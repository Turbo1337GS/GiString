# GiString Class Documentation

![GiString Logo](https://main.gigasoft.com.pl/logo.png)

## Overview

GiString is an advanced string manipulation library that augments the standard C++ `std::string` class, providing rich functionalities that are often required in various applications but are not present in the standard library. It provides numerous ways to handle, query, and transform string data, making it a reliable and handy tool for both simple and complex string operations.

The library is under active development, with new features and updates being added regularly. The project is open-source, licensed under the [MIT License](), and welcomes contributions from the community.

For more information about the library, and to stay updated with the latest developments, visit [GigaSoft](https://gigasoft.com.pl).

## Table of Contents

- [Installation](#installation)
- [Usage Examples](#usage-examples)
- [Building the Project](#building-the-project)
- [API Reference](#api-reference)
  - [Construction and Assignment](#construction-and-assignment)
  - [String Operations](#string-operations)
  - [Case Manipulation](#case-manipulation)
  - [String Queries](#string-queries)
  - [Substring and Replacement](#substring-and-replacement)
  - [String Comparison](#string-comparison)
  - [Trimming and Padding](#trimming-and-padding)
  - [Conversion](#conversion)
  - [File Operations](#file-operations)
  - [Utility Functions](#utility-functions)
- [Contributing](#contributing)
- [License](#license)

## Installation

To use GiString in your C++ projects:

1. Download the latest version of `GiString.hpp` and `GiString.cpp` from the [GiString repository](https://github.com/Turbo1337GS/gistring).
2. Place the downloaded files in your project's include directory.
3. Include the header file in your source code:

   ```cpp
   #include "GiString.hpp"
   ```

4. Ensure that `GiString.cpp` is added to your project's source files list and compiled along with them.

## Usage Examples

Using the GiString library is as simple as working with the standard `std::string` class but with added functionality:

### Basic Initialization and Appending

```cpp
#include "GiString.hpp"

int main() {
    GiString text("Hello, GiString!");
    
    // Convert to uppercase
    GiString upperText = text.toUpperCase();
    std::cout << upperText.getValue() << std::endl; // Outputs: HELLO, GISTRING!
    
    // Append another string
    text.append(" Let's manipulate strings with ease.");
    std::cout << text.getValue() << std::endl;
    
    return 0;
}
```

### Trimming and Checking Properties

```cpp
#include "GiString.hpp"

int main() {
    GiString email("  example@example.com  ");

    email.trim(); // Trim whitespace from both ends
    bool isValidEmail = email.is_valid_email(); // Check if it's a valid email address format
    
    std::cout << "Trimmed Email: " << email.getValue() << std::endl;
    std::cout << "Is Valid Email: " << (isValidEmail ? "Yes" : "No") << std::endl;
    
    return 0;
}
```

### Case Conversion and Validation

```cpp
#include "GiString.hpp"

int main() {
    GiString text("GigaSoft123");

    bool isAlphanumeric = text.is_alphanumeric(); // Check for alphanumeric characters only
    GiString lowerText = text.toLowerCase(); // Convert to lowercase
    
    std::cout << "Original: " << text.getValue() << std::endl;
    std::cout << "Lowercase: " << lowerText.getValue() << std::endl;
    std::cout << "Is Alphanumeric: " << (isAlphanumeric ? "Yes" : "No") << std::endl;
    
    return 0;
}
```

### Replacing Substrings and Removing Characters

```cpp
#include "GiString.hpp"

int main() {
    GiString text("The C++ programming language is powerful.");
    
    // Replace "C++" with "GiString"
    text.replace("C++", "GiString");
    
    // Remove all occurrences of 'i'
    text.erase('i');
    
    std::cout << text.getValue() << std::endl; // Outputs: The GiString programmng language s powerful.
    
    return 0;
}
```

## Building the Project

To build the GiString class alongside your project's code, you can use Makefile provided:

```makefile
# To build the executable
all: GigaSoft

GigaSoft: main.cpp
    g++ ./*.cpp ./*.hpp -o GigaSoft

# To clean up the build
clean:
    rm -f GigaSoft
```

Run `make all` to build and `make clean` to remove the built executable.

## API Reference

Due to the length and rich feature set of GiString, please refer to the header file `GiString.hpp` for detailed API documentation. Here are some of the categories of methods you can expect to find:

### Construction and Assignment

- `GiString(const std::string &str)`
- `GiString &setValue(const std::string &value)`

### String Operations

- `GiString &append(const std::string &value)`
- `GiString &insert(size_t index, const std::string &value)`
- `GiString &erase(const std::string &str)`
- `GiString &erase(char ch)`

### Case Manipulation

- `GiString toLowerCase() const`
- `GiString &toUpperCase()`
- `GiString &swapcase()`
- `GiString &capitalize()`
- `GiString &title()`

### String Queries

- `bool is_numeric() const`
- `bool is_alpha() const`
- `bool is_alphanumeric() const`
- `bool is_whitespace() const`
- `bool empty() const`

### Substring and Replacement

- `GiString &replace(const std::string str1, std::string str2)`
- `GiString &substr(const std::string str)`
- `GiString &substr(const size_t index, const size_t endIndex)`

### String Comparison

- `GiString &compare(const std::string &str)`
- `bool operator==(const char *cstr) const`
- `bool operator!=(const char *cstr) const`

### Trimming and Padding

- `GiString &trim()`
- `GiString &trimLeft()`
- `GiString &trimRight()`
- `GiString &pad_left(size_t total_width, char pad = ' ')`
- `GiString &pad_right(size_t total_width, char pad = ' ')`

### Conversion

- `int to_int() const`
- `float to_float() const`
- `double to_double() const`
- `GiString &from_int(int value)`
- `GiString &from_float(float value, int precision = 6)`

### File Operations

- `static GiString read_from_file(const std::string &file_path)`
- `void write_to_file(const std::string &file_path) const`

### Utility Functions

- `GiString &unique()`
- `GiString &repeat(size_t times)`
- `GiString &zfill(size_t width)`
- `size_t count_words() const`
  
... and many more. Please refer to the [source code](https://github.com/your-github/gistring) for the full list and details.

## Contributing

Contributions to the GiString project are welcome! To contribute:

1. Fork the repository.
2. Create a new branch for each feature or improvement.
3. Send a pull request from each feature branch to the main branch for review.

When contributing to the library, please follow the project's coding conventions and comment standards.

## License

This project is open-source software licensed under the MIT License. See the [LICENSE](LICENSE.md) file for more information.