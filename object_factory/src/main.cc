#include "main.h"


namespace demo {
	void CreateObject(const FunctionCallbackInfo<Value>& args)
	{
		Isolate* isolate = args.GetIsolate();
		Local<Object> obj = Object::New(isolate);
		obj->Set(String::NewFromUtf8(isolate, "msg"), args[0]->ToString());

		args.GetReturnValue().Set(obj);
	}
	void Init(Local<Object> exports, Local<Object> module)
	{
		NODE_SET_METHOD(module, "exports", CreateObject);
	}

	NODE_MODULE(object_factory, Init)
}
