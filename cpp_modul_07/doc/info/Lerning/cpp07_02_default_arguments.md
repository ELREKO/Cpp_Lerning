
[back](cpp07_01_templates.md) | [main](/) | [forward](cpp07_00_learning.md) >

---

# Default Template Argument
It allows default values to be set for template parameters in a template.

## Syntax
```cpp
template <typename T = int, typename U = double>
class MyClass {
    // Class content
};
```

In this example, the template parameter `T` has the default value `int` and `U` has the default value `double`.

## Usage
```cpp
	MyClass<> obj; // Becomes MyClass<int, double>
```

## Example
```cpp
#include <iostream>
#include <typeinfo>

// Template class
template <typename T = double>
class MyContainer {
private:
    T value;

public:
    // Constructor
    MyContainer(T val) : value(val) {}

    // Getter for the value
    T getValue() const {
        return value;
    }

    // Method to check the type
    void printType() const {
        std::cout << "Type: " << typeid(value).name() << std::endl;
    }
};

// Operator overload for <<
template <typename T>
std::ostream& operator<<(std::ostream& os, const MyContainer<T>& container) {
    os << "Value: " << container.getValue();
    return os;
}

int main() {
    MyContainer<int> intContainer(42);
    MyContainer<> doubleContainer(42.0);  // Note that a double is passed here

    // Output via the << operator
    std::cout << intContainer << std::endl;
    std::cout << doubleContainer << std::endl;

    // Type check
    intContainer.printType();
    doubleContainer.printType();

    return 0;
}
```