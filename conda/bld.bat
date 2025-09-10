@echo off
REM bld.bat - For Windows builds

REM Create the target directories
if not exist "%PREFIX%\bin" mkdir "%PREFIX%\bin"

REM Copy entire folders into %PREFIX
xcopy bin "%PREFIX%\bin" /E /Y /I

REM Copy all .pmodule files into %PREFIX%
copy *.pmodule "%PREFIX%\" || exit 1

REM Create activation scripts
if not exist "%PREFIX%\etc\conda\activate.d" mkdir "%PREFIX%\etc\conda\activate.d"
if not exist "%PREFIX%\etc\conda\deactivate.d" mkdir "%PREFIX%\etc\conda\deactivate.d"

REM Create activation script
echo @echo off > "%PREFIX%\etc\conda\activate.d\plugify-module-cpp.bat"
echo set "PLUGIFY_CPP_MODULE_PATH=%%CONDA_PREFIX%%;%%PLUGIFY_CPP_MODULE_PATH%%" >> "%PREFIX%\etc\conda\activate.d\plugify-module-cpp.bat"

REM Create deactivation script  
echo @echo off > "%PREFIX%\etc\conda\deactivate.d\plugify-module-cpp.bat"
echo set "PLUGIFY_CPP_MODULE_PATH=%%PLUGIFY_CPP_MODULE_PATH:%%CONDA_PREFIX%%;=%%" >> "%PREFIX%\etc\conda\deactivate.d\plugify-module-cpp.bat"

exit 0
