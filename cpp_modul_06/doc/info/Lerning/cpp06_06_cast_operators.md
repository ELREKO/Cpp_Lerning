[back](cpp06_05_const_cast.md) | [main](/) | [forward](cpp06_07_explicit_keyword.md) > 

---

# Cast Operator

The `cast operator` refers to a type of operator overloading for data types within a class.

This becomes clear through the following example:

## Example
```cpp
#include <iostream>

class MyClass {
private:
    float value;

public:
    // Constructor
    MyClass(float v) : value(v) {}

    // Type conversion operator to float
    operator float() const {
        return value;
    }

    // Type conversion operator to int
    operator int() const {
        return static_cast<int>(value);
    }

    // Type conversion operator to double
    operator double() const {
        return static_cast<double>(value);
    }
};

int main() {
    MyClass obj(3.14f);

    // Using the type conversion operators
    float f = obj;          // implicit conversion from MyClass to float
    int i = obj;            // implicit conversion from MyClass to int
    double d = obj;         // implicit conversion from MyClass to double

    std::cout << "Float value: " << f << std::endl;
    std::cout << "Int value: " << i << std::endl;
    std::cout << "Double value: " << d << std::endl;

    return 0;
}
```