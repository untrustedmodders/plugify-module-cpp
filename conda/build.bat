@echo off
REM build.bat - For Windows builds

if not exist "%PREFIX%\bin" mkdir "%PREFIX%\bin"

copy bin\plugify-module-cpp.dll "%PREFIX%\bin\" || exit 1
copy plugify-module-cpp.pmodule "%PREFIX%\" || exit 1

REM Create activation scripts
if not exist "%PREFIX%\etc\conda\activate.d" mkdir "%PREFIX%\etc\conda\activate.d"
if not exist "%PREFIX%\etc\conda\deactivate.d" mkdir "%PREFIX%\etc\conda\deactivate.d"

echo @echo off > "%PREFIX%\etc\conda\activate.d\plugify-module-cpp.bat"
echo set "PLUGIFY_CPP_MODULE_PATH=%%CONDA_PREFIX%%;%%PLUGIFY_CPP_MODULE_PATH%%" >> "%PREFIX%\etc\conda\activate.d\plugify-module-cpp.bat"

echo @echo off > "%PREFIX%\etc\conda\deactivate.d\plugify-module-cpp.bat"
echo set "PLUGIFY_CPP_MODULE_PATH=%%PLUGIFY_CPP_MODULE_PATH:%%CONDA_PREFIX%%;=%%" >> "%PREFIX%\etc\conda\deactivate.d\plugify-module-cpp.bat"

exit 0
