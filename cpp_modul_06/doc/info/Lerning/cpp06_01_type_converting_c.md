
[back](cpp06_00_lerning.md) | [main](/) | [forward](cpp06_02_downcast_and_upcast.md) > 

---

# Type Converting in C

## Types of Type Conversion

### Implicit Type Conversion
Automatically performed by the compiler without programmer intervention.

- Larger data types, e.g., `int` to `double`, can be converted easily since `double` is larger than `int`.
- Implicit conversion from larger to smaller data types, e.g., `double` to `int`, can lead to loss of information, such as truncation of decimal places.

### Explicit Type Conversion
Deliberate type conversion by the programmer using casts. This allows control over how the compiler performs the conversion.

### Example of Implicit and Explicit Type Conversion
```c
int a = 42;
double b = a; // Implicit type conversion

double c = 42.42f;
int d = (int)c; // Explicit type conversion
```

### Type Reinterpretation
Type reinterpretation (also known as type casting) refers to converting a pointer from one data type to another, often using C-style casts or C++ type casting operators.

- Changes the data type and interpretation of the data.
- Example: Changing the interpretation of `double` as `int` leads to undefined behavior because the data types are different.
- However, it may be desired when data types are being interchanged between C and C++.

#### Example
```c
#include <stdio.h>

int main() {
    double a = 42.424242;
    void *ptr = &a; // void* can point to any address
    
    // Type Reinterpretation: void* to double*
    double *double_ptr = (double *)ptr;
    printf("Value of a: %f\n", *double_ptr);
    
    // Type Reinterpretation: void* to int*
    int *int_ptr = (int *)ptr; // This line results in undefined behavior
    printf("Interpreted as int: %d\n", *int_ptr);
    
    return 0;
}
```

### Type Qualifier Reinterpretation
Type qualifier reinterpretation refers to converting a pointer or reference where only the type qualifiers (such as `const`, `volatile`, `restrict`) are changed, without altering the underlying type.

- Only changes qualifiers like `const` or `volatile` without changing the actual data type.

- Example: Removing `const` allows modifications to data originally defined as `const`.

```c
#include <stdio.h>

void printInt(const int *value) {
    printf("Value: %d\n", *value);
}

int main() {
    int a = 42;
    const int *const_ptr = &a; // const int*
    
    // Type Qualifier Reinterpretation: const int* to int*
    int *mutable_ptr = (int *)const_ptr; // This is dangerous but legal in C
    
    *mutable_ptr = 100; // Changing the value
    printInt(const_ptr); // Shows the modified value
    
    return 0;
}
```
