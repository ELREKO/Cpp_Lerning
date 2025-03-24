[back](cpp06_04_reinterpret_cast.md) | [main](/) | [forward](cpp06_06_cast_operators.md) > 

---

# Const Cast

`const_cast` allows you to modify the constness of a pointer or reference.

This means you can use `const_cast` to convert a `const` pointer or `const` reference to a non-const pointer or non-const reference.

```cpp
#include <iostream>

void printValue(int *value){
	*value = 100;
	std::cout << "Value is: " << *value << std::endl;
}

int main() {
    const int val = 42;
    const int* ptr = &val;

    // Using const_cast to use the printValue function, 
	// which expects a non-const pointer
    printValue(const_cast<int*>(ptr));
	
	// printValue(&val); // This does not work as printValue expects a non-const value;

    std::cout << "The original value is: " << val << std::endl;  // This value is not guaranteed to be correct
    std::cout << "The value pointed to by ptr is: " << *ptr << std::endl;  // This value is not guaranteed to be correct

	return 0;
}
```