<[backward](cpp04_00_lerning.md) | [main](/) | [forward](cpp04_02_abstract_class.md) > 

---

# Sub-typing Polymorphism

## Explanation of Sub-typing Polymorphism

Sub-typing Polymorphism, also known as `Inclusion Polymorphism`, is a fundamental concept in object-oriented programming that allows an object of a certain class to be treated as an object of one of its base classes.

In C++, this concept is often realized through inheritance and `virtual` functions.

-> `Base class` provides the general interface or behavior.
-> `Derived class` has specialized or customized methods.

## Example

### **With** the `virtual` keyword

The method call is decided at runtime based on the actual object type (dynamic binding). The method of the derived class is called if the pointer points to a derived object.

```cpp
#include <iostream>

class Base {
public:
    virtual void display() {
        std::cout << "Display from Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        std::cout << "Display from Derived class" << std::endl;
    }
};

int main() {
    Base* b = new Derived(); // Pointer to base class points to derived object
    b->display(); // Calls the overridden method in the derived class
    
    delete b;
    return 0;
}
```

Output
```Display from Derived class``` --> here the function from the `Derived` class is used.

---

### **Without** the `virtual` keyword

The compiler binds the method at compile time (static binding). The method of the base class is called regardless of the object type the pointer points to.

```cpp
#include <iostream>

class Base {
public:
    void display() {
        std::cout << "Display from Base class" << std::endl;
    }
};

class Derived : public Base {
public:
    void display() override {
        std::cout << "Display from Derived class" << std::endl;
    }
};

int main() {
    Base* b = new Derived(); // Pointer to base class points to derived object
    b->display(); // Calls the method from the base class
    
    delete b;
    return 0;
}
```

Output
```Display from Base class``` --> here the function from the `Base` class is used.
