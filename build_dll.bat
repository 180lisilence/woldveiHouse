@echo off
chcp 65001 >nul
call "C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
cd /d "D:\pingye_pack\development\current\woldvein_trainer0.4.2"
cl /LD /O2 /Fe:dist\woldvein_trainer.dll src\injector\trainer.c /link psapi.lib
echo.
echo 编译完成，按任意键退出...
pause >nul