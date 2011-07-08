//    Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
//    All rights reserved.

#pragma once

#include <string>

#include <v8.h>


//Native
bool RunJsFile(const std::string& path);
bool RunJsString(const std::string& body);

bool HandleException(const v8::TryCatch& trycatch);
const std::string MessageOfException(const v8::TryCatch& trycatch);

