#pragma once
#include <node.h>

namespace demo{

	using namespace v8;

	Local<String> initial_val;

	void MyFunction(const FunctionCallbackInfo<Value>& args);

	void CreateFunction(const FunctionCallbackInfo<Value>& args);

	void Init(Local<Object> exports, Local<Object> module);
}