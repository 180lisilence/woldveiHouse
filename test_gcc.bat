@echo off
chcp 65001 >nul
set "PATH=D:\TOOL\mingw64\mingw64\bin;D:\TOOL\mingw64\mingw64\x86_64-w64-mingw32\bin;%PATH%"
cd /d "D:\pingye_pack\development\current\woldvein_trainer0.4.2\src\injector"
gcc -v 2>&1
echo EXIT: %ERRORLEVEL%
pause
