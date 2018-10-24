#include "main.h"
#include <node.h>

namespace demo {
	using v8::FunctionCallbackInfo;
	using v8::Isolate;
	using v8::Local;
	using v8::Object;
	using v8::String;
	using v8::Value;

	void Method(const FunctionCallbackInfo<Value>& args) {
		Isolate* isolate = args.GetIsolate();
		args.GetReturnValue().Set(String::NewFromUtf8(isolate, "world"));
	}

	void Initialize(Local<Object> exports) {
		NODE_SET_METHOD(exports, "hello", Method);
	}

	NODE_MODULE(first_addon, Initialize) // no semi-colon & need to be same name with Target Name in project configuration
} // namespace demo