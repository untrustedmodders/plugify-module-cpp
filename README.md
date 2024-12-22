# C++ Language Module for Plugify

The C++ Language Module for Plugify enables developers to write plugins in C++ for the Plugify framework. This module provides a seamless integration for C++ plugins, allowing them to be dynamically loaded and managed by the Plugify core.

## Features

- **C++ Plugin Support**: Write your plugins in C++ and integrate them effortlessly with the Plugify framework.
- **Automatic Exporting**: Easily export and import methods between plugins and the language module.
- **Initialization and Cleanup**: Handle plugin initialization, startup, and cleanup with dedicated module events.
- **Interoperability**: Communicate with plugins written in other languages through auto-generated interfaces.

## Getting Started

### Prerequisites

- C++ Compiler with C++20 support
- Plugify Framework Installed

### Installation

#### Option 1: Install via Plugify Plugin Manager

You can install the C++ Language Module using the Plugify plugin manager by running the following command:

```bash
plg install plugify-module-cpp
```

#### Option 2: Manual Installation

1. Install dependencies:  

   a. Windows
   > Setting up [CMake tools with Visual Studio Installer](https://learn.microsoft.com/en-us/cpp/build/cmake-projects-in-visual-studio#installation)

   b. Linux:
   ```sh
   sudo apt-get install -y build-essential cmake ninja-build
   ```

   c. Mac:
   ```sh
   brew install cmake ninja
   ```

2. Clone this repository:

    ```bash
    git clone https://github.com/untrustedmodders/plugify-module-cpp.git --recursive
    cd plugify-module-cpp
    ```

3. Build the C++ language module:

    ```bash
    mkdir build && cd build
    cmake ..
    cmake --build .
    ```

### Usage

1. **Integration with Plugify**

   Ensure that your C++ language module is available in the same directory as your Plugify setup.

2. **Write C++ Plugins**

   Develop your plugins in C++ using the Plugify C++ API. Refer to the [Plugify C++ Plugin Guide](https://untrustedmodders.github.io/en/developing/plugins/first-plugin) for detailed instructions.

3. **Build and Install Plugins**

   Compile your C++ plugins and place the shared libraries in a directory accessible to the Plugify core.

4. **Run Plugify**

   Start the Plugify framework, and it will dynamically load your C++ plugins.

## Example

```c++
#include <plugify/cpp_plugin.hpp>
#include <plugin_export.h>
#include <iostream>

class ExamplePlugin : public plugify::IPluginEntry {
public:
	void OnPluginStart() override {
		std::cout << "Example Start!" << std::endl;
	}

	void OnPluginEnd() override {
		std::cout << "Example End!" << std::endl;
	}
} g_examplePlugin;

EXPOSE_PLUGIN(PLUGIN_API, &g_examplePlugin)
```

## Documentation

For comprehensive documentation on writing plugins in C++ using the Plugify framework, refer to the [Plugify Documentation](https://untrustedmodders.github.io).

## Contributing

Feel free to contribute by opening issues or submitting pull requests. We welcome your feedback and ideas!

## License

This C++ Language Module for Plugify is licensed under the [MIT License](LICENSE).
