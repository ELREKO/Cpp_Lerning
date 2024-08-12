< [back](cpp00_01_namespace.md)| [main](/) | [forward](cpp00_03_class_instance.md) >

# Overview of the `<iostream>` Library in C++

The `<iostream>` library in C++ is part of the Standard Library and provides facilities for input and output (I/O) using streams. It is a crucial part of C++ programming for handling console input and output operations. Here’s a detailed overview of the `<iostream>` library:

### Include function

| Name  | Description                                |
|-------|--------------------------------------------|
| cerr  | Represents the global `cerr` stream.       |
| cin   | Represents the global `cin` stream.        |
| clog  | Represents the global `clog` stream.       |
| cout  | Represents the global `cout` stream.       |
| wcerr | Represents the global `wcerr` stream.      |
| wcin  | Represents the global `wcin` stream.       |
| wclog | Represents the global `wclog` stream.      |
| wcout | Represents the global `wcout` stream.      |

- `c..` e.g. `clog` Character Encoding: It uses narrow characters (char).
- `c..` e.g. `wlog` Character Encoding: It uses wide characters (wchar_t) --> international.

## Key Components

### Standard Input (`cin`)
- **Description**: `std::cin` is an object of the `istream` class and is used to accept input from the standard input device (usually the keyboard).
- **Usage**:
  ```cpp
  #include <iostream>
  int main() {
      int number;
      std::cout << "Enter a number: ";
      std::cin >> number;
      std::cout << "You entered: " << number << std::endl;
      return 0;
  }
  ```

### Standard Output (`cout`)
- **Description**: `std::cout` is an object of the `ostream` class and is used to output data to the standard output device (usually the screen).
- **Usage**:
  ```cpp
  #include <iostream>
  int main() {
      std::cout << "Hello, World!" << std::endl;
      return 0;
  }
  ```

### Standard Error (`cerr`)
- **Description**: `std::cerr` is an object of the `ostream` class and is used to output error messages to the standard error device. It is unbuffered, meaning the output is immediate.
- **Usage**:
  ```cpp
  #include <iostream>
  int main() {
      std::cerr << "An error occurred!" << std::endl;
      return 0;
  }
  ```

### Standard Log (`clog`)
- **Description**: `std::clog` is an object of the `ostream` class and is used to output log messages to the standard error device. It is buffered, meaning the output may not be immediate.
- **Usage**:
  ```cpp
  #include <iostream>
  int main() {
      std::clog << "Log message" << std::endl;
      return 0;
  }
  ```

## Stream Operations

### Insertion Operator (<<)
- **Description**: Used to insert data into the output stream (`std::cout`, `std::cerr`, etc.).
- **Usage**:
  ```cpp
  int value = 10;
  std::cout << "The value is: " << value << std::endl;
  ```

### Extraction Operator (>>)
- **Description**: Used to extract data from the input stream (`std::cin`).
- **Usage**:
  ```cpp
  int value;
  std::cin >> value;
  ```

## Formatting Output

### `endl`
- **Description**: Inserts a newline character and flushes the stream.
- **Usage**:
  ```cpp
  std::cout << "Hello" << std::endl;
  ```

## Stream States

Streams have state flags that can be checked to ensure successful operations:

### `eof()`
- **Description**: Checks if the end-of-file has been reached.
- **Usage**:
  ```cpp
  if (std::cin.eof()) {
      std::cout << "End of file reached" << std::endl;
  }
  ```

### `fail()`
- **Description**: Checks if a non-fatal error has occurred (e.g., input type mismatch).
- **Usage**:
  ```cpp
  if (std::cin.fail()) {
      std::cerr << "Input error" << std::endl;
  }
  ```

### `bad()`
- **Description**: Checks if a fatal error has occurred (e.g., stream buffer failure).
- **Usage**:
  ```cpp
  if (std::cin.bad()) {
      std::cerr << "Fatal error" << std::endl;
  }
  ```

### `clear()`
- **Description**: Resets the state flags.
- **Usage**:
  ```cpp
  std::cin.clear(); // Clear all error flags
  ```

