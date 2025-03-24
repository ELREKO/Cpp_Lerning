
< [back](cpp08_05_Iteratoren.md) | [main](/) | [forward](cpp08_00_lerning.md) >

# Functors in C++

## What is a Functor?
A **functor** is an object in C++ that behaves like a function. This is achieved by overloading the **function call operator** (`operator()`). As a result, the object can be invoked like a function.

## Features of Functors
- **Class with `operator()`**: Functors are classes that overload the `operator()`.
- **Stateful**: Functors can store internal state, which is not possible with regular functions.
- **Flexibility**: They allow easy parameterization of algorithms.

## Example of a Functor

```cpp
#include <iostream>

// Definition of a Functor
class Adder {
public:
    // Overloaded function call operator
    int operator()(int a, int b) {
        return a + b; // Add the two numbers
    }
};

int main() {
    Adder add; // Instantiation of the functor
    std::cout << add(2, 3) << std::endl; // Output: 5
    return 0;
}
```

## Advantages of Functors
1. **State storage**: Functors can have variables that retain their value between calls.
2. **Reusability**: They can be specialized for different data types or operations.
3. **Integration with STL**: Functors can be easily used in STL algorithms.

## Difference from Other Concepts
- **Function pointers**: Point to a function but have no state.
- **Overloading `operator=`**: Determines how an instance of a class is assigned to another instance, <span style="color:red">but is not a functor</span>.