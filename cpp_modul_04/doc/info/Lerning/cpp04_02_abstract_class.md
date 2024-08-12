<[backward](cpp04_01_sub-typing_polymorphism.md) | [main](/) | [forward](cpp04_03_virtual_table.md) > 

---

# Abstract Classes in C++

Abstract classes in C++ are classes that contain at least **one** pure virtual function. Pure virtual functions are functions that are defined in the base class but do not have an implementation and are marked with `= 0` (`virtual ..... = 0`). Abstract classes serve as base classes for other classes and cannot be instantiated.

**Pure Virtual Function**
A pure virtual function is only declared in the base class and not implemented. This forces all derived classes to implement this function.

## Abstract Classes vs. Interfaces

In Java, multiple inheritance as in C++ is not allowed (see module cpp03). However, a class can inherit from multiple interfaces. An interface is a class that allows defining abstract methods and constants without specifying their implementation. Interfaces cannot be instantiated in `main`.

In C++, there are no interfaces, but there are abstract classes. These can be used similarly to interfaces.

## Example of an Abstract Class

In this example, `Shape` cannot be instantiated, but pointers to objects of derived classes such as `Circle` can be created. The derived class `Circle` implements the `draw` function and can use the other functions of the base class.

```cpp
#include <iostream>

class Shape {
protected:
    int _parameter[2];
public:
    virtual void draw() const = 0;  // Pure virtual function
    virtual ~Shape() = default;     // Virtual destructor

    void askInput() {
        std::cout << "Asking for input..." << std::endl;
        // Example input prompt
        std::cin >> _parameter[0] >> _parameter[1];
    }

    void setInput() {
        std::cout << "Setting input..." << std::endl;
        // Example implementation
        _parameter[0] = 10;
        _parameter[1] = 20;
    }
};

class Circle : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a circle" << std::endl;
    }
};

class Square : public Shape {
public:
    void draw() const override {
        std::cout << "Drawing a square" << std::endl;
    }
};

void drawShape(const Shape& shape) {
    shape.draw();
}

int main() {
    Shape* circle = new Circle;
    Shape* square = new Square;

    circle->askInput();
    square->askInput();

    drawShape(*circle);  // Output: Drawing a circle
    drawShape(*square);  // Output: Drawing a square

    delete circle;  // Free memory
    delete square;  // Free memory

    return 0;
}
```

## Notes

- Abstract classes can only be used as base classes and must be instantiated through derived classes.

- All functions that are declared as pure virtual (`= 0`) in an abstract class must be implemented in the derived classes.

- The destructor of the abstract class should be declared as virtual to ensure that derived classes are correctly destroyed when a pointer to the base class is deleted.
