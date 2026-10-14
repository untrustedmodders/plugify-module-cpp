#!/bin/bash
# build.sh - For Linux and macOS builds

set -ex

if [[ "$target_platform" == osx-* ]]; then
    LIB_EXT="dylib"
else
    LIB_EXT="so"
fi

mkdir -p $PREFIX/bin

cp bin/libplugify-module-cpp.$LIB_EXT $PREFIX/bin/
cp plugify-module-cpp.pmodule $PREFIX/

chmod 755 $PREFIX/bin/libplugify-module-cpp.$LIB_EXT
chmod 644 $PREFIX/plugify-module-cpp.pmodule

# Create activation scripts for proper library path
mkdir -p $PREFIX/etc/conda/activate.d
mkdir -p $PREFIX/etc/conda/deactivate.d

cat > $PREFIX/etc/conda/activate.d/plugify-module-cpp.sh << EOF2
#!/bin/bash
export PLUGIFY_CPP_MODULE_PATH="\${CONDA_PREFIX}:\${PLUGIFY_CPP_MODULE_PATH}"
EOF2

cat > $PREFIX/etc/conda/deactivate.d/plugify-module-cpp.sh << EOF2
#!/bin/bash
export PLUGIFY_CPP_MODULE_PATH="\${PLUGIFY_CPP_MODULE_PATH//\${CONDA_PREFIX}:/}"
EOF2

chmod +x $PREFIX/etc/conda/activate.d/plugify-module-cpp.sh
chmod +x $PREFIX/etc/conda/deactivate.d/plugify-module-cpp.sh
