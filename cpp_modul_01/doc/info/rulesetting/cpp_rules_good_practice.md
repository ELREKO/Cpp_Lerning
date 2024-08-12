< [Back](cpp_rules_picine.md) | [Main](/) | [Lerning](../Lerning/cpp01_00_lerning.md)

---

# C++ Best Practices

## 1. Clarity and Readability

- **Use Descriptive Names:** Choose meaningful names for variables, functions, and classes. Names should reflect the purpose of the code.
  - **Good:** `class Account { ... };`
  - **Bad:** `class A { ... };`

- **Use Constants:** Use `const` or `constexpr` for immutable values to make the code clearer and safer.
  - **Good:** `const int MAX_USERS = 100;`
  - **Bad:** `int max_users = 100;`

## 2. Encapsulation and Modularity

- **Use Getter and Setter Methods:** Access private data members via public getter and setter methods instead of making them public.
  - **Good:** 
    ```cpp
    class Person {
    private:
        std::string _name;

    public:
        std::string getName() const;
        void setName(const std::string& newName);
    };
    ```
  - **Bad:** 
    ```cpp
    class Person {
    public:
        std::string name; // Direct access
    };
    ```

- **Keep Classes and Methods Small:** Ensure classes and methods are focused on a single responsibility.
  - **Good:** `class User { ... };`
  - **Bad:** `class UserManager { ... };` (with too many unrelated methods)

## 3. Memory Management

- **Follow RAII Principle:** Acquire resources in constructors and release them in destructors.
  - **Good:** 
    ```cpp
    class FileManager {
    private:
        std::ifstream _file;

    public:
        FileManager(const std::string& filename) : _file(filename) {}
        ~FileManager() { file.close(); }
    };
    ```
  - **Bad:** Managing resources manually without RAII.

- **Use Smart Pointers:** Use smart pointers like `std::unique_ptr`, `std::shared_ptr` to avoid memory leaks.
  - **Good:** 
    ```cpp
    std::unique_ptr<MyClass> obj = std::make_unique<MyClass>();
    ```
  - **Bad:** `MyClass* obj = new MyClass(); // Manual memory management`
  
## 4. Inheritance and Polymorphism

- **Use `override` Keyword:** Explicitly indicate that a method overrides a base class method.
  - **Good:** 
    ```cpp
    class Base {
    public:
        virtual void foo() { }
    };

    class Derived : public Base {
    public:
        void foo() override { }
    };
    ```
  - **Bad:** `void foo() { }` without `override`.

- **Avoid Multiple Inheritance:** Prefer single inheritance and use interfaces for polymorphism.
  - **Good:** Single inheritance from `Base` class.
  - **Bad:** Multiple inheritance with multiple base classes unless necessary.

## 5. Const Correctness and References

- **Ensure Const Correctness:** Use `const` where applicable to ensure variables and parameters are not modified.
  - **Good:** 
    ```cpp
    void print(const std::string& text);
    ```
  - **Bad:** `void print(std::string text);` (non-const reference)

- **Prefer References over Pointers:** Use references (`&`) where possible to avoid null pointer issues and ensure safer code.
  - **Good:** `void processData(const Data& data);`
  - **Bad:** `void processData(Data* data);`

## 6. Error Handling

- **Use Exceptions:** Handle errors with exceptions (`try`, `catch`) rather than error codes.
  - **Good:** 
    ```cpp
    try {
        doSomething();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    ```
  - **Bad:** `if (!doSomething()) { /* Handle error */ }`

- **Use the Standard Library:** Use STL features like `std::vector`, `std::map`, etc., which are well-tested and optimized.
  - **Good:** `std::vector<int> numbers;`
  - **Bad:** Manual dynamic array management.

## 7. Documentation and Comments

- **Write Clear Comments:** Provide helpful comments but avoid excessive comments that clutter the code.
  - **Good:** 
    ```cpp
    // Increment age by 1
    person.setAge(person.getAge() + 1);
    ```
  - **Bad:** `// Add 1 to the age.` (if the code is self-explanatory)

- **Use Documentation Tools:** Utilize tools like Doxygen for automated documentation generation.
  - **Good:** `/** @brief This method does something. */`
  - **Bad:** Lack of comments or documentation.

## 8. Adhere to Conventions

- **Follow Consistent Style:** Use a consistent coding style for indentation, braces, and naming conventions.
  - **Good:** 
    ```cpp
    class MyClass {
    public:
        void myMethod();
    };
    ```
  - **Bad:** Mixed styles for braces and indentation.

- **Naming Conventions:** Follow consistent naming conventions such as `camelCase` for methods and `snake_case` for variables.
  - **Good:** `void calculateTotal();`
  - **Bad:** `void CalculateTotal();`

## Example Header File with All Access Modifiers

```cpp
#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP

#include <iostream>

class Example {
private:
    int _private_attribute_; // Private access
    void _privateMethod(); // Private access

protected:
    int _protected_attribute_; // Protected access
    void _protectedMethod(); // Protected access

public:
    Example(); // Constructor
    ~Example(); // Destructor
    int public_attribute_; // Public access
    void publicMethod(); // Public access
    void showAttributes() const; // Public access, const method
};

#endif // EXAMPLE_HPP
```
