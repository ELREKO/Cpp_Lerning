
# Vectors 
## Include 
```cpp
#include <vector>
```

## Constructors 
```cpp
    std::vector<int> vec1; // Default Constructor 
    std::vector<int> vec2(5);  // Vector with 5 elements, all initialized to 0
    std::vector<int> vec3(5, 10);  // Vector with 5 elements, all set to the value 10
    std::vector<int> vec4 = {1, 2, 3, 4, 5}; // Vector with 5 elements with the corresponding values
    std::vector<int> vec5(vec4); // Copy Vector 
    vec1 = vec5; // Assignment Vector 
```

## Methods 

The most common methods of the `std::vector` container

| Method                     | Description                                                                | Example                                         |
|----------------------------|----------------------------------------------------------------------------|--------------------------------------------------|
| `push_back(value)`         | Adds an element to the end of the vector.                                 | `vec.push_back(7.2);`                           |
| `pop_back()`               | Removes the last element of the vector.                                   | `vec.pop_back();`                               |
| `insert(position, value)`   | Inserts an element at the specified position in the vector.               | `vec.insert(vec.begin() + 1, 5.5);`             |
| `erase(position)`          | Removes the element at the specified position.                             | `vec.erase(vec.begin() + 1);`                   |
| `clear()`                  | Removes all elements from the vector.                                     | `vec.clear();`                                  |
| `size()`                   | Returns the number of current elements in the vector.                     | `size_t n = vec.size();`                        |
| `capacity()`               | Returns the current capacity of the vector.                               | `size_t cap = vec.capacity();`                  |
| `resize(new_size)`         | Changes the size of the vector to `new_size`.                            | `vec.resize(5);`                                |
| `shrink_to_fit()`          | Reduces the capacity of the vector to the current size.                   | `vec.shrink_to_fit();`                          |

- The position specified in `insert()` and `erase()` must be indicated using an iterator, like `vec.begin() + 1` (which refers to position 1, or the second element). For example, `vec.insert(1, 5.5)` would result in a compilation error. 

1. **`insert(position, value)`**:
   - **Description**: Inserts an element at a specific position in the vector. The position is indicated by an iterator.
   - **Example**:
     ```cpp
     std::vector<double> vec = {1.1, 2.2, 3.3}; // Vector contains: [1.1, 2.2, 3.3]
     vec.insert(vec.begin() + 1, 5.5); // Inserts 5.5 at position 1
     // Vector now contains: [1.1, 5.5, 2.2, 3.3]
     ```

1. **`erase(position)`**:
   - **Description**: Removes the element at a specific position in the vector.
   - **Example**:
     ```cpp
     vec.erase(vec.begin() + 1); // Removes the element at position 1 (5.5)
     // Vector now contains: [1.1, 2.2, 3.3]
     ```

## Accessing Elements 
- `operator[]` -> no bound check
- `at()` -> bound check -> `std::out_of_range`

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    try {
        std::cout << vec.at(10) << std::endl;  // Exception will be thrown 
    } catch (const std::out_of_range& e) {
        std::cerr << "Index out of range: " << e.what() << std::endl;
    }

    return 0;
}
```

## Iterators 
- `begin()` and `end()`: Forward iteration
- `rbegin()` and `rend()`: Reverse iteration
- `cbegin()` and `cend()`: Constant iterators (no modifications allowed)

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Iterating with an iterator
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";  // Output: 1 2 3 4 5
    }
    std::cout << std::endl;

    // Reverse iteration with rbegin() and rend()
    for (std::vector<int>::reverse_iterator rit = vec.rbegin(); rit != vec.rend(); ++rit) {
        std::cout << *rit << " ";  // Output: 5 4 3 2 1
    }

    for (std::vector<int>::const_iterator it = vec.cbegin(); it != vec.cend(); ++it) {
        std::cout << *it << " "; // Outputs the values, but cannot be modified
    }

    return 0;
}
```
