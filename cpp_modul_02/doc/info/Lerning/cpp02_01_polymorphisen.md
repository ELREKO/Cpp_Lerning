<[back](cpp02_00_lerning.md) | [main](/) | [forward](cpp02_02_orthodox_canonical.md) >

# Ad-hoc Polymorphism in C++ (Overloaded Polymorphism)

Ad-hoc polymorphism, also known as overloaded polymorphism, is a concept where functions or operators with the same name but different argument lists (types or number of arguments) can be defined. In C++, this is achieved through function and operator overloading.

## Function Overloading

Function overloading allows multiple functions with the same name but different parameter types or different numbers of parameters to be defined.

### Example of Function Overloading

```cpp
#include <iostream>

struct sample1 
{
    private:
        int _nbr; 

    public:
        // Default Constructor 
        sample1(void) : _nbr(0) {}
        // Parametric Constructor 
        sample1(int const n) : _nbr(n) {}
        // Copy Constructor 
        sample1(sample1 const & src) : _nbr(src._nbr) {}
        ~sample1(void) {}

        sample1 & operator=(sample1 const &src) {
            if (this != &src) {
                this->_nbr = src._nbr;
            }
            return *this;
        }

        int getNbr() const {  std::cout << "Test _ String: " << std::endl; return _nbr; }
        void setNbr(int const n) { _nbr = n; }

        void over(int const i) const { std::cout << "Integer: " << i << std::endl; }
        void over(char const i) const { std::cout << "Char: " << i << std::endl; }
        void over(float const i) const { std::cout << "Float: " << i << std::endl; }
        void over(sample1 const &i) const { std::cout << "sample1: " << i.getNbr() << std::endl; }
};

std::ostream & operator<<(std::ostream & o, sample1 const & rhs) {
    o << rhs.getNbr();
    return o;
}

int main() {
    sample1 s1(42);
    sample1 s2(100);

    // Example of function overloading
    s1.over(10);        // Calls the version with int parameter
    s1.over('a');       // Calls the version with char parameter
    s1.over(2.71f);     // Calls the version with float parameter
    s1.over(s2);        // Calls the version with sample1 parameter

    // Example of operator overloading
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    s1 = s2; 
    std::cout << "s1: " << s1 << std::endl;

    return 0;
}
```

## Operator Overloading

Operator overloading allows existing operators (like `+`, `-`, `*`, etc.) to be redefined for user-defined data types. In this example, the output operator `<<` is overloaded for the `sample1` class.

### Example of Operator Overloading

```cpp
std::ostream & operator<<(std::ostream & o, sample1 const & rhs) {
    o << rhs.getNbr();
    return o;
}
```
```cpp
sample1 & operator=(sample1 const &src) {
    if (this != &src) {
        this->_nbr = src._nbr;
    }
    return *this;
}
```

### Using the Operator Overloading in `main`
As seen in the above example, the `<<` operator is used to call the `getNbr` function of `sample1`.
```cpp
    // Example of operator overloading
    std::cout << "s1: " << s1 << std::endl;
    std::cout << "s2: " << s2 << std::endl;
    s1 = s2; 
    std::cout << "s1: " << s1 << std::endl;
```

## Advantages of Ad-hoc Polymorphism

1. **Readability and Maintainability**: 
    Overloading makes code more intuitive and easier to read.
2. **Flexibility**: 
    Similar operations can be grouped under the same name, making the code more flexible and easier to understand.

---