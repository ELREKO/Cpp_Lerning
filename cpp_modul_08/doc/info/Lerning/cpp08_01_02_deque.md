
# Deque

The methods and the handling of iterators are similar to `std::vector`, but with additional methods like <span style="background-color: green;">push_front</span> and <span style="background-color: green;">pop_front</span>, which are specific to the double-ended queue.

## Include
```cpp
#include <deque>
```

## Constructors
```cpp
std::deque<int> deq1;               // Default Constructor 
std::deque<int> deq2(5);            // Deque with 5 elements, all initialized to 0
std::deque<int> deq3(5, 10);        // Deque with 5 elements, all set to the value 10
std::deque<int> deq4 = {1, 2, 3, 4, 5}; // Deque with 5 elements with the corresponding values
std::deque<int> deq5(deq4);         // Copy Deque 
deq1 = deq5;                         // Assignment Deque 
```

## Methods

The most common methods of the `std::deque` container

| Method                     | Description                                                                | Example                                      |
|----------------------------|----------------------------------------------------------------------------|-----------------------------------------------|
| `push_back(value)`         | Adds an element to the end of the deque.                                  | `deq.push_back(7);`                          |
| `push_front(value)`        | Adds an element to the front of the deque.                                | `deq.push_front(0);`                         |
| `pop_back()`               | Removes the last element of the deque.                                    | `deq.pop_back();`                            |
| `pop_front()`              | Removes the first element of the deque.                                   | `deq.pop_front();`                           |
| `insert(position, value)`   | Inserts an element at the specified position in the deque.                | `deq.insert(deq.begin() + 1, 5);`           |
| `erase(position)`          | Removes the element at the specified position.                            | `deq.erase(deq.begin() + 1);`               |
| `clear()`                  | Removes all elements from the deque.                                      | `deq.clear();`                               |
| `size()`                   | Returns the number of current elements in the deque.                      | `size_t n = deq.size();`                     |
| `capacity()`               | Returns the capacity of the deque (not always available).                 | `size_t cap = deq.max_size();`               |
| `resize(new_size)`         | Changes the size of the deque to `new_size`.                             | `deq.resize(5);`                             |
| `shrink_to_fit()`          | Reduces the capacity of the deque to the current size (not always available). | `deq.shrink_to_fit();`                       |

- The position specified in `insert()` and `erase()` must be indicated using an iterator, e.g., `deq.insert(deq.begin() + 1, 5);` (which refers to position 1, or the second element).

1. **`insert(position, value)`**:
   - **Description**: Inserts an element at a specific position in the deque. The position is indicated by an iterator.
   - **Example**:
     ```cpp
     std::deque<double> deq = {1.1, 2.2, 3.3}; // Deque contains: [1.1, 2.2, 3.3]
     deq.insert(deq.begin() + 1, 5.5); // Inserts 5.5 at position 1
     // Deque now contains: [1.1, 5.5, 2.2, 3.3]
     ```

2. **`erase(position)`**:
   - **Description**: Removes the element at a specific position in the deque.
   - **Example**:
     ```cpp
     deq.erase(deq.begin() + 1); // Removes the element at position 1 (5.5)
     // Deque now contains: [1.1, 2.2, 3.3]
     ```

## Accessing Elements
- `operator[]` -> no bound check
- `at()` -> bound check -> `std::out_of_range`

```cpp
#include <iostream>
#include <deque>

int main() {
    std::deque<int> deq = {1, 2, 3, 4, 5};
    try {
        std::cout << deq.at(10) << std::endl;  // Exception will be thrown 
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
#include <deque>

int main() {
    std::deque<int> deq = {1, 2, 3, 4, 5};

    // Iterating with an iterator
    for (std::deque<int>::iterator it = deq.begin(); it != deq.end(); ++it) {
        std::cout << *it << " ";  // Output: 1 2 3 4 5
    }
    std::cout << std::endl;

    // Reverse iteration with rbegin() and rend()
    for (std::deque<int>::reverse_iterator rit = deq.rbegin(); rit != deq.rend(); ++rit) {
        std::cout << *rit << " ";  // Output: 5 4 3 2 1
    }

    for (std::deque<int>::const_iterator it = deq.cbegin(); it != deq.cend(); ++it) {
        std::cout << *it << " "; // Outputs the values, but cannot be modified
    }

    return 0;
}
```