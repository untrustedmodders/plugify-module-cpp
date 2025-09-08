@echo off
REM bld.bat - For Windows builds

REM Create the target directories
if not exist "%PREFIX%\Library\bin" mkdir "%PREFIX%\Library\bin"
if not exist "%PREFIX%\Library" mkdir "%PREFIX%\Library"

REM Copy the DLL and module file
copy bin\plugify-module-cpp.dll "%PREFIX%\Library\bin\" || exit 1
copy plugify-module-cpp.pmodule "%PREFIX%\Library\" || exit 1

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