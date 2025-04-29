# WcwidthWrapper

**WcwidthWrapper** is a C++ library that calculates the display width of Unicode characters, facilitating accurate rendering in console applications. It provides a native interface for determining the number of terminal cells a Unicode character occupies, supporting wide characters and surrogate pairs.

## Features

- **Unicode Width Calculation**: Determine the number of terminal cells a Unicode character occupies.
- **Support for Surrogate Pairs**: Accurately handle characters represented by surrogate pairs.
- **Native C++ Interface**: Seamlessly integrate with C++ applications without the need for external dependencies.

## Installation

To integrate **WcwidthWrapper** into your project:

1. Clone the repository:

   ```bash
   git clone https://github.com/BDisp/WcwidthWrapper.git
   ```

2. Include the header file in your project:

   ```cpp
   #include "NativeExports.h"
   ```

3. Link against the compiled library during the build process.

## Usage

Here's a simple example demonstrating how to use **WcwidthWrapper**:

```cpp
#include <iostream>
#include "NativeExports.h"

int main() {
    wchar_t ch = L'あ'; // Example Unicode character
    int width = GetWidth(ch, /* version */ 0);
    std::wcout << L"Character width: " << width << std::endl;
    return 0;
}
```

## Acknowledgements

This project is inspired by the [Spectre.Console/wcwidth](https://github.com/spectreconsole/wcwidth) repository, a .NET library that calculates the width of Unicode characters. We extend our gratitude to the Spectre.Console team for their work, which served as a valuable reference in developing this C++ wrapper.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
