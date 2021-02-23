// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: runtime/healthcheck.proto
// Original file comments:
// Copyright (c) 2015 Improbable Worlds Ltd. All Rights Reserved.
#ifndef GRPC_runtime_2fhealthcheck_2eproto__INCLUDED
#define GRPC_runtime_2fhealthcheck_2eproto__INCLUDED

#include "runtime/healthcheck.pb.h"

#include <functional>
#include <grpc/impl/codegen/port_platform.h>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace improbable {
namespace platform {
namespace runtime {

// HealthCheckService obtains the health status of a given node
class HealthCheckService final {
 public:
  static constexpr char const* service_full_name() {
    return "improbable.platform.runtime.HealthCheckService";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // HealthCheck
    virtual ::grpc::Status HealthCheck(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::improbable::platform::runtime::HealthCheckResponse* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::improbable::platform::runtime::HealthCheckResponse>> AsyncHealthCheck(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::improbable::platform::runtime::HealthCheckResponse>>(AsyncHealthCheckRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::improbable::platform::runtime::HealthCheckResponse>> PrepareAsyncHealthCheck(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::improbable::platform::runtime::HealthCheckResponse>>(PrepareAsyncHealthCheckRaw(context, request, cq));
    }
    class experimental_async_interface {
     public:
      virtual ~experimental_async_interface() {}
      // HealthCheck
      virtual void HealthCheck(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::improbable::platform::runtime::HealthCheckResponse* response, std::function<void(::grpc::Status)>) = 0;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      virtual void HealthCheck(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::improbable::platform::runtime::HealthCheckResponse* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      #else
      virtual void HealthCheck(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::improbable::platform::runtime::HealthCheckResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) = 0;
      #endif
    };
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    typedef class experimental_async_interface async_interface;
    #endif
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    async_interface* async() { return experimental_async(); }
    #endif
    virtual class experimental_async_interface* experimental_async() { return nullptr; }
  private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::improbable::platform::runtime::HealthCheckResponse>* AsyncHealthCheckRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::improbable::platform::runtime::HealthCheckResponse>* PrepareAsyncHealthCheckRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel);
    ::grpc::Status HealthCheck(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::improbable::platform::runtime::HealthCheckResponse* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::improbable::platform::runtime::HealthCheckResponse>> AsyncHealthCheck(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::improbable::platform::runtime::HealthCheckResponse>>(AsyncHealthCheckRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::improbable::platform::runtime::HealthCheckResponse>> PrepareAsyncHealthCheck(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::improbable::platform::runtime::HealthCheckResponse>>(PrepareAsyncHealthCheckRaw(context, request, cq));
    }
    class experimental_async final :
      public StubInterface::experimental_async_interface {
     public:
      void HealthCheck(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::improbable::platform::runtime::HealthCheckResponse* response, std::function<void(::grpc::Status)>) override;
      #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      void HealthCheck(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::improbable::platform::runtime::HealthCheckResponse* response, ::grpc::ClientUnaryReactor* reactor) override;
      #else
      void HealthCheck(::grpc::ClientContext* context, const ::google::protobuf::Empty* request, ::improbable::platform::runtime::HealthCheckResponse* response, ::grpc::experimental::ClientUnaryReactor* reactor) override;
      #endif
     private:
      friend class Stub;
      explicit experimental_async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class experimental_async_interface* experimental_async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class experimental_async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::improbable::platform::runtime::HealthCheckResponse>* AsyncHealthCheckRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::improbable::platform::runtime::HealthCheckResponse>* PrepareAsyncHealthCheckRaw(::grpc::ClientContext* context, const ::google::protobuf::Empty& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_HealthCheck_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // HealthCheck
    virtual ::grpc::Status HealthCheck(::grpc::ServerContext* context, const ::google::protobuf::Empty* request, ::improbable::platform::runtime::HealthCheckResponse* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_HealthCheck : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_HealthCheck() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_HealthCheck() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status HealthCheck(::grpc::ServerContext* /*context*/, const ::google::protobuf::Empty* /*request*/, ::improbable::platform::runtime::HealthCheckResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestHealthCheck(::grpc::ServerContext* context, ::google::protobuf::Empty* request, ::grpc::ServerAsyncResponseWriter< ::improbable::platform::runtime::HealthCheckResponse>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_HealthCheck<Service > AsyncService;
  template <class BaseClass>
  class ExperimentalWithCallbackMethod_HealthCheck : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithCallbackMethod_HealthCheck() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::google::protobuf::Empty, ::improbable::platform::runtime::HealthCheckResponse>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::google::protobuf::Empty* request, ::improbable::platform::runtime::HealthCheckResponse* response) { return this->HealthCheck(context, request, response); }));}
    void SetMessageAllocatorFor_HealthCheck(
        ::grpc::experimental::MessageAllocator< ::google::protobuf::Empty, ::improbable::platform::runtime::HealthCheckResponse>* allocator) {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
    #else
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::experimental().GetHandler(0);
    #endif
      static_cast<::grpc::internal::CallbackUnaryHandler< ::google::protobuf::Empty, ::improbable::platform::runtime::HealthCheckResponse>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~ExperimentalWithCallbackMethod_HealthCheck() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status HealthCheck(::grpc::ServerContext* /*context*/, const ::google::protobuf::Empty* /*request*/, ::improbable::platform::runtime::HealthCheckResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* HealthCheck(
      ::grpc::CallbackServerContext* /*context*/, const ::google::protobuf::Empty* /*request*/, ::improbable::platform::runtime::HealthCheckResponse* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* HealthCheck(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::google::protobuf::Empty* /*request*/, ::improbable::platform::runtime::HealthCheckResponse* /*response*/)
    #endif
      { return nullptr; }
  };
  #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
  typedef ExperimentalWithCallbackMethod_HealthCheck<Service > CallbackService;
  #endif

  typedef ExperimentalWithCallbackMethod_HealthCheck<Service > ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_HealthCheck : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_HealthCheck() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_HealthCheck() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status HealthCheck(::grpc::ServerContext* /*context*/, const ::google::protobuf::Empty* /*request*/, ::improbable::platform::runtime::HealthCheckResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_HealthCheck : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_HealthCheck() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_HealthCheck() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status HealthCheck(::grpc::ServerContext* /*context*/, const ::google::protobuf::Empty* /*request*/, ::improbable::platform::runtime::HealthCheckResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestHealthCheck(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class ExperimentalWithRawCallbackMethod_HealthCheck : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    ExperimentalWithRawCallbackMethod_HealthCheck() {
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
      ::grpc::Service::
    #else
      ::grpc::Service::experimental().
    #endif
        MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
                   ::grpc::CallbackServerContext*
    #else
                   ::grpc::experimental::CallbackServerContext*
    #endif
                     context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->HealthCheck(context, request, response); }));
    }
    ~ExperimentalWithRawCallbackMethod_HealthCheck() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status HealthCheck(::grpc::ServerContext* /*context*/, const ::google::protobuf::Empty* /*request*/, ::improbable::platform::runtime::HealthCheckResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    #ifdef GRPC_CALLBACK_API_NONEXPERIMENTAL
    virtual ::grpc::ServerUnaryReactor* HealthCheck(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #else
    virtual ::grpc::experimental::ServerUnaryReactor* HealthCheck(
      ::grpc::experimental::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)
    #endif
      { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_HealthCheck : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_HealthCheck() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::google::protobuf::Empty, ::improbable::platform::runtime::HealthCheckResponse>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::google::protobuf::Empty, ::improbable::platform::runtime::HealthCheckResponse>* streamer) {
                       return this->StreamedHealthCheck(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_HealthCheck() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status HealthCheck(::grpc::ServerContext* /*context*/, const ::google::protobuf::Empty* /*request*/, ::improbable::platform::runtime::HealthCheckResponse* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedHealthCheck(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::google::protobuf::Empty,::improbable::platform::runtime::HealthCheckResponse>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_HealthCheck<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_HealthCheck<Service > StreamedService;
};

}  // namespace runtime
}  // namespace platform
}  // namespace improbable


#endif  // GRPC_runtime_2fhealthcheck_2eproto__INCLUDED
