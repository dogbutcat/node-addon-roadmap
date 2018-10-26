#pragma once
#include <node.h>

namespace demo {
	using v8::Function;
	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::Object;
	using v8::String;
	using v8::Value;

	void RunCallback(const FunctionCallbackInfo<Value>& args);
	
	void Init(Local<Object> exports, Local<Object> module);
}