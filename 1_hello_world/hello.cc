#include <node.h>
#include <v8.h>
#include "nan.h"
#include "hello.h"

using namespace v8;

NAN_METHOD(Hello) {
  NanScope();

  NanReturnValue(String::New("world"));
}

void init(Handle<Object> exports) {
  exports->Set(String::NewSymbol("hello"),
      FunctionTemplate::New(Hello)->GetFunction());
}

NODE_MODULE(hello, init)
