< [back](cpp08_01_05_forward_list.md)| [main](/) | [forward](cpp08_02_00_Container_Assoziativ.md) > 

---
# Stack
## Include
```cpp
#include <stack>
```

## Constructors
```cpp
std::stack<int> stack1; // Default constructor
std::stack<int, std::vector<int>> stack2; // With a specific container type (here std::vector)
std::stack<int> stack3(stack2); // Copy constructor
stack1 = stack3; // Assignment
```

`std::stack` is a <span style="color:red">container adapter</span> that is based on another container (such as `std::deque`, `std::vector`, or `std::list`) and uses the **LIFO** (Last In, First Out) principle.

### By default, `std::deque` is used as the underlying container:
```cpp
std::stack<int, std::deque<int>> stack; // Default underlying container
```

## Methods
The most common methods of the `std::stack` container:

| Method                     | Description                                                                 | Example                                         |
|----------------------------|-----------------------------------------------------------------------------|--------------------------------------------------|
| `push(value)`              | Adds an element to the top of the stack.                                   | `stack.push(10);`                                |
| `pop()`                    | Removes the top element of the stack.                                      | `stack.pop();`                                   |
| `top()`                    | Returns the top element of the stack (without removing it).                | `int val = stack.top();`                         |
| `empty()`                  | Checks if the stack is empty (`true` or `false`).                         | `if (stack.empty()) { ... }`                     |
| `size()`                   | Returns the number of elements in the stack.                               | `size_t n = stack.size();`                       |

## Example Code

```cpp
#include <iostream>
#include <stack>

int main() {
    std::stack<int> stack;

    // Push elements onto the stack
    stack.push(1);
    stack.push(2);
    stack.push(3);

    // Top element of the stack
    std::cout << "Top element: " << stack.top() << std::endl;  // Output: 3

    // Remove top element
    stack.pop();

    // New top element
    std::cout << "New top element: " << stack.top() << std::endl;  // Output: 2

    // Stack size and whether it is empty
    std::cout << "Stack size: " << stack.size() << std::endl;  // Output: 2
    std::cout << "Is stack empty? " << (stack.empty() ? "Yes" : "No") << std::endl;  // Output: No

    return 0;
}
```

## Accessing Elements
- `top()`: Returns the top element of the stack without removing it.
- `pop()`: Removes the top element but does **not** return it.

```cpp
std::stack<int> stack;
stack.push(10);
stack.push(20);

int topElement = stack.top(); // topElement == 20
stack.pop(); // Removes 20 from the stack
topElement = stack.top(); // topElement == 10
```

## Standard Container
`std::stack` uses `std::deque` as the underlying container by default. Alternatively, a different container (e.g., `std::vector` or `std::list`) can be specified:

```cpp
#include <stack>
#include <vector>

std::stack<int, std::vector<int>> stackWithVector; // Uses std::vector instead of std::deque
```

## Limitations
- <span style="color:red">**No direct iterators**</span>: Unlike `std::vector` or `std::deque`, `std::stack` does not allow direct access to its elements (no `begin()`, `end()`, etc.).
- Only access to the top element with `top()`.

## Application of `std::stack`
- **Backtracking**: Algorithms such as Depth-First Search (DFS) often use stacks.
- **Bracket Evaluation**: Stacks are often used to analyze expressions like parentheses in compiler implementations.
- **Undo Functionality**: Stacks are used in software with undo functionality to store and reverse the order of actions.
