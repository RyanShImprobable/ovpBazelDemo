// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: agones/allocation.proto

#include "agones/allocation.pb.h"
#include "agones/allocation.grpc.pb.h"

#include <functional>
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
namespace allocation {

static const char* AllocationService_method_names[] = {
  "/allocation.AllocationService/Allocate",
};

std::unique_ptr< AllocationService::Stub> AllocationService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< AllocationService::Stub> stub(new AllocationService::Stub(channel));
  return stub;
}

AllocationService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel)
  : channel_(channel), rpcmethod_Allocate_(AllocationService_method_names[0], ::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status AllocationService::Stub::Allocate(::grpc::ClientContext* context, const ::allocation::AllocationRequest& request, ::allocation::AllocationResponse* response) {
  return ::grpc::internal::BlockingUnaryCall(channel_.get(), rpcmethod_Allocate_, context, request, response);
}

void AllocationService::Stub::experimental_async::Allocate(::grpc::ClientContext* context, const ::allocation::AllocationRequest* request, ::allocation::AllocationResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall(stub_->channel_.get(), stub_->rpcmethod_Allocate_, context, request, response, std::move(f));
}

void AllocationService::Stub::experimental_async::Allocate(::grpc::ClientContext* context, const ::allocation::AllocationRequest* request, ::allocation::AllocationResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create(stub_->channel_.get(), stub_->rpcmethod_Allocate_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::allocation::AllocationResponse>* AllocationService::Stub::PrepareAsyncAllocateRaw(::grpc::ClientContext* context, const ::allocation::AllocationRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderFactory< ::allocation::AllocationResponse>::Create(channel_.get(), cq, rpcmethod_Allocate_, context, request, false);
}

::grpc::ClientAsyncResponseReader< ::allocation::AllocationResponse>* AllocationService::Stub::AsyncAllocateRaw(::grpc::ClientContext* context, const ::allocation::AllocationRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncAllocateRaw(context, request, cq);
  result->StartCall();
  return result;
}

AllocationService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      AllocationService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< AllocationService::Service, ::allocation::AllocationRequest, ::allocation::AllocationResponse>(
          [](AllocationService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::allocation::AllocationRequest* req,
             ::allocation::AllocationResponse* resp) {
               return service->Allocate(ctx, req, resp);
             }, this)));
}

AllocationService::Service::~Service() {
}

::grpc::Status AllocationService::Service::Allocate(::grpc::ServerContext* context, const ::allocation::AllocationRequest* request, ::allocation::AllocationResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace allocation

