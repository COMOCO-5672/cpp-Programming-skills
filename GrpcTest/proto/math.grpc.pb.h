// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: math.proto
#ifndef GRPC_math_2eproto__INCLUDED
#define GRPC_math_2eproto__INCLUDED

#include "math.pb.h"

#include <functional>
#include <grpcpp/generic/async_generic_service.h>
#include <grpcpp/support/async_stream.h>
#include <grpcpp/support/async_unary_call.h>
#include <grpcpp/support/client_callback.h>
#include <grpcpp/client_context.h>
#include <grpcpp/completion_queue.h>
#include <grpcpp/support/message_allocator.h>
#include <grpcpp/support/method_handler.h>
#include <grpcpp/impl/proto_utils.h>
#include <grpcpp/impl/rpc_method.h>
#include <grpcpp/support/server_callback.h>
#include <grpcpp/impl/server_callback_handlers.h>
#include <grpcpp/server_context.h>
#include <grpcpp/impl/service_type.h>
#include <grpcpp/support/status.h>
#include <grpcpp/support/stub_options.h>
#include <grpcpp/support/sync_stream.h>

namespace mathtest {

// Defines the service
class MathTest final {
 public:
  static constexpr char const* service_full_name() {
    return "mathtest.MathTest";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // Function invoked to send the request
    virtual ::grpc::Status sendRequest(::grpc::ClientContext* context, const ::mathtest::MathRequest& request, ::mathtest::MathReply* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::mathtest::MathReply>> AsyncsendRequest(::grpc::ClientContext* context, const ::mathtest::MathRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::mathtest::MathReply>>(AsyncsendRequestRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::mathtest::MathReply>> PrepareAsyncsendRequest(::grpc::ClientContext* context, const ::mathtest::MathRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::mathtest::MathReply>>(PrepareAsyncsendRequestRaw(context, request, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      // Function invoked to send the request
      virtual void sendRequest(::grpc::ClientContext* context, const ::mathtest::MathRequest* request, ::mathtest::MathReply* response, std::function<void(::grpc::Status)>) = 0;
      virtual void sendRequest(::grpc::ClientContext* context, const ::mathtest::MathRequest* request, ::mathtest::MathReply* response, ::grpc::ClientUnaryReactor* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::mathtest::MathReply>* AsyncsendRequestRaw(::grpc::ClientContext* context, const ::mathtest::MathRequest& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::mathtest::MathReply>* PrepareAsyncsendRequestRaw(::grpc::ClientContext* context, const ::mathtest::MathRequest& request, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status sendRequest(::grpc::ClientContext* context, const ::mathtest::MathRequest& request, ::mathtest::MathReply* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::mathtest::MathReply>> AsyncsendRequest(::grpc::ClientContext* context, const ::mathtest::MathRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::mathtest::MathReply>>(AsyncsendRequestRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::mathtest::MathReply>> PrepareAsyncsendRequest(::grpc::ClientContext* context, const ::mathtest::MathRequest& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::mathtest::MathReply>>(PrepareAsyncsendRequestRaw(context, request, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void sendRequest(::grpc::ClientContext* context, const ::mathtest::MathRequest* request, ::mathtest::MathReply* response, std::function<void(::grpc::Status)>) override;
      void sendRequest(::grpc::ClientContext* context, const ::mathtest::MathRequest* request, ::mathtest::MathReply* response, ::grpc::ClientUnaryReactor* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::mathtest::MathReply>* AsyncsendRequestRaw(::grpc::ClientContext* context, const ::mathtest::MathRequest& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::mathtest::MathReply>* PrepareAsyncsendRequestRaw(::grpc::ClientContext* context, const ::mathtest::MathRequest& request, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_sendRequest_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // Function invoked to send the request
    virtual ::grpc::Status sendRequest(::grpc::ServerContext* context, const ::mathtest::MathRequest* request, ::mathtest::MathReply* response);
  };
  template <class BaseClass>
  class WithAsyncMethod_sendRequest : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_sendRequest() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_sendRequest() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status sendRequest(::grpc::ServerContext* /*context*/, const ::mathtest::MathRequest* /*request*/, ::mathtest::MathReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestsendRequest(::grpc::ServerContext* context, ::mathtest::MathRequest* request, ::grpc::ServerAsyncResponseWriter< ::mathtest::MathReply>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_sendRequest<Service > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_sendRequest : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_sendRequest() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::mathtest::MathRequest, ::mathtest::MathReply>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::mathtest::MathRequest* request, ::mathtest::MathReply* response) { return this->sendRequest(context, request, response); }));}
    void SetMessageAllocatorFor_sendRequest(
        ::grpc::MessageAllocator< ::mathtest::MathRequest, ::mathtest::MathReply>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::mathtest::MathRequest, ::mathtest::MathReply>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_sendRequest() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status sendRequest(::grpc::ServerContext* /*context*/, const ::mathtest::MathRequest* /*request*/, ::mathtest::MathReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* sendRequest(
      ::grpc::CallbackServerContext* /*context*/, const ::mathtest::MathRequest* /*request*/, ::mathtest::MathReply* /*response*/)  { return nullptr; }
  };
  typedef WithCallbackMethod_sendRequest<Service > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_sendRequest : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_sendRequest() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_sendRequest() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status sendRequest(::grpc::ServerContext* /*context*/, const ::mathtest::MathRequest* /*request*/, ::mathtest::MathReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_sendRequest : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_sendRequest() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_sendRequest() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status sendRequest(::grpc::ServerContext* /*context*/, const ::mathtest::MathRequest* /*request*/, ::mathtest::MathReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestsendRequest(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_sendRequest : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_sendRequest() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->sendRequest(context, request, response); }));
    }
    ~WithRawCallbackMethod_sendRequest() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status sendRequest(::grpc::ServerContext* /*context*/, const ::mathtest::MathRequest* /*request*/, ::mathtest::MathReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* sendRequest(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_sendRequest : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_sendRequest() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::mathtest::MathRequest, ::mathtest::MathReply>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::mathtest::MathRequest, ::mathtest::MathReply>* streamer) {
                       return this->StreamedsendRequest(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_sendRequest() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status sendRequest(::grpc::ServerContext* /*context*/, const ::mathtest::MathRequest* /*request*/, ::mathtest::MathReply* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedsendRequest(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::mathtest::MathRequest,::mathtest::MathReply>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_sendRequest<Service > StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef WithStreamedUnaryMethod_sendRequest<Service > StreamedService;
};

}  // namespace mathtest


#endif  // GRPC_math_2eproto__INCLUDED
