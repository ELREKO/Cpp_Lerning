
[back](cpp06_02_downcast_and_upcast.md) | [main](/) | [forward](cpp06_04_reinterpret_cast.md) > 

---

# static_cast and dynamic_cast 

## static_cast
`static_cast` is a C++ casting operation used for type conversion. It is safe if the `cast` is correct at `compile-time`, but it performs `no runtime check`.

### Conversion between Fundamental Data Types

```cpp
int intValue = 10;
double doubleValue = static_cast<double>(intValue);
std::cout << doubleValue << std::endl; // Output: 10.0
```

### Conversion Between Inheritance Hierarchies
Assuming you know that the actual type of the object is the derived class

```cpp
class Base {
public:
    virtual void baseMethod() { std::cout << "Base method" << std::endl; }
    virtual ~Base() = default;
};

class Derived : public Base {
public:
    void derivedMethod() { std::cout << "Derived method" << std::endl; }
};

int main() {
    Base *basePtr = new Derived(); // Base class pointer to derived object

    // Downcast with static_cast
    Derived *derivedPtr = static_cast<Derived *>(basePtr);
    derivedPtr->derivedMethod(); // Access method of derived class

    delete basePtr; // Free memory
    return 0;
}
```

## dynamic_cast
`dynamic_cast` checks `at runtime` if the cast is valid. This is especially important in inheritance hierarchies where you want to ensure that the base class pointer actually points to an object of the derived class.

- **Inheritance** Works only if the base class has a virtual `destructor` or a `virtual method` to enable RTTI (Run-Time Type Information).

- **Return Value** If the cast fails, `dynamic_cast` returns a null pointer. When converting references, a `std::bad_cast` exception is thrown.

### Example
```cpp
#include <iostream>

class Base {
public:
    virtual void baseMethod() { std::cout << "Base method" << std::endl; }
    virtual ~Base() = default; // Virtual destructor needed for dynamic_cast
};

class Derived : public Base {
public:
    void derivedMethod() { std::cout << "Derived method" << std::endl; }
};

int main() {
    Base *basePtr = new Derived(); // Base class pointer to derived object
    
    // Downcast with dynamic_cast
    Derived *derivedPtr = dynamic_cast<Derived *>(basePtr);

    if (derivedPtr) {
        derivedPtr->derivedMethod(); // Works, as basePtr actually points to a Derived object
    } else {
        std::cout << "Downcast failed" << std::endl;
    }
    
    delete basePtr; // Free memory
    return 0;
}
```

| **Property**         | **`static_cast`**                                                                                         | **`dynamic_cast`**                                                                                                          |
|----------------------|-----------------------------------------------------------------------------------------------------------|----------------------------------------------------------------------------------------------------------------------------|
| **Definition**       | A type conversion that is checked at compile-time.                                                        | A type conversion that is checked at runtime.                                                                             |
| **Usage**            | - Fundamental types (e.g., `int` to `double`) <br> - Inheritance hierarchies when types are known at compile-time | - Polymorphism <br> - Downcasting in inheritance hierarchies when types need to be checked at runtime                      |
| **Checking**         | - Compile-time checking <br> - No runtime checking                                                         | - Runtime checking <br> - Returns `nullptr` (for pointers) or `std::bad_cast` (for references) if the cast fails            |
| **Safety**           | - Not safe for unknown types at runtime <br> - No runtime checking                                        | - Safe due to runtime checking <br> - Protection against invalid type conversions                                         |
| **Performance**      | - Faster, as there is no runtime checking                                                                   | - Potentially slower due to runtime checking                                                                             |
