Embed-GoogleV8 test project.
============================


Building:
---------
    git@github.com:okertanov/Embed-GoogleV8.git
    cd Embed-GoogleV8
    git submodule add https://github.com/v8/v8.git v8
    git submodule init
    git submodule update
    git submodule foreach "git pull"
    call build-v8.cmd
    cd jj
    call "C:\Program Files (x86)\Microsoft Visual Studio 9.0\VC\bin\vcvars32.bat"
    make


The JavaScript shell:
---------------------
    jj.exe "var msg= ''; ['Hello', 'World!'].map(function(v){msg += v + ' '}); Alert(msg)"

    jj.exe "((1e-3 + 1e-2) / .05).toPrecision(20)"

    jj.exe "+ new Date()"

