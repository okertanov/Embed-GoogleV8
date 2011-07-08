//    Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
//    All rights reserved.

#include <new>
#include <string>
#include <cassert>
#include <cstdlib>
#include <iomanip>
#include <ostream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <functional>

#include "jj.h"
#include "japi.h"


bool HandleException(const v8::TryCatch& trycatch)
{
    bool ret = false;

    if ( (ret = trycatch.HasCaught()) )
    {
    }

    return ret;
}

const std::string MessageOfException(const v8::TryCatch& trycatch)
{
    std::string message = "";

    if ( trycatch.HasCaught() )
    {
        v8::Handle<v8::Value> except = trycatch.Exception();
        v8::String::Utf8Value exception_str(except);
        if (*exception_str)
            message = *exception_str;
    }

    return message;
}

bool RunJsString(const std::string& body)
{
    bool rc = true;

    v8::HandleScope handle_scope;
    v8::Handle<v8::ObjectTemplate> global = v8::ObjectTemplate::New();
    global->Set(v8::String::New("Alert"), v8::FunctionTemplate::New(JS_Alert));
    v8::Persistent<v8::Context> context = v8::Context::New(NULL, global);
    v8::Context::Scope context_scope(context);

    try
    {
        v8::Handle<v8::String> source = v8::String::New(body.c_str());
        v8::Handle<v8::Script> script;
        v8::Handle<v8::Value>  result;

        {
            v8::TryCatch trycatch;
            script = v8::Script::Compile(source);
            HandleException(trycatch) ? throw std::runtime_error(MessageOfException(trycatch)) : true ;
        }

        {
            v8::TryCatch trycatch;
            result = script->Run();
            HandleException(trycatch) ? throw std::runtime_error(MessageOfException(trycatch)) : true ;
        }

        if ( !result.IsEmpty() )
        {
            v8::String::Utf8Value output(result);
            if (*output)
                std::cout << *output << std::endl;
        }
        else
        {
            std::cerr << "Empty result." << std::endl;
        }
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    catch(...)
    {
        std::cerr << "Unknown exception." << std::endl;
    }

    context.Dispose();
    v8::V8::Dispose();

    return rc;
}

int main(int argc, char** argv)
{
    std::cout << "V8 engine: " << v8::V8::GetVersion() << std::endl;

    std::string eval_str = "";
    if (argc > 1)
    {
        eval_str = argv[1];
        RunJsString(eval_str);
    }

    return EXIT_SUCCESS;
}

