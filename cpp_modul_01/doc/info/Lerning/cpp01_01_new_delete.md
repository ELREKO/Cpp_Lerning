<[back](cpp01_00_lerning.md) | [main](/) | [forward](cpp01_02_pointer_vs_reference.md)>

---

# new and delete

## Using `new`

The `new` operator allocates memory on the heap and calls the constructor for an object. It returns a pointer to the allocated memory.

Syntax for using `new`:
```cpp
int* ptr = new int;          // Allocates memory for a single int
int* array = new int[10];    // Allocates memory for an array of 10 ints
```

## Using `delete`

The `delete` operator frees the memory allocated with `new` and calls the destructor for the object.

Syntax for using `delete`:
```cpp
delete ptr;           // Frees the memory for a single int
delete[] array;       // Frees the memory for an array of ints
```

It's important to ensure that every `new` call is accompanied by a corresponding `delete` call to avoid memory leaks.

## Advantages of `new` and `delete`

- **Dynamic Memory Management**: With `new` and `delete`, you can allocate and deallocate memory dynamically at runtime.

- **Object Lifetime**: You can control the lifetime of objects.

- **No Fixed Size Constraints**: Unlike stack allocations (e.g., local variables), which have limited memory, heap allocation with `new` allows managing larger amounts of data.

- **Flexible Data Structures**: Data structures like linked lists, trees, and other dynamic structures require dynamic memory management, which `new` and `delete` provide.

## Disadvantages of `new` and `delete`

**Manual Memory Management**:
   - Errors such as memory leaks (when memory is not freed) and double frees (when memory is freed more than once) can occur.
   - This increases maintenance requirements and the likelihood of bugs.
   - Can lead to fragmentation, especially with frequent `new` and `delete` operations.
   - A `std::bad_alloc` exception is thrown if memory allocation fails. If this exception is not properly handled, the program can crash.
   - Incompatibilities and inconsistencies can arise if different modules or libraries follow different memory allocators or strategies.

## Alternatives
Smart pointers like `std::unique_ptr` and `std::shared_ptr` in the C++11 and later standard libraries help automate and make memory management safer.

### Example

Here is a simple example demonstrating the use of `new` and `delete`:

```cpp
#include <iostream>

class MyClass {
public:
    MyClass() { std::cout << "Constructor called!" << std::endl; }
    ~MyClass() { std::cout << "Destructor called!" << std::endl; }
};

int main() {
    MyClass* obj = new MyClass();  // Allocates memory and calls the constructor
    // Use the object
    delete obj;                    // Calls the destructor and frees the memory

    int* array = new int[5];       // Allocates memory for an array
    // Use the array
    delete[] array;                // Frees the memory for the array

    return 0;
}
```