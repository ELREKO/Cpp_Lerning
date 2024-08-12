<[back](cpp03_00_lerning.md) | [main](/) | [forward](cpp03_02_DiamondClass.md)>

---
# Inheritance

## Basic Structure of Inheritance in C++
Base class (Superclass) and derived class (Subclass)

- Base class: The class from which other classes inherit.
- Derived class: The class that inherits from another class.

```cpp
class BaseClass {
    // Base class members
};

class DerivedClass : public BaseClass {
    // Derived class members
};

class DerivedClass_2 : public DerivedClass 
{
    // Derived class members
}
```

## Access Specifiers

- public: Can be used anywhere on an object of the class, within the class itself, and in derived classes.

- protected: Can be used within the class itself and in derived classes.

- private: Can only be used within the class itself.

## Visibility Modifiers in Inheritance

```cpp
class Base {
public:
    int publicVar;
protected:
    int protectedVar;
private:
    int privateVar;
};

class DerivedPublic : public Base {
    // publicVar is public
    // protectedVar is protected
    // privateVar is not accessible
};

class DerivedProtected : protected Base {
    // publicVar is protected
    // protectedVar is protected
    // privateVar is not accessible
};

class DerivedPrivate : private Base {
    // publicVar is private
    // protectedVar is private
    // privateVar is not accessible
};
```

## Virtual Functions
Any member (function) can be overridden in the derived class. However, for "true polymorphic behavior," virtual classes are better.

- WITH `virtual`
  --> Dynamic Binding
  --> Also known as "Run-Time Binding," where the decision about which method to call is made at runtime.

- WITHOUT `virtual`
  --> Static Binding
  --> The binding occurs at compile time, meaning the compiler decides which method to call.

Dynamic Binding is particularly advantageous in scenarios where the exact type of the object is known only at runtime. It thus enables greater flexibility and extensibility of the code.

## `Virtual` for Destructors

It is advisable to set the destructors of the base class as virtual. Otherwise, when deleting an object of the derived class via a base class pointer, only the destructor of the base class is called, which can lead to `resource leaks`.

```cpp
class Base {
public:
    virtual ~Base() {
        cout << "Base class destructor called" << endl;
    }
};

class Derived : public Base {
public:
    ~Derived() {
        cout << "Derived class destructor called" << endl;
    }
};

int main() {
    Base* b = new Derived();
    delete b; // Calls Derived::~Derived() and then Base::~Base()

    return 0;
}
```