#pragma once
#include <node.h>

namespace func_arg {
	using v8::Exception;
	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::Number;
	using v8::Object;
	using v8::String;
	using v8::Value;

	void Add(const FunctionCallbackInfo<Value>& args);

	void Init(Local<Object> exports);

}