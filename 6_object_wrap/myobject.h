#ifndef MYOBJECT_H
#define MYOBJECT_H

#include <node.h>
#include "nan.h"

class MyObject : public node::ObjectWrap {
 public:
  static void Init(v8::Handle<v8::Object> target);

 private:
  MyObject();
  ~MyObject();

  static NAN_METHOD(New);
  static NAN_METHOD(PlusOne);
  double counter_;
};

#endif
