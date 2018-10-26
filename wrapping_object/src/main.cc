#include "main.h"
#include "myobject.h"

namespace demo {
	using namespace v8;

	void InitAll(Local<Object> exports)
	{
		MyObject::Init(exports);
	}

	NODE_MODULE(wrapping_object, InitAll)
}
