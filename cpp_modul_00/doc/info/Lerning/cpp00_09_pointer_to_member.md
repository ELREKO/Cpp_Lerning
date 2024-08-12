< [back](cpp00_08_non_membe_non_attribute.md)| [main](/) | [forward](cpp00_00_lerning.md) >

---

# C++ Pointers to Members

In C++, pointers to members are a powerful feature that allows you to work with data members and member functions of a class in a dynamic and flexible way. This document will provide a comprehensive overview of **Pointer to Data Members** and **Pointer to Member Functions**, including syntax, examples, and best practices.

---

## Pointer to Data Members

### Concept

A **pointer to a data member** allows you to refer to a specific data member of a class. This pointer can then be used to access or modify the data member for a particular class instance.

### Syntax

```cpp
type ClassName::*pointerToDataMember;
```

- `type` is the data type of the member (e.g., `int`).
- `ClassName` is the name of the class.
- `pointerToDataMember` is the name of the pointer.

**Example:**

```cpp
int Sample::*p;       // Pointer to an int data member of Sample class
p = &Sample::foo;     // Assign the address of 'foo' to the pointer 'p'
```

### Example

```cpp
#include <iostream>
#include "Sample.hpp"

int main() {
    Sample instance;
    int Sample::*p = &Sample::foo;  // Pointer to 'foo'

    instance.*p = 42;  // Set the value of 'foo' to 42 using the pointer
    std::cout << "Value of member foo: " << instance.foo << std::endl;

    return 0;
}
```

### Best Practices

- Use data member pointers when you need to manipulate data members in a generic way.
- Ensure that the data member pointer is valid before dereferencing it.
- Prefer using `nullptr` instead of `NULL` for pointer initialization.

## Pointer to Member Functions

### Concept

A **pointer to a member function** refers to a specific member function of a class. This pointer can be used to call the function for a particular class instance.

### Syntax

```cpp
returnType (ClassName::*pointerToMemberFunction)(arguments) const;
```

- `returnType` is the return type of the member function.
- `ClassName` is the name of the class.
- `pointerToMemberFunction` is the name of the pointer.
- `arguments` specifies the function parameters.
- `const` indicates if the function is `const`.

**Example:**

```cpp
void (Sample::*f)(void) const;  // Pointer to a const member function with no arguments
f = &Sample::bar;                // Assign the address of 'bar' to the pointer 'f'
```

### Example

```cpp
#include <iostream>
#include "Sample.hpp"

int main() {
    Sample instance;
    void (Sample::*f)(void) const;  // Pointer to 'bar'

    f = &Sample::bar;               // Assign the address of 'bar' to the pointer

    (instance.*f)();  // Call the function 'bar' using the pointer

    return 0;
}
```
### Best Practices

- Use member function pointers when you need to call functions dynamically.
- Ensure the member function pointer matches the signature of the function you intend to call.
- Use `const` qualifiers correctly based on the function's behavior.

## Combined Use

### Concept

Combining data member pointers and member function pointers can be useful for complex operations where you need to access data members and call functions dynamically.

### Syntax

```cpp
type ClassName::*dataMemberPointer;
returnType (ClassName::*memberFunctionPointer)(arguments) const;
```

**Example:**

```cpp
#include <iostream>
#include "Sample.hpp"

int main() {
    Sample instance;
    int Sample::*p = &Sample::foo;
    void (Sample::*f)(void) const = &Sample::bar;

    instance.*p = 21;  // Set 'foo' to 21
    std::cout << "Value of member foo: " << instance.foo << std::endl;

    (instance.*f)();  // Call 'bar' function

    return 0;
}
```


### Best Practices

- Use combined pointers for advanced scenarios where you need both data access and function calls.
- Ensure both pointers (`dataMemberPointer` and `memberFunctionPointer`) are valid.
- Validate pointers before using them.



---
## Compleat example 

## *.hpp
```cpp
#ifndef SAMPLE_HPP
#define SAMPLE_HPP

class Sample {
public:
    int foo;
    void bar() const;

    Sample() : foo(0) {} 
};

#endif // SAMPLE_HPP
```
## *.cpp

```cpp
#include <iostream>
#include "Sample.hpp"

int main ()
{

	Sample 		instanc;
	Sample*		inst = &instanc; 

	int Sample::*p = NULL;
	void (Sample:: *f)(void) const; 

	p = &Sample::foo; 

	std::cout << "Volue of member foo: " << instance.foo << std::endl; 
	instance.*p = 21; 
	std::cout << "Volume of member foo: " << instance.foo << 
	std::endl;
	instance->*p = 42;
	std::cout << "Volume of member " << instance.foo << std.endl; 

	f = &Sample::bar; 
	(instance.*f)();
	(instance->*f)();

	return (0); 
}

```