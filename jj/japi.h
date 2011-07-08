//    Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
//    All rights reserved.

#pragma once

#include <v8.h>

namespace japi
{

//Native
bool RegisterModule(v8::Handle<v8::ObjectTemplate>& target);

//JS API
v8::Handle<v8::Value> JS_Alert(const v8::Arguments& args);

} //namespace japi

