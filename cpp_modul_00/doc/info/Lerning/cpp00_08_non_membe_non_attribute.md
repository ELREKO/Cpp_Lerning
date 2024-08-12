< [back](cpp00_07_use_this_pointer.md) | [main](/) | [forward](cpp00_09_pointer_to_member.md)  >

---


# C++ Best Practices: Non-Member and Non-Attribute Functions

## 1. Non-Member Functions

### Definition
Non-member functions are functions that are **not** part of a class but can operate on instances of the class or its data.

### Usage
- **Free Functions:** These functions are not bound to any class and work directly with class instances or data passed to them.
- **Global Functions:** They do not have access to the internal data of a class unless they are declared as friends.

### Advantages
- **Separation of Concerns:** Allows you to define functions that operate on class data without modifying the class itself.
- **Better Modularity:** Functions can be created and used without being tied to the class’s internal structure.

### Examples

```cpp
#include <iostream>
#include <vector>

// Class definition
class VectorWrapper {
private:
    std::vector<int> data;

public:
    VectorWrapper(const std::vector<int>& vec) : data(vec) {}

    // Friend function declaration
    friend void printVector(const VectorWrapper& vw);
};

// Non-member function
void printVector(const VectorWrapper& vw) {
    for (int elem : vw.data) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;
}

int main() {
    VectorWrapper vw({1, 2, 3, 4});
    printVector(vw); // Calling non-member function
    return 0;
}
```

In this example, `printVector` is a non-member function declared as a `friend` of the class `VectorWrapper` to access its private members.

## 2. Non-Attribute Functions

### Definition
Non-attribute functions are functions that are **not** part of a class’s attributes but are used to perform operations related to the class.

### Usage
- **Free Functions:** These functions operate on instances of classes or on class data but are not members of the class.
- **Helper Functions:** They perform tasks that support the class but do not directly manage the class’s internal data.

### Advantages
- **Reduced Coupling:** Functions that do not interact with internal data members have less dependency on the class.
- **Clearer Interfaces:** Functions that only use public methods of the class are easier to manage and understand.

### Examples

```cpp
#include <iostream>

class Circle {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}
    double getRadius() const { return radius; }
};

// Non-member function to calculate area
double calculateArea(const Circle& c) {
    return 3.14 * c.getRadius() * c.getRadius();
}

int main() {
    Circle circle(5.0);
    std::cout << "Area: " << calculateArea(circle) << std::endl; // Calling non-member function
    return 0;
}
```

Here, `calculateArea` is a non-member function that operates on the `Circle` class but does not modify or directly access its internal data.

## 3. Advantages of Non-Member and Non-Attribute Functions

### Increased Flexibility
- Non-member functions can be defined independently of the class and used across different classes or contexts.

### Improved Testability
- Functions that do not rely on class internals can be tested more easily in isolation.

### Reduced Dependencies
- Functions that are not tied to class attributes avoid unnecessary dependencies and improve maintainability.

## 4. Non-Member Functions as Operators

### Example of Overloading Operators as Non-Member Functions

```cpp
class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r, double i) : real(r), imag(i) {}

    // Getter methods
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // Friend function for operator overloading
    friend Complex operator+(const Complex& lhs, const Complex& rhs);
};

// Non-member function to overload the + operator
Complex operator+(const Complex& lhs, const Complex& rhs) {
    return Complex(lhs.real + rhs.real, lhs.imag + rhs.imag);
}
```

In this example, the `+` operator for the `Complex` class is overloaded as a non-member function.

## 5. Non-Member Functions as Free Functions

### Example of Free Functions

```cpp
#include <iostream>
#include <vector>

// A free function to compute the average of a vector
double computeAverage(const std::vector<int>& vec) {
    if (vec.empty()) return 0.0;
    double sum = 0.0;
    for (int num : vec) {
        sum += num;
    }
    return sum / vec.size();
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << "Average: " << computeAverage(numbers) << std::endl; // Calling free function
    return 0;
}
```

Here, `computeAverage` is a free function that calculates the average of a `std::vector<int>`.

## Summary Table

| **Concept**              | **Definition**                                                               | **Advantages**                                 | **Example**                                    |
|-------------------------|------------------------------------------------------------------------------|-----------------------------------------------|-----------------------------------------------|
| **Non-Member Functions** | Functions that are not part of the class but can access its data via friends | Separation of concerns, modularity          | `void printVector(const VectorWrapper& vw);` |
| **Non-Attribute Functions** | Functions that do not manipulate internal data members of the class         | Lower coupling, clearer interfaces           | `double calculateArea(const Circle& c);`     |
| **Operator Overloading** | Overloading operators as non-member functions                                | Flexibility, can be more intuitive            | `Complex operator+(const Complex& lhs, const Complex& rhs);` |
| **Free Functions**       | Functions that operate on class instances but are not members of the class    | Reusability, simplicity                        | `double computeAverage(const std::vector<int>& vec);` |
