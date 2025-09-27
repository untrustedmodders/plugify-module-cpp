#!/bin/bash
# build.sh - For Unix builds

set -ex

# Detect the platform and set the appropriate library extension
if [[ "$OSTYPE" == "darwin"* ]]; then
    LIB_EXT="dylib"
elif [[ "$OSTYPE" == "linux-gnu"* ]]; then
    LIB_EXT="so"
else
    echo "Unsupported platform: $OSTYPE"
    exit 1
fi

# Create the target directories
mkdir -p $PREFIX/bin
mkdir -p $PREFIX

# Copy the shared library and module file
cp bin/libplugify-module-cpp.$LIB_EXT $PREFIX/bin/
cp plugify-module-cpp.pmodule $PREFIX/

# Set proper permissions
chmod 755 $PREFIX/bin/libplugify-module-cpp.$LIB_EXT
chmod 644 $PREFIX/plugify-module-cpp.pmodule

# Create activation scripts for proper library path
mkdir -p $PREFIX/etc/conda/activate.d
mkdir -p $PREFIX/etc/conda/deactivate.d

cat > $PREFIX/etc/conda/activate.d/plugify-module-cpp.sh << EOF
#!/bin/bash
export PLUGIFY_CPP_MODULE_PATH="\${CONDA_PREFIX}:\${PLUGIFY_CPP_MODULE_PATH}"
EOF

cat > $PREFIX/etc/conda/deactivate.d/plugify-module-cpp.sh << EOF
#!/bin/bash
export PLUGIFY_CPP_MODULE_PATH="\${PLUGIFY_CPP_MODULE_PATH//\${CONDA_PREFIX}:/}"
EOF

chmod +x $PREFIX/etc/conda/activate.d/plugify-module-cpp.sh
chmod +x $PREFIX/etc/conda/deactivate.d/plugify-module-cpp.sh