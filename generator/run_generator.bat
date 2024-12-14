@echo off
REM Enable delayed variable expansion
setlocal enabledelayedexpansion

REM Check if at least one file was provided
IF "%~1"=="" (
    echo No .pplugin files were provided. Please drag and drop at least one .pplugin file onto the script.
    exit /b
)

REM Ensure the Python generator script exists in the same directory as the batch file
IF NOT EXIST "%~dp0generator.py" (
    echo Python generator script not found in the script directory!
    exit /b
)

REM Ensure Python is installed and available in PATH
WHERE python >nul 2>nul
IF %ERRORLEVEL% NEQ 0 (
    echo Python is not installed or not in PATH.
    exit /b
)

REM Loop through all the dropped .pplugin files
for %%F in (%*) do (
    REM Set the full path to the .pplugin file and its directory
    SET PLUGIN_FILE=%%F
    SET PLUGIN_DIR=%%~dpF

    REM Check if the .pplugin file exists
    IF NOT EXIST "!PLUGIN_FILE!" (
        echo The specified .pplugin file "!PLUGIN_FILE!" does not exist.
    ) ELSE (
        REM Set output directory to be at the same location as the .pplugin file
        SET OUTPUT_DIR=!PLUGIN_DIR!output
        
        REM Ensure the output directory exists. If not, create it.
        IF NOT EXIST "!OUTPUT_DIR!" (
        	echo Output directory does not exist. Creating it at "!OUTPUT_DIR!"...
        	mkdir "!OUTPUT_DIR!"
        )
        
        REM Run the Python script, passing the manifest file and output directory as arguments
        echo Processing file: !PLUGIN_FILE!
        python "%~dp0generator.py" "!PLUGIN_FILE!" "!OUTPUT_DIR!" --override
	)
)

echo All files processed successfully.
