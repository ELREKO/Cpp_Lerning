< [back](cpp00_05_class_members_and_attributs.md)| [main](/) | [forward](cpp00_07_use_this_pointer.md)  >

---

# Access Modifiers in C++

## Private Attributes (Default Setting)

- Can only be directly accessed within the class in which they are declared.
- Are not directly accessible in derived classes.

## Protected Attributes

- Can be accessed within the class in which they are declared.
- Are also directly accessible in all classes derived from this class.

## Public Attributes

- Can be accessed from anywhere in the program.
- Are accessible within the class, in derived classes, and by any other code that has visibility of the object.

## UML Dokumetation
In UML (Unified Modeling Language) diagram notation, there is a standardized representation for different visibilities.

- **Private:** `-`
- **Protected:** `#`
- **Public:** `+`

### Example of a UML Class Diagram

```plaintext
+----------------------+
|      ClassName       |
+----------------------+
| - privateAttribute   |
| # protectedAttribute |
| + publicAttribute    |
+----------------------+
| + publicMethod()     |
| # protectedMethod()  |
| - privateMethod()    |
+----------------------+
```

## Good Praxis use **_** underline for privat or protected  

In C++ header files, we don't use the UML notation (+, #, -). These symbols `_` for privat members or Attributs.

```cpp
#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include <iostream>

class Example {
private:
    int _privateAttribute;
    void _privateMethod() 

protected:
    int _protectedAttribute;
    void _protectedMethod();

public:
	Example();
	~Example();
    int publicAttribute;
    void publicMethod();
    void showAttributes();
};

#endif
```


