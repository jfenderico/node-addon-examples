#include <node.h>
#include "nan.h"

using namespace v8;

NAN_METHOD(MyFunction) {
  NanScope();
  NanReturnValue(String::New("hello world"));
}

NAN_METHOD(CreateFunction) {
  NanScope();

  Local<FunctionTemplate> tpl = FunctionTemplate::New(MyFunction);
  Local<Function> fn = tpl->GetFunction();
  fn->SetName(String::NewSymbol("theFunction")); // omit this to make it anonymous

  NanReturnValue(fn);
}

void Init(Handle<Object> exports, Handle<Object> module) {
  module->Set(String::NewSymbol("exports"),
      FunctionTemplate::New(CreateFunction)->GetFunction());
}

NODE_MODULE(addon, Init)
