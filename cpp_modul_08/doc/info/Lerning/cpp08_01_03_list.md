
# List
Simple flexible insertion and deletion at any position is possible and more efficient than with vector and deque, <span style="background-color: red;">but it does not provide direct access to elements via indices.</span>

## Include
```cpp
#include <list>
```

## Constructors
```cpp
std::list<int> lst1;               // Default Constructor 
std::list<int> lst2(5);            // List with 5 elements, all initialized to 0
std::list<int> lst3(5, 10);        // List with 5 elements, all set to the value 10
std::list<int> lst4 = {1, 2, 3, 4, 5}; // List with 5 elements with the corresponding values
std::list<int> lst5(lst4);         // Copy List 
lst1 = lst5;                       // Assignment List 
```

## Methods

The most common methods of the `std::list` container

| Method                     | Description                                                               | Example                                      |
|----------------------------|---------------------------------------------------------------------------|-----------------------------------------------|
| `push_back(value)`         | Adds an element to the end of the list.                                 | `lst.push_back(7);`                          |
| `push_front(value)`        | Adds an element to the front of the list.                               | `lst.push_front(0);`                         |
| `pop_back()`               | Removes the last element of the list.                                    | `lst.pop_back();`                            |
| `pop_front()`              | Removes the first element of the list.                                   | `lst.pop_front();`                           |
| `insert(position, value)`   | Inserts an element at the specified position in the list.               | `lst.insert(++lst.begin(), 5);`              |
| `erase(position)`          | Removes the element at the specified position.                           | `lst.erase(++lst.begin());`                  |
| `clear()`                  | Removes all elements from the list.                                      | `lst.clear();`                               |
| `size()`                   | Returns the number of current elements in the list.                      | `size_t n = lst.size();`                     |
| `empty()`                  | Checks whether the list is empty.                                        | `bool isEmpty = lst.empty();`                |

- The position specified in `insert()` and `erase()` must be indicated using an iterator, e.g., `lst.insert(++lst.begin(), 5);` (which refers to position 1, or the second element).

1. **`insert(position, value)`**:
   - **Description**: Inserts an element at a specific position in the list. The position is indicated by an iterator.
   - **Example**:
     ```cpp
     std::list<double> lst = {1.1, 2.2, 3.3}; // List contains: [1.1, 2.2, 3.3]
     lst.insert(++lst.begin(), 5.5); // Inserts 5.5 at position 1
     // List now contains: [1.1, 5.5, 2.2, 3.3]
     ```

2. **`erase(position)`**:
   - **Description**: Removes the element at a specific position in the list.
   - **Example**:
     ```cpp
     lst.erase(++lst.begin()); // Removes the element at position 1 (5.5)
     // List now contains: [1.1, 2.2, 3.3]
     ```

## Accessing Elements
- **No direct access** via indices, as it is a doubly linked list. Access is typically done through iterators.
- **`front()`**: Returns the first element (no bound check).
- **`back()`**: Returns the last element (no bound check).

```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5};
    
    // Accessing the first and last element
    std::cout << "First element: " << lst.front() << std::endl; // Output: 1
    std::cout << "Last element: " << lst.back() << std::endl;   // Output: 5

    return 0;
}
```

## Iterators
- `begin()` and `end()`: Forward iteration
- `rbegin()` and `rend()`: Reverse iteration
- `cbegin()` and `cend()`: Constant iterators (no modifications allowed)

```cpp
#include <iostream>
#include <list>

int main() {
    std::list<int> lst = {1, 2, 3, 4, 5};

    // Iterating with an iterator
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it) {
        std::cout << *it << " ";  // Output: 1 2 3 4 5
    }
    std::cout << std::endl;

    // Reverse iteration with rbegin() and rend()
    for (std::list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit) {
        std::cout << *rit << " ";  // Output: 5 4 3 2 1
    }

    for (std::list<int>::const_iterator it = lst.cbegin(); it != lst.cend(); ++it) {
        std::cout << *it << " "; // Outputs the values, but cannot be modified
    }

    return 0;
}
```

