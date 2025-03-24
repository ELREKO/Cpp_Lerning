[back](cpp05_02_exceptions.md) | [main](/) | [forward](cpp05_00_learning.md) >

---

# Function Pointers

See ex03

- A function pointer stores the address of a function and can be used to call that function later.

- The function pointer can also be used as an array.

**Syntax**
```cpp
ReturnType (*FunctionPointer)(ArgumentType1, ArgumentType2, ...);
``` 

## Example 

```cpp
#include <iostream>

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() 
{
    int (*operation)(int, int);
    operation = &add;
    std::cout << "Addition: " << operation(5, 3) << std::endl;
    operation = &subtract;
    std::cout << "Subtraction: " << operation(5, 3) << std::endl;

    return 0;
}
```

## Advantages of Function Pointers

- **Usage of Callback Functions:** A function itself can use the function pointer as a parameter to react individually to events.

### Callback Example

```cpp
#include <iostream>

void callbackFunction() {
    std::cout << "Callback function was called!" << std::endl;
}

void performTask(void (*callback)()) {
    std::cout << "Task is being executed..." << std::endl;
    callback();
}

int main() {
    performTask(callbackFunction);
    return 0;
}
```

- **Dynamic Function Selection:** When different functions need to be used at runtime.

- **Using Function Pointers as an Array:**
--> see ex03.

# Example of Function Pointer Array
```cpp
int (*operations[])(int, int) = {add, subtract};
std::cout << "Addition from array: " << operations[0](10, 5) << std::endl;
std::cout << "Subtraction from array: " << operations[1](10, 5) << std::endl;
```
