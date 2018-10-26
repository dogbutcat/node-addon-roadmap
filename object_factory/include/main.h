#pragma once
#include <node.h>

namespace demo {

	using namespace v8;

	void CreateObject(const FunctionCallbackInfo<Value>& args);

	void Init(Local<Object> exports, Local<Object> module);
}