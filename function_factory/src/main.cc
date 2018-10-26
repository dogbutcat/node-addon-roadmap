#include "main.h"


namespace demo {
	void MyFunction(const FunctionCallbackInfo<Value>& args)
	{
		Isolate* isolate = args.GetIsolate();
		// Local<String> str_arg = args[0]->ToString();
		// args.GetReturnValue().Set(str_arg);
		args.GetReturnValue().Set(initial_val);
	}

	void CreateFunction(const FunctionCallbackInfo<Value>& args)
	{
		Isolate* isolate = args.GetIsolate();
		initial_val = args[0]->ToString();

		Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, MyFunction);
		Local<Function> fn = tpl->GetFunction();

		fn->SetName(String::NewFromUtf8(isolate, "theFunction"));

		args.GetReturnValue().Set(fn);
	}


	void Init(Local<Object> exports, Local<Object> module)
	{
		NODE_SET_METHOD(module, "exports", CreateFunction);
	}

	NODE_MODULE(function_factory, Init)
}
