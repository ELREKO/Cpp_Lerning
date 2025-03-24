[back](cpp07_00_learning.md) | [main](/) | [forward](cpp07_02_default_arguments.md) >

---

# Templates
Templates are a feature that allows writing generic code that works with different data types. They provide a way to define functions and classes that can work with any data type.

## File Naming
Templates can be declared in the header. However, to avoid large `.h` or `.hpp` files and improve readability, it is often useful to use separate template files, like `.tpp` or sometimes `.ipp`.

## 1. Function Templates
A function template allows you to define a function that can work with different data types.

-> Check exercise `ex00` to test data types.

```cpp
#include <iostream>

template <typename T>
T add(T a, T b) {
    return a + b;
}

template <typename T>
void print(std::string str, T value) {
    std::cout 	<< str << ": " 
				<< value << " (Type: " 
				<< typeid(T).name() 
				<< ")" << std::endl;
}

int main() {
    int x = 5, y = 10;
    double a = 2.5, b = 3.5;

    std::cout << "Sum of x and y: " << add(x, y) << std::endl;
    std::cout << "Sum of a and b: " << add(a, b) << std::endl;

	print<double>("The value is", a); 
    return 0;
}
```

## 2. Class Templates
Class templates allow you to create classes that work with different data types.

```cpp
#include <iostream>

template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;

public:
    Pair(T1 f, T2 s) : first(f), second(s) {}

    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }
};

int main() {
    Pair<int, double> p1(1, 2.5);
    Pair<std::string, int> p2("Hello", 100);

    std::cout << "p1: (" << p1.getFirst() << ", " << p1.getSecond() << ")" << std::endl;
    std::cout << "p2: (" << p2.getFirst() << ", " << p2.getSecond() << ")" << std::endl;

    return 0;
}

```

## 3. Template Specialization
Template specialization can be seen as a form of polymorphism but with the following differences:

- Polymorphism in C++ usually refers to dynamic behavior at runtime (e.g., through virtual functions and inheritance).
- Templates and specialization offer a form of static polymorphism at compile-time, where the compiler decides which function or class to use based on the types of the arguments.
- So, you could say that template specialization is a form of polymorphism, but one that happens entirely at compile-time and does not incur runtime overhead. It is static polymorphism as opposed to dynamic polymorphism.

### Example: Function
```cpp
#include <iostream>

// Generic function template
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Full specialization for the int type
template <>
int add<int>(int a, int b) {
    std::cout << "Addition of int values: ";
    return a + b;
}

int main() {
    std::cout << add(3.5, 2.5) << std::endl;   // Generic version (double)
    std::cout << add(3, 2) << std::endl;       // Specialized version (int)

    return 0;
}
```

### Example: Class
```cpp
#include <iostream>

// Generic template
template <typename T>
class Calculator {
public:
    T add(T a, T b) {
        return a + b;
    }
};

// Full specialization for the int type
template <>
class Calculator<int> {
public:
    int add(int a, int b) {
        std::cout << "Addition of integers: ";
        return a + b;
    }
};

int main() {
    Calculator<double> calc1;  // Uses the generic template
    Calculator<int> calc2;     // Uses the specialized version for int

    std::cout << calc1.add(3.2, 4.3) << std::endl;   // Generic version for double
    std::cout << calc2.add(3, 4) << std::endl;       // Specialized version for int

    return 0;
}
```