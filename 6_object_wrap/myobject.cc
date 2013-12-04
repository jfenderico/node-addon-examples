#include <node.h>
#include "nan.h"
#include "myobject.h"

using namespace v8;

MyObject::MyObject() {};
MyObject::~MyObject() {};

void MyObject::Init(Handle<Object> target) {
  // Prepare constructor template
  Local<FunctionTemplate> tpl = FunctionTemplate::New(New);
  tpl->SetClassName(String::NewSymbol("MyObject"));
  tpl->InstanceTemplate()->SetInternalFieldCount(1);
  // Prototype
  tpl->PrototypeTemplate()->Set(String::NewSymbol("plusOne"),
      FunctionTemplate::New(PlusOne)->GetFunction());

  NanCallback *constructor = new NanCallback(tpl->GetFunction());
  target->Set(String::NewSymbol("MyObject"), constructor->GetFunction());
}

NAN_METHOD(MyObject::New) {
  NanScope();

  MyObject* obj = new MyObject();
  obj->counter_ = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
  obj->Wrap(args.This());

  NanReturnValue(args.This());
}

NAN_METHOD(MyObject::PlusOne) {
  NanScope();

  MyObject* obj = ObjectWrap::Unwrap<MyObject>(args.This());
  obj->counter_ += 1;

  NanReturnValue(Number::New(obj->counter_));
}
