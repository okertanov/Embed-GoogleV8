##    Copyright (C) 2011 Oleg Kertanov <okertanov@gmail.com>
##    All rights reserved.

V8_INC=/I../v8/include
V8_LIB=../v8/v8.lib

CC=cl.exe
CPPFLAGS=/MD /EHsc /W3 /nologo /Od /D_DEBUG $(V8_INC)
LDFLAGS=ws2_32.lib user32.lib winmm.lib $(V8_LIB)
LINKER=/link /SUBSYSTEM:CONSOLE /LTCG /DEBUG /PDB:jj.pdb

all: jj.exe

jj.cpp: jj.h

japi.cpp: japi.h

jj.exe: jj.cpp japi.cpp
	$(CC) $(CPPFLAGS) $^ $(LDFLAGS) $(LINKER)

clean:
	-@rm -f *.exe *.manifest
	-@rm -f *.obj *.o *.pdb *.suo

.PTHONY: all clean

.SILENT: clean

