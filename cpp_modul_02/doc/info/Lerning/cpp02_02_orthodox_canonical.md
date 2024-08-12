<[back](cpp02_01_polymorphisen.md) | [main](/) | [forward](cpp02_00_lerning.md) >

--- 

# Orthodox Canonical Class Form

## Minimum Required Components of an Orthodox Canonical Class

1. **Default Constructor**
   --> Initializes a new object.
2. **Copy Constructor**
   --> Creates a copy of the object.
3. **Copy Assignment Operator**
   --> Assignment from one object to another.
4. **Destructor**
   --> Releases resources when the object is destroyed.
5. **Move Constructor**
   --> Transfers resources from one object to another.

6. **Move Assignment Operator**
   --> Assignment from an rvalue object to another.

## Example:
```c++
#include <iostream>
#include <string>

// Person class definition (same as before)
class Person
{
    private:
        std::string _name; // name of the person
        int _age; // age of the person
    public:
        // default constructor
        Person() : _name(""), _age(0) {}

        // copy constructor
        Person(const Person& other) : _name(other._name), _age(other._age) {}

        // assignment operator
        Person& operator=(const Person& other)
        {
            if (this != &other)
            { // avoid self-assignment
                _name = other._name;
                _age = other._age;
            }
            return *this;
        }

        // destructor
        ~Person() {}

        // move constructor
        Person(Person&& other) noexcept : _name(std::move(other._name)), _age(other._age) {}

        // move assignment operator
        Person& operator=(Person&& other) noexcept
        {
            if (this != &other)
            { // avoid self-assignment
                _name = std::move(other._name);
                _age = other._age;
            }
            return *this;
        }

        // method to print Person details
        void print() const
        {
            std::cout << "Name: " << _name << ", Age: " << _age << std::endl;
        }
};

int main()
{
    // Default constructor
    Person p1;
    std::cout << "Person p1: ";
    p1.print();

    // Parameterized constructor (assuming you might want to add this)
    Person p2;
    // For demonstration purposes, we'll set values directly
    // In practice, you would use a parameterized constructor or setter methods
    p2 = Person();
    std::cout << "Person p2 (after assignment): ";
    p2.print();

    // Copy constructor
    Person p3(p1);
    std::cout << "Person p3 (copied from p1): ";
    p3.print();

    // Copy assignment operator
    Person p4;
    p4 = p2;
    std::cout << "Person p4 (assigned from p2): ";
    p4.print();

    // Move constructor
    Person p5(std::move(p3));
    std::cout << "Person p5 (moved from p3): ";
    p5.print();
    std::cout << "Person p3 (after move): ";
    p3.print(); // p3 should be in a valid but empty state

    // Move assignment operator
    Person p6;
    p6 = std::move(p5);
    std::cout << "Person p6 (assigned from p5): ";
    p6.print();
    std::cout << "Person p5 (after move assignment): ";
    p5.print(); // p5 should be in a valid but empty state

    return 0;
}
```

## Compare **Copy Constructor** and **Move Constructor**

| **Property**                     | **Copy Constructor**                                   | **Move Constructor**                                    |
|---------------------------------|--------------------------------------------------------|---------------------------------------------------------|
| **Definition**                  | Creates a new copy of an existing object.             | Transfers resources from a temporary object to a new object. |
| **Used For**                    | Non-temporary objects when a complete copy is needed. | Temporary objects (rvalues) to efficiently take over resources. |
| **Resource Management**         | Copies all resources.                                | Takes over resources without copying them.             |
| **Performance**                 | Can be costly, especially with large or complex resources. | Typically faster, as only pointers or handles are transferred. |
| **State of Source Object**      | The source object remains unchanged and has its own copy of the resources. | The source object is left in a valid but empty state (usually `nullptr`). |
| **Copy Overhead**               | Requires a complete copy of the data.                 | Requires no data copy, only transfer of pointers.      |
| **Advantages**                  | - Ensures that each instance has its own copy of resources. <br> - Safe, as no unexpected side effects occur from transferring resources. | - Higher performance with large data or complex resources. <br> - Avoids unnecessary copies and reduces memory usage. |
| **Disadvantages**               | - Can be expensive, especially with large data sets. <br> - Additional memory overhead due to resource copying. | - The source object may be left in an undefined state, which must be handled safely. <br> - Not all classes are implemented to be safely movable. |

## Compare **Copy Assignment Operator** and **Move Assignment Operator**

| **Property**                     | **Copy Assignment Operator**                           | **Move Assignment Operator**                             |
|---------------------------------|--------------------------------------------------------|----------------------------------------------------------|
| **Definition**                  | Assigns the values of one object to an existing object by creating a copy of the resources. | Assigns the resources of a temporary object to an existing object without copying them. |
| **Used For**                    | When assigning the values of one object to an already existing object. | When assigning the resources of a temporary object to an existing object. |
| **Resource Management**         | Copies all resources of the source object.            | Takes over the resources of the source object and leaves the source object in a defined but empty state. |
| **Performance**                 | Can be costly, as all resources need to be copied.    | Typically faster, as only pointers or handles are transferred. |
| **State of Source Object**      | The source object remains unchanged and still has its resources. | The source object is left in a valid but empty state (usually `nullptr`). |
| **Copy Overhead**               | Requires a complete copy of the data.                 | Requires no data copy, only transfer of pointers.       |
| **Advantages**                  | - Ensures that all resources are fully copied. <br> - Safe, as no unexpected side effects occur from transferring resources. | - Higher performance with large data or complex resources. <br> - Avoids unnecessary copies and reduces memory usage. |
| **Disadvantages**               | - Can be expensive, especially with large data sets. <br> - Additional memory overhead due to resource copying. | - The source object may be left in an undefined state, which must be handled safely. <br> - Not all classes are implemented to be safely movable. |