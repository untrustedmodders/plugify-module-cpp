#!/bin/bash

# Ensure at least one .pplugin file was provided
if [ $# -eq 0 ]; then
    echo "No .pplugin files were provided. Please drag and drop at least one .pplugin file onto the script."
    exit 1
fi

# Ensure the Python generator script exists in the same directory as the bash script
if [ ! -f "$(dirname "$0")/generator.py" ]; then
    echo "Python generator script not found in the script directory!"
    exit 1
fi

# Ensure that Python is installed and available in the PATH
if ! command -v python3 &> /dev/null; then
    echo "Python is not installed or not in PATH."
    exit 1
fi

# Loop over all provided .pplugin files
for PLUGIN_FILE in "$@"; do
    # Check if the file exists
    if [ ! -f "$PLUGIN_FILE" ]; then
        echo "The specified .pplugin file \"$PLUGIN_FILE\" does not exist."
        continue
    fi

    # Get the directory of the .pplugin file
    PLUGIN_DIR=$(dirname "$PLUGIN_FILE")

    # Set output directory to be at the same location as the .pplugin file
    OUTPUT_DIR="$PLUGIN_DIR/output"

    # Ensure the output directory exists. If not, create it.
    if [ ! -d "$OUTPUT_DIR" ]; then
        echo "Output directory does not exist. Creating it at \"$OUTPUT_DIR\"..."
        mkdir "$OUTPUT_DIR"
    fi

    # Run the Python script, passing the manifest file and output directory as arguments
    echo "Processing file: $PLUGIN_FILE"
    python3 "$(dirname "$0")/generator.py" "$PLUGIN_FILE" "$OUTPUT_DIR" --override
    echo "Done processing $PLUGIN_FILE"
done

echo "All files processed successfully."
