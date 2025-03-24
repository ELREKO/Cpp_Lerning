
[back](cpp06_06_cast_operators.md) | [main](/) | [forward](cpp06_08_Promotion_casts.md) > 

---

# explicit keyword

The `explicit` keyword is used to prevent automatic type conversion in constructors and conversion operators.

## Example Constructor

```cpp
#include <iostream>

class Base {
public:
    // Constructor with explicit
    explicit Base(int x) : value(x) {
        std::cout << "Base constructor called with value: " << value << std::endl;
    }

private:
    int value;
};

class Derived : public Base {
public:
    // Constructor of Derived that calls the Base constructor
    Derived(int y) : Base(y) {
        std::cout << "Derived constructor called" << std::endl;
    }
};

int main() {
	// !!!!!!!!! 
    Derived d = 10; // Compiler error: No implicit conversion allowed without explicit
	// !!!!!!!!!
    Derived d(10.11f); // Allowed, because the conversion is explicit --> But error
	Derived b{10.11f}; // Allowed as a list, but would result in a compiler error!
    return 0;
}
```

## Another Example with operator Cast

```cpp
#include <iostream>

class MyClass {
public:
    MyClass(int x) : value(x) {}
    explicit operator int() const { return value; }
private:
    int value;
};

void print(int x) {
    std::cout << x << std::endl;
}

int main() {
    MyClass obj(20);
    // print(obj); // Compiler error: No automatic conversion path from MyClass to int
    print(static_cast<int>(obj)); // Allowed because the conversion is done explicitly
    return 0;
}
```
