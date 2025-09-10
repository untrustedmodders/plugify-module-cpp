#!/bin/bash
# build.sh - For Linux builds

set -ex

# Copy entire bin/ folder into $PREFIX/bin/
mkdir -p $PREFIX/bin
cp -r bin/* $PREFIX/bin/

# Copy all .pmodule files into $PREFIX/
cp -r *.pmodule $PREFIX/

# Fix permissions (recursively for bin, selective for modules)
chmod -R 755 $PREFIX/bin
chmod 644 $PREFIX/*.pmodule

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