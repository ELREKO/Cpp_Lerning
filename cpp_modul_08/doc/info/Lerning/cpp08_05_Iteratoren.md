
< [back](cpp08_04_Algoritmen.md) | [main](/) | [forward](cpp08_06_Funtoren.md) >

# Iterators

### What are Iterators?

In C++, **iterators** are special objects used to iterate over and access elements of a container (such as `std::vector`, `std::list`, `std::set`, etc.). They function similarly to pointers but allow for general access to containers and their elements, regardless of the type of the container.

### Using Iterators

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};

    // Using an iterator to iterate over the vector
    std::vector<int>::iterator it;  // Defines an iterator for the vector

    for (it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " ";  // Dereferencing the iterator to display the element
    }

    return 0;
}
```

### Iterators and Containers

Most C++ containers provide functions that return iterators:
- **`begin()`**: Returns an iterator to the first element.
- **`end()`**: Returns an iterator to the "one-past-the-end" element (i.e., the element after the last).
- **`rbegin()`**: Returns a reverse iterator to the last element (for reverse iteration).
- **`rend()`**: Returns a reverse iterator to the element before the first element.

### Example of Constant Iterators

A constant iterator allows read access to the elements but prevents modification:

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec = {10, 20, 30, 40, 50};

    std::vector<int>::const_iterator it;  // Constant iterator

    for (it = vec.cbegin(); it != vec.cend(); ++it) {
        std::cout << *it << " ";  // Allows only reading the elements
        // *it = 100;  // Error: Attempt to modify an element
    }

    return 0;
}
```

### Comparison of Iterator Types

| Container        | Iterator Type          | Description |
|------------------|-----------------------|--------------|
| `std::vector`    | Random Access Iterator | Allows access to arbitrary positions |
| `std::list`      | Bidirectional Iterator | Can iterate forwards and backwards |
| `std::set`       | Bidirectional Iterator | Ordered sets, iterates in sorted order |
| `std::deque`     | Random Access Iterator | Arbitrary access similar to `std::vector` |
| `std::stack`     | No Iterators          | `std::stack` provides <span style="color:red"> no direct iterator access</span> |

### Important Iterator Operations and Their Use

| Operation         | Description                                      | Example                                          |
|-------------------|---------------------------------------------------|---------------------------------------------------|
| `*it`             | Dereferencing: Accessing the element pointed to by the iterator. | `int value = *it;`                                |
| `it->member`      | Accessing a member of the object pointed to by the iterator (similar to `(*it).member`). | `it->length();` (for iterators on objects)      |
| `++it`            | Pre-increment: Moves the iterator to the next element (forwards). | `++it;`                                           |
| `it++`            | Post-increment: Moves the iterator forwards but returns the old state first. | `it++;`                                           |
| `--it`            | Pre-decrement: Moves the iterator to the previous element (backwards, only for bidirectional iterators). | `--it;`                                           |
| `it--`            | Post-decrement: Moves the iterator backwards but returns the old state first (only for bidirectional iterators). | `it--;`                                           |
| `it == other_it`  | Compares two iterators for equality.         | `if (it == vec.end())`                            |
| `it != other_it`  | Compares two iterators for inequality.       | `if (it != vec.end())`                            |
| `it + n`          | Moves the iterator forward by `n` positions (only for random access iterators). | `it = it + 3;`                                    |
| `it - n`          | Moves the iterator backward by `n` positions (only for random access iterators). | `it = it - 2;`                                    |
| `it[n]`           | Accesses the `n`-th element relative to the iterator (only for random access iterators). | `std::cout << it[2];`                             |
| `std::distance(first, last)` | Returns the number of elements between two iterators. | `std::distance(vec.begin(), vec.end());`          |
| `std::advance(it, n)` | Moves the iterator forward or backward by `n` positions. | `std::advance(it, 3);`                            |

### Different Iterator Categories

| Iterator Type              | Example Container       | Supported Operations            |
|---------------------------|--------------------------|-------------------------------------|
| **Input Iterator**         | `std::istream_iterator`   | Reading data, forward movement only |
| **Output Iterator**        | `std::ostream_iterator`   | Writing data, forward movement only |
| **Forward Iterator**       | `std::forward_list`       | Forward movement, reading and writing |
| **Bidirectional Iterator** | `std::list`, `std::set`   | Forward and backward movement          |
| **Random Access Iterator** | `std::vector`, `std::deque` | Forward and backward movement, random access (`[]`, `+`, `-`) |

Iterators are a fundamental concept in C++, allowing you to access and work with containers in a generic and efficient manner.