//    Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
//    All rights reserved.

#include <windows.h>

#include "japi.h"


v8::Handle<v8::Value> JS_Alert(const v8::Arguments& args)
{
    v8::HandleScope handle_scope;
    v8::String::Utf8Value message(args.Length() ? args[0] : v8::String::New("undefined"));
    ::MessageBoxA(0, *message, "JavaScript", 0);
    return v8::Undefined();
}

