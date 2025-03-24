
[back](cpp06_01_type_converting_c.md) | [main](/) | [forward](cpp06_03_static_and_dynamic_cast.md) > 

---

# Upcasting and Downcasting

## Upcasting
Upcasting occurs when an object of a derived class (child class) is cast to a pointer or reference of the base class (parent class).

- **Safe:** Always safe because every instance of the derived class is also an instance of the base class.

- **Loss of Access:** Access to specific methods and data of the derived class is lost.

### Example
```cpp
#include <iostream>

class Base {
public:
    void baseMethod() { std::cout << "Base method" << std::endl; }
};

class Derived : public Base {
public:
    void derivedMethod() { std::cout << "Derived method" << std::endl; }
};

int main() {
    Derived derived;
    Base *basePtr = &derived; // Upcast: Derived* to Base*
    basePtr->baseMethod(); // Access to base class method
    // basePtr->derivedMethod(); // Error: Base class has no derivedMethod
    return 0;
}
```

## Downcasting
Downcasting occurs when a pointer or reference to a base class is cast to a pointer or reference to a derived class.

- **Risk:** Can be unsafe if the actual type of the object is not the expected derived type.

- **Requires Type Checking:** Use `static_cast`, `dynamic_cast`, etc.

```cpp
#include <iostream>

class Base {
public:
    virtual void baseMethod() { std::cout << "Base method" << std::endl; }
    virtual ~Base() = default; // Required for dynamic_cast
};

class Derived : public Base {
public:
    void derivedMethod() { std::cout << "Derived method" << std::endl; }
};

int main() {
    Base *basePtr; // Base class pointer to derived object
    
    // Downcast !!! This leads to errors in the compiler 
    Derived *derivedPtr = &(basePtr);

    delete basePtr;
    
    return 0;
}
```
