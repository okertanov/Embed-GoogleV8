REM    Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
REM    All rights reserved.

REM http://code.google.com/p/v8/wiki/BuildingOnWindows
REM svn checkout http://v8.googlecode.com/svn/branches/bleeding_edge/ v8

call "C:\Program Files (x86)\Microsoft Visual Studio 9.0\VC\bin\vcvars32.bat"

cd v8

scons env="PATH:%PATH%,INCLUDE:%INCLUDE%,LIB:%LIB%" msvcrt=shared -j4

