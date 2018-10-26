#include "main.h"

namespace demo{
	void RunCallback(const FunctionCallbackInfo<Value>& args)
	{
		Isolate* isolate = args.GetIsolate();
		Local<Function> cb = Local<Function>::Cast(args[0]);
		const unsigned argc = 1;
		Local<Value> argv[argc] = { String::NewFromUtf8(isolate,"hello world") };
		if (args.Length() > 1) {
			Local<String> val = args[1]->ToString();
			args.GetReturnValue().Set(val);
		}
		cb->Call(Null(isolate), argc, argv);
	}

	// uses a two-argument form of Init() that receives the full module object as the second argument.
	// This allows the Addon to completely overwrite exports with a single function instead of adding the function as a property of exports.
	void Init(Local<Object> exports, Local<Object> module)
	{
		NODE_SET_METHOD(module, "exports", RunCallback);
	}

	NODE_MODULE(callback, Init)
}