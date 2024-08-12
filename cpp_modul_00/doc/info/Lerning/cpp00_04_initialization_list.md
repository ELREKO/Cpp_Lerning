< [back](cpp00_03_class_instance.md)| [main](/) | [forward](cpp00_05_class_members_and_attributs) >

---

# C++ Initialization List

An initialization list is a syntax feature in C++ that allows you to initialize class members and base classes at the time of object construction. It appears right after the constructor’s parameter list and before the constructor’s body.


## Basic Syntax

```cpp
ClassName::ClassName(ParameterList) : member1(initValue1), member2(initValue2) {
    // Constructor body
}
```

- **`ClassName::ClassName`**: Constructor’s definition.
- **`ParameterList`**: List of parameters passed to the constructor.
- **`member1(initValue1)`**: Initializes `member1` with `initValue1`.
- **`member2(initValue2)`**: Initializes `member2` with `initValue2`.

## Examples

Here is an example of using an initialization list to initialize class members.

**Header File: `SampleClass.hpp`**

```cpp
#ifndef SAMPLE_CLASS_H
#define SAMPLE_CLASS_H

class Sample
{
private: 
    char c1;
    int i1;
    float f1;

public: 
    Sample(char a1, int b1, float c1);
    ~Sample(void);
};
#endif
```

### Using **Source File: `SampleClass.cpp`**

```cpp
#include <iostream>
#include "SampleClass.hpp"

// Constructor using assignment
Sample::Sample(char a1, int b1, float c1)
{
    std::cout << "Constructor called" << std::endl;
    
    this->c1 = a1; 
    this->i1 = b1; 
    this->f1 = c1;

    std::cout << "Variable c1: " << this->c1 << std::endl;
    std::cout << "Variable i1: " << this->i1 << std::endl;
    std::cout << "Variable f1: " << this->f1 << std::endl;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl; 
}
```

In the above example, `c1`, `i1`, and `f1` are assigned values inside the constructor body.

# OR: Using Initialization List

Using the initialization list is a more efficient and cleaner way to initialize members:

**Source File: `SampleClass.cpp`**

```cpp
#include <iostream>
#include "SampleClass.hpp"

// Constructor using initialization list
Sample::Sample(char a1, int b1, float c1) : c1(a1), i1(b1), f1(c1)
{
    std::cout << "Constructor called" << std::endl;
    std::cout << "Variable c1: " << this->c1 << std::endl;
    std::cout << "Variable i1: " << this->i1 << std::endl;
    std::cout << "Variable f1: " << this->f1 << std::endl;
}

Sample::~Sample(void)
{
    std::cout << "Destructor called" << std::endl; 
}
```
