#include "myobject.h"

namespace demo {

	using namespace v8;

	Persistent<Function> MyObject::constructor;

	MyObject::MyObject(double value) :value_(value) {

	}

	void MyObject::Init(v8::Local<v8::Object> exports)
	{
		Isolate* isolate = exports->GetIsolate();
		
		// prepare constructor template
		Local<FunctionTemplate> tpl = FunctionTemplate::New(isolate, New);
		tpl->SetClassName(String::NewFromUtf8(isolate, "MyObject"));
		tpl->InstanceTemplate()->SetInternalFieldCount(1);

		// Prototype
		NODE_SET_PROTOTYPE_METHOD(tpl, "plusOne", PlusOne);

		constructor.Reset(isolate, tpl->GetFunction());
		exports->Set(String::NewFromUtf8(isolate, "MyObject"), tpl->GetFunction());
	}

	MyObject::~MyObject()
	{
	}

	void MyObject::New(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		Isolate* isolate = args.GetIsolate();
		if (args.IsConstructCall()) {
			double value = args[0]->IsUndefined() ? 0 : args[0]->NumberValue();
			MyObject* obj = new MyObject(value);
			obj->Wrap(args.This());
			args.GetReturnValue().Set(args.This());
		}
		else {
			const int argc = 1;
			Local<Value> argv[argc] = { args[0] };
			Local<Context> context = isolate->GetCurrentContext();
			Local<Function> cons = Local<Function>::New(isolate, constructor);
			Local<Object> result = cons->NewInstance(context, argc, argv).ToLocalChecked();
			args.GetReturnValue().Set(result);
		}
	}

	void MyObject::PlusOne(const v8::FunctionCallbackInfo<v8::Value>& args)
	{
		Isolate* isolate = args.GetIsolate();

		MyObject* obj = ObjectWrap::Unwrap<MyObject>(args.Holder());
		obj->value_ += 1;

		args.GetReturnValue().Set(Number::New(isolate, obj->value_));
	}

} // namespace demo