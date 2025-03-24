
# Forward List
Like `list`, random element access is not possible! 
Requires less memory than `list`!

## Include
```cpp
#include <forward_list>
```

## Constructors
```cpp
std::forward_list<int> flst1;                  // Default constructor 
std::forward_list<int> flst2(5);               // Forward list with 5 elements, all initialized to 0
std::forward_list<int> flst3(5, 10);           // Forward list with 5 elements, all with the value 10
std::forward_list<int> flst4 = {1, 2, 3, 4, 5}; // Forward list with 5 elements with the corresponding values
std::forward_list<int> flst5(flst4);            // Copy forward list 
flst1 = flst5;                                  // Assignment of forward list 
```

## Methods

The most common methods of the `std::forward_list` container

| Method                     | Description                                                              | Example                                      |
|----------------------------|--------------------------------------------------------------------------|-----------------------------------------------|
| `push_front(value)`        | Adds an element to the front of the forward list.                      | `flst.push_front(0);`                        |
| `pop_front()`              | Removes the first element of the forward list.                         | `flst.pop_front();`                          |
| `insert_after(position, value)` | Inserts an element after the specified position in the list.     | `flst.insert_after(flst.begin(), 5);`       |
| `erase_after(position)`     | Removes the element after the specified position.                     | `flst.erase_after(flst.begin());`           |
| `clear()`                  | Removes all elements from the forward list.                             | `flst.clear();`                              |
| `size()`                   | Returns the number of elements in the forward list.                    | `size_t n = std::distance(flst.begin(), flst.end());` |
| `empty()`                  | Checks if the forward list is empty.                                    | `bool isEmpty = flst.empty();`               |

1. **`insert_after(position, value)`**:
   - **Description**: Inserts an element after a specified position in the forward list. The position is specified by an iterator.
   - **Example**:
     ```cpp
     std::forward_list<double> flst = {1.1, 2.2, 3.3}; // Forward list contains: [1.1, 2.2, 3.3]
     flst.insert_after(flst.begin(), 5.5); // Inserts 5.5 after position 0
     // Forward list now contains: [1.1, 5.5, 2.2, 3.3]
     ```

2. **`erase_after(position)`**:
   - **Description**: Removes the element after a specified position in the forward list.
   - **Example**:
     ```cpp
     flst.erase_after(flst.begin()); // Removes the element after position 0 (5.5)
     // Forward list now contains: [1.1, 2.2, 3.3]
     ```

## Accessing Elements
- **No direct access** via indices, as it is a singly linked list. Access is typically done through iterators.
- **`front()`**: Returns the first element (no bound check).

```cpp
#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> flst = {1, 2, 3, 4, 5};
    
    // Accessing the first element
    std::cout << "First element: " << flst.front() << std::endl; // Output: 1

    return 0;
}
```

## Iterators
- `begin()` and `end()`: Forward iteration
- `cbegin()` and `cend()`: Constant iterators (no modifications allowed)

```cpp
#include <iostream>
#include <forward_list>

int main() {
    std::forward_list<int> flst = {1, 2, 3, 4, 5};

    // Iterating with an iterator
    for (std::forward_list<int>::iterator it = flst.begin(); it != flst.end(); ++it) {
        std::cout << *it << " ";  // Output: 1 2 3 4 5
    }
    std::cout << std::endl;

    for (std::forward_list<int>::const_iterator it = flst.cbegin(); it != flst.cend(); ++it) {
        std::cout << *it << " "; // Outputs the values, but cannot be modified
    }

    return 0;
}
```
