
#include <grpcpp/grpcpp.h>
#include "agonesshim/gameserver.grpc.pb.h"
#include "agones/allocation.grpc.pb.h"
#include "platform/deployments.grpc.pb.h"
#include "runtime/receptionist.pb.h"
//#include <grpcpp/impl/codegen/async_unary_call_impl.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>

#include <nlohmann/json.hpp>
#include <jwt-cpp/jwt.h>
#include <iostream>
#include <fstream>
#include <string>
#include <chrono>
#include <thread>
#include <future>
class OvpClient {
public:
	explicit OvpClient(std::shared_ptr<grpc::Channel> channel)
		: gsStub_(improbable::svp::agonesshim::GameserverService::NewStub(channel)),
		agonesStub_(allocation::AllocationService::NewStub(channel)) {}

	void deleteGameRoom(std::string gsName) {
		auto delete_req = improbable::svp::agonesshim::DeleteGameserverRequest();
		std::string ns("game-umi");
		delete_req.set_namespace_(ns);
		delete_req.set_name(gsName);
		AsyncClientCall<improbable::svp::agonesshim::DeleteGameserverResponse>* call = new AsyncClientCall<improbable::svp::agonesshim::DeleteGameserverResponse>;
		call->response_reader = gsStub_->AsyncDeleteGameserver(&call->context, delete_req, &cq_);
		call->response_reader->Finish(&call->deleteResponse, &call->status, (void*)call);
	}

	void allocateGameRoom() {
		auto cd_req = allocation::AllocationRequest();
		std::string ns("game-umi");
		cd_req.set_namespace_(ns);
		allocation::LabelSelector* lb = cd_req.mutable_requiredgameserverselector();
		(*lb->mutable_matchlabels())["agones.dev/fleet"] = "ryan-test-by-zhou";
	
		AsyncClientCall<::allocation::AllocationResponse>* call = new AsyncClientCall<::allocation::AllocationResponse>;
		call->response_reader = agonesStub_->AsyncAllocate(&call->context, cd_req, &cq_);
		call->response_reader->Finish(&call->allocateResponse, &call->status, (void*)call);
	}

	void listDepoyment() {
		auto cd_req = improbable::svp::agonesshim::ListGameserversRequest();
		
		AsyncClientCall<::improbable::svp::agonesshim::ListGameserversResponse>* call = new AsyncClientCall<::improbable::svp::agonesshim::ListGameserversResponse>;
		call->response_reader = gsStub_->AsyncListGameservers(&call->context,cd_req, &cq_);
		call->response_reader->Finish(&call->listResponse, &call->status, (void*)call);
	}

	void syncAllocateAndLogin(std::string fleetName,  std::string locatorKey, std::string agonescert, std::string agoneskey) {
		grpc::ClientContext context;
		
		// Allocate a room
		auto cd_req = allocation::AllocationRequest();
		std::string ns("game-umi");
		cd_req.set_namespace_(ns);
		allocation::LabelSelector* lb = cd_req.mutable_requiredgameserverselector();

		//Set the fleetName
		(*lb->mutable_matchlabels())["agones.dev/fleet"] = fleetName;

		auto allocateResponse = allocation::AllocationResponse();
		agonesStub_->Allocate(&context, cd_req, &allocateResponse);
		

		std::string locatorIP = allocateResponse.address();
		std::replace(locatorIP.begin(), locatorIP.end(), '.', '-');
		allocateResponse.ports_size();
		int portValue = 0;
		for (int i = 0; i < allocateResponse.ports_size(); i++) {
			allocation::AllocationResponse_GameServerStatusPort portRef = allocateResponse.ports(i);
			if (portRef.name() == "receptionist") {
				portValue = portRef.port();
				break;
			}
		}
		
		// Create URL 
		std::string locatorUrl = locatorIP + "-" + std::to_string(portValue) + ".locator-proxy.game-tct-ap-beijing-3-1.ovp-tst.spatialoschina.net:443";
		std::string gameserverName = allocateResponse.gameservername();
		
		
		//std::string locatorUrl = "81-70-198-252-7052.locator-proxy.game-tct-ap-beijing-3-1.ovp-tst.spatialoschina.net:443";
		//std::string gameserverName = "ryan-login-8kvtm-kgskc";

		// Try Login into locator 
		auto credentials = grpc::SslCredentialsOptions();
		credentials.pem_private_key = agoneskey;
		credentials.pem_cert_chain = agonescert;

		// logoin will use the grpc default root.pem
		//credentials.pem_root_certs = agonescacert;

		auto channel = grpc::CreateChannel(locatorUrl, grpc::SslCredentials(credentials));
		std::unique_ptr<improbable::platform::locator::LocateServiceV2::Stub> locatorStub_;
		locatorStub_ = improbable::platform::locator::LocateServiceV2::NewStub(channel);
		auto loginResponse = improbable::platform::locator::LoginResponse();
		improbable::platform::locator::LoginRequest loginRequest = getLoginRequest(gameserverName, locatorKey);
		grpc::ClientContext contextLogin;
		locatorStub_->Login(&contextLogin, loginRequest, &loginResponse);

		std::cout << "LocatorUrl: " << locatorUrl << std::endl;
		std::cout << "PlayerIdentityToken: " << loginRequest.player_identity_token() << std::endl;

		if (loginResponse.has_failure()) {
			std::cout << "Login failed" << std::endl;
		} else {
			std::cout << "Login success!" << std::endl;
		}


	}

	improbable::platform::locator::LoginRequest getLoginRequest(std::string gsName, std::string locatorKey) {
		auto loginReq = improbable::platform::locator::LoginRequest();
		std::string wtype("UnrealClient");
		
		
		improbable::platform::runtime::ProtocolCapabilitiesV2* cv2 = new improbable::platform::runtime::ProtocolCapabilitiesV2();
		improbable::platform::runtime::ProtocolCapabilities capabilities;
		capabilities.set_allocated_capabilities_v2(cv2);
		std::string capabilityStr("");
		capabilities.SerializeToString(&capabilityStr);

		auto pid = jwt::create()
			.set_expires_at(std::chrono::system_clock::now() + std::chrono::seconds{60000})
			.set_audience(gsName)
			.set_payload_claim("manifest", jwt::claim(std::string{ "2" }))
			.sign(jwt::algorithm::ps256("", locatorKey, "", ""));

		loginReq.set_player_identity_token(pid);
		loginReq.set_protocol_capabilities(capabilityStr);
		loginReq.set_worker_type(wtype);
		return loginReq;
	}


	// Out of the passed in Channel comes the stub, stored here, our view of the
	// server's exposed services.
	std::unique_ptr<improbable::svp::agonesshim::GameserverService::Stub> gsStub_;
	std::unique_ptr<allocation::AllocationService::Stub> agonesStub_;
	//std::unique_ptr<improbable::platform::locator::LocateServiceV2::Stub> locatorStub_;

	struct AsyncResult {
		std::string Message;
	};

	// Loop while listening for completed responses.
   // Prints out the response from the server.
	template <class R>
	AsyncResult AsyncCompleteRpc() {
		void* got_tag;
		bool ok = false;
		AsyncResult result;
		// Block until the next result is available in the completion queue "cq".
		while (cq_.Next(&got_tag, &ok)) {
			// The tag in this example is the memory location of the call object
			AsyncClientCall<R>* call = static_cast<AsyncClientCall<R>*>(got_tag);
			// Verify that the request was completed successfully. Note that "ok"
			// corresponds solely to the request for updates introduced by Finish().
			GPR_ASSERT(ok);

			if (call->status.ok()) {

				
				//Allocate
				/*
				result.Message = call->allocateResponse.gameservername();
				std::cout << "GameServerName: " << call->reply.gameservername() << std::endl;
				*/
				
				
				//List
				result.Message = std::to_string(call->listResponse.gameserverlist_size());
				std::cout << "DeploymentNumber: " << call->listResponse.gameserverlist_size() << std::endl;
				for (int i = 0; i < call->listResponse.gameserverlist_size(); i++) {
					::improbable::svp::agonesshim::GameserverInfo gamesrvr = call->listResponse.gameserverlist(i);
					std::string* name = gamesrvr.mutable_gameservername();
					std::cout << "DeploymentNumber: " << *name << std::endl;
				}
				
				//Delete
				//No Reply
				std::cout << "RPC succeeded!" << std::endl;
			} else {
				result.Message = call->status.error_message();
				std::cout << "RPC failed" << std::endl;
			}
			// Once we're complete, deallocate the call object.
			delete call;
			return result;

		}

		return result;
	}

	template <class R>
	struct AsyncClientCall {
		improbable::svp::agonesshim::ListGameserversResponse listResponse;
		allocation::AllocationResponse allocateResponse;
		improbable::svp::agonesshim::DeleteGameserverResponse deleteResponse;
		grpc::ClientContext context;
		grpc::Status status;
		std::unique_ptr<grpc::ClientAsyncResponseReader<R>> response_reader;
	};

	grpc::CompletionQueue cq_;
};

std::string readFileToString(const std::string filePath)
{
	std::ifstream ifs(filePath);
	std::string content((std::istreambuf_iterator<char>(ifs)),
		(std::istreambuf_iterator<char>()));
	return content;
}


int main(int argc, char** argv) {
	std::string agonescacert = readFileToString("C:/Umi_ovp/cpp_sample/agonescacert");
	std::string agonescert = readFileToString("C:/Umi_ovp/cpp_sample/agonescert");
	std::string agoneskey = readFileToString("C:/Umi_ovp/cpp_sample/agoneskey");
	grpc::SslCredentialsOptions sslCredentials;
	sslCredentials.pem_root_certs = agonescacert;
	sslCredentials.pem_cert_chain = agonescert;
	sslCredentials.pem_private_key = agoneskey;
	auto channel_creds = grpc::SslCredentials(sslCredentials);

	//For umi local environment, please use "agones-shim.ovp-local.ovp.spatialoschina.net"
	std::string locatorUrl = "agones-shim.game-tct-ap-beijing-3-1.ovp-tst.spatialoschina.net:15443";
	auto channel = grpc::CreateChannel(locatorUrl, channel_creds);

	OvpClient greeter(channel);
	
	

	// sync allocate and login 
	std::string locatorKey = readFileToString("C:/Umi_ovp/cpp_sample/locatorsignkey");
	greeter.syncAllocateAndLogin("ryan-login", locatorKey, agonescert, agoneskey);


	/*
	//List
	greeter.listDepoyment();
	auto listDeploymentFuture = std::async(&OvpClient::AsyncCompleteRpc<::improbable::svp::agonesshim::ListGameserversResponse>, &greeter);
	OvpClient::AsyncResult simple = listDeploymentFuture.get();
	std::cout << "ListCount is " << simple.Message << std::endl;
	*/


	/*
	//Allocate
	greeter.allocateGameRoom();
	auto allocationFuture = std::async(&OvpClient::AsyncCompleteRpc<::allocation::AllocationResponse>, &greeter);
	OvpClient::AsyncResult allocation = allocationFuture.get();
	std::cout << "Allocation message is " << allocation.Message << std::endl;
	*/


	//Delete
	/*
	std::string gsName("test234-7gtwg-t2s5k");
	greeter.deleteGameRoom(gsName);
	auto deleteFuture = std::async(&OvpClient::AsyncCompleteRpc<::improbable::svp::agonesshim::DeleteGameserverResponse>, &greeter);
	OvpClient::AsyncResult deleteResult = deleteFuture.get();
	*/
	
	return 0;
}
