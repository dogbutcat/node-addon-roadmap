#include <node.h>
#include "main.h"

namespace func_arg {


	void Add(const FunctionCallbackInfo<Value>& args) {
		Isolate* isolate = args.GetIsolate();

		// check the number of arguments passed
		if (args.Length() < 2) {
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Wrong number of argumennts")
			));
			return;
		}

		// check argument types
		if(!args[0]->IsNumber()||!args[1]->IsNumber()){
			isolate->ThrowException(Exception::TypeError(
				String::NewFromUtf8(isolate, "Wrong argument type")
			));
			return;
		}

		double value = args[0]->NumberValue() + args[1]->NumberValue();
		Local<Number> num = Number::New(isolate, value);
		args.GetReturnValue().Set(num);
	}

	void Init(Local<Object> exports) {
		NODE_SET_METHOD(exports, "add", Add);
	}

	NODE_MODULE(func_with_arg, Init)
}