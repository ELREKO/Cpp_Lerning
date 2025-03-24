
< [back](cpp08_03_Container_unsort.md) | [main](/) | [forward](cpp08_05_Iteratoren.md) >

# Summary of the `<algorithm>` Library in C++

The `<algorithm>` library in C++ offers a wide range of functions for searching, sorting, modifying, and managing data in *iterative* containers such as `std::vector`, `std::set`, etc. These algorithms often work with iterators and allow for the manipulation of elements within containers.

#### Including the Library
```c++
#include <algorithm>
```

### Important Categories and Examples:

#### 1. **Searching and Finding**
- **`std::find`**: Searches for a specific value in a range.
  ```c++
  std::vector<int> vec = {1, 2, 3, 4, 5};
  auto it = std::find(vec.begin(), vec.end(), 3);
  ```
- **`std::find_if`**: Searches for the first element that satisfies a specific condition.
  ```c++
  auto it = std::find_if(vec.begin(), vec.end(), [](int i){ return i > 3; });
  ```

#### 2. **Sorting**
- **`std::sort`**: Sorts the range [first, last) in ascending order.
  ```c++
  std::sort(vec.begin(), vec.end());
  ```
- **`std::stable_sort`**: Like `std::sort`, but stable (equal elements retain their order).
- **`std::partial_sort`**: Sorts only the first *k* elements.
  ```c++
  std::partial_sort(vec.begin(), vec.begin() + 3, vec.end());
  ```

**[Continue with the remaining sections, following the same structure and style]**

...

### Iterator Support:
All algorithms in `<algorithm>` work with <span style="color:red">**iterators**</span>, which means they can be used with a variety of containers that provide iterators, such as `std::vector`, `std::list`, `std::deque`, `std::array`, etc.
