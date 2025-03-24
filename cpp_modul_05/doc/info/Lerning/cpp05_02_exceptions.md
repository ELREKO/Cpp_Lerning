[back](cpp05_01_nested_class.md) | [main](/) | [forward](cpp05_03_function_pointer.md) >

---

# Exception Handling in C++

An exception is an unexpected problem that arises during the execution of a program, causing the program to terminate abruptly with some errors/issues.

## Syntax
```cpp
try {         
     // Code that might throw an exception
     throw SomeExceptionType("Error message");
 } 
catch( ExceptionName e1 )  {   
     // catch block catches the exception thrown from the try block
 } 
```

#### Example
```cpp
#include <iostream>

int main()
{
	try
	{
		int numerator = 12;
    	int denominator = 0;
		
		if(denominator == 0)
			throw std::runtime_error("Division by zero not allowed!");
    	std::cout << numerator / denominator << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << "ERR: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cerr << "Default Exception" << std::endl;
	}
}
```

## Custom Exceptions
- Custom exceptions are derived from `std::exception` classes.
- Using polymorphism, the `what` method can be overridden:
```cpp
virtual const char* what() const noexcept;
```

### Example of a Custom Exception

```cpp
#include <iostream>
#include <exception>
#include <string>

class MyException : public std::exception {
public:
    // Base class for specific errors
    class Error_1 : public MyException {
    public:
        const char* what() const noexcept override {
            return "Error 1 occurred!";
        }
    };

    class Error_2 : public MyException {
    public:
        const char* what() const noexcept override {
            return "Error 2 occurred!";
        }
    };

    // Generic base exception
    const char* what() const noexcept override {
        return "General MyException error";
    }
};

int main() {
    try {
        // Trigger a specific exception
        throw MyException::Error_1();
    } catch (const MyException::Error_1& e) {
        std::cerr << "Specific error: " << e.what() << std::endl;
    } catch (const MyException::Error_2& e) {
        std::cerr << "Specific error: " << e.what() << std::endl;
    } catch (const MyException& e) {
        std::cerr << "General error: " << e.what() << std::endl;
    }

    return 0;
}
```

### Special Example for Safe Division

```cpp
#include <iostream>
#include <exception>
#include <string>

class MyException : public std::exception {
public:
    class DivisionByZero : public MyException {
    public:
        const char* what() const noexcept override {
            return "Division by zero is not allowed!";
        }
    };

    class NegativeDivisor : public MyException {
    public:
        const char* what() const noexcept override {
            return "The divisor cannot be negative!";
        }
    };

    // Method for safe division with validation
    static int safeDivide(int numerator, int denominator) {
        if (denominator == 0) {
            throw DivisionByZero();
        } else if (denominator < 0) {
            throw NegativeDivisor();
        }
        return numerator / denominator;
    }
};

int main() {
    int numerator = 10;
    int denominator = 0;

    try {
        // Use the method within the class to perform the division
        int result = MyException::safeDivide(numerator, denominator);
        std::cout << "Result: " << result << std::endl;
    } catch (const MyException::DivisionByZero& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const MyException::NegativeDivisor& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    } catch (const MyException& e) {
        std::cerr << "General error: " << e.what() << std::endl;
    }

    return 0;
}
```

### Types of Standard Exceptions

The C++ Standard Library provides a range of built-in exceptions.

| Exception Class           | Description                                                               | Inheritance Hierarchy                      |
|---------------------------|---------------------------------------------------------------------------|-------------------------------------------|
| `std::exception`           | Base class for all standard exceptions. Contains the `what()` method.     | - `std::exception`                        |
| └── `std::runtime_error`   | Base class for runtime errors that occur during execution.                | - `std::exception`                        |
| └── `std::logic_error`     | Base class for logical errors caused by program bugs.                     | - `std::exception`                        |
|    └── `std::invalid_argument` | Error for invalid arguments.                                           | - `std::logic_error`                      |
|    └── `std::out_of_range`     | Error for accessing out-of-range values (e.g., array index).           | - `std::logic_error`                      |
|    └── `std::length_error`     | Error for exceeding length limits (e.g., container size).              | - `std::logic_error`                      |
| └── `std::overflow_error`  | Error for arithmetic overflow.                                            | - `std::runtime_error`                    |
| └── `std::underflow_error` | Error for arithmetic underflow.                                           | - `std::runtime_error`                    |
| └── `std::bad_alloc`       | Error for failed memory allocation attempts.                              | - `std::runtime_error`                    |
| └── `std::bad_cast`        | Error for failed type casting (e.g., `dynamic_cast` failure).             | - `std::exception`                        |
| └── `std::bad_typeid`      | Error for accessing `typeid` of a non-existent object.                    | - `std::exception`                        |
| └── `std::bad_function_call` | Error for invalid function calls on `std::function` objects.            | - `std::exception`                        |
| └── `std::bad_exception`   | Error for unknown types of exceptions.                                   | - `std::exception`                        |
| └── `std::future_error`    | Error when using `std::future` and `std::promise`.                        | - `std::runtime_error`                    |
| └── `std::ios_base::failure` | Error during stream I/O, such as reading or writing to streams.          | - `std::runtime_error`                    |

## Comparison to Other Technologies
In other technologies, error handling (e.g., division by zero) is often more automated, so many cases are handled automatically.

In C++, error handling is not automated, which requires manual intervention.

### Disadvantages
Even common errors like "division by zero" often have to be caught manually.

### Advantages
This increases **efficiency**, as it is more **resource-friendly** and avoids unnecessary overhead seen in other technologies. Additionally, it offers greater **flexibility** due to the lack of standard extensions.

