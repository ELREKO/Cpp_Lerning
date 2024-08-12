< [back](cpp00_06_visibality.md)| [main](/) | [forward](cpp00_08_non_membe_non_attribute.md) >

---


# Understanding `this->` in C++

In C++, the `this` keyword is a special pointer that refers to the current object. The `this->` syntax is used to access the members of the object from within its own methods. 

## What is `this`?

In C++, `this` is an **implicit pointer** that refers to the current object of the class. It allows access to the object's members (attributes and methods).

## Syntax

```cpp
this->member
```

Here, `member` refers to an attribute or a method of the class.

## Why Use `this->`?

The `this` keyword and the `this->` syntax are used for several reasons:

1. **Accessing Data Members and Methods**:
   - Sometimes, it is necessary to explicitly access the current object, especially in cases of name conflicts or within templates.

2. **Distinguishing Between Member Variables and Parameters**:
   - When a parameter has the same name as a class data member, `this->` can be used to clarify that you are referring to the data member and not the parameter.

3. **Returning the Current Object**:
   - `this` can be used to return the current object itself, which is useful in methods for fluent interfaces or method chaining.

4. **Accessing Template Members**:
   - Within templates, `this->` is used to access members of the template, as the compiler handles the visibility of template member names differently.

## Examples of `this->`

### 1. **Accessing Data Members and Methods**

```cpp
class Example {
private:
    int value;

public:
    void setValue(int value) {
        this->value = value; // Here, `this->` is used to refer to the data member `value`
    }

    int getValue() {
        return this->value; // Alternatively, `value` alone could also be used
    }
};
```

In this example, `this->value` ensures that the data member `value` is referenced rather than the parameter `value`.

### 2. **Using in Templates**

```cpp
template <typename T>
class Container {
public:
    void display() {
        this->print(); // Here, `this->` is necessary to access the `print` method
    }

    void print() {
        // Print something
    }
};
```

In templates, `this->print()` is required to access the `print` method as a member of the `Container` class.

### 3. **Returning the Current Object**

```cpp
class FluentInterface {
public:
    FluentInterface& setValue(int value) {
        this->value = value; // Sets the `value` attribute
        return *this; // Returns the current object for method chaining
    }

    FluentInterface& incrementValue() {
        this->value++;
        return *this; // Returns the current object for method chaining
    }

private:
    int value;
};
```

Here, `setValue` and `incrementValue` methods enable method chaining by returning the current object.

## `this->` in Different Contexts

| **Context**            | **Usage**                                                                                  | **Example**                                                                                       |
|------------------------|--------------------------------------------------------------------------------------------|---------------------------------------------------------------------------------------------------|
| **Data Members**      | Disambiguate between parameters and class attributes.                                    | `this->value = value;` (Assigning a parameter to a data member)                                  |
| **Method Calls**      | Call methods within the class.                                                             | `this->print();` (Calling a method within the class)                                             |
| **Templates**         | Access template members.                                                                    | `this->templateMethod();` (Accessing a method defined in a template)                             |
| **Method Chaining**   | Return the current object for fluent interfaces.                                          | `return *this;` (Returning the current object for method chaining)                               |

### Example Applications

Here are some additional examples that use `this->` in different situations:

```cpp
class Rectangle {
public:
    // Parameter and attribute have the same name
    void setWidth(int width) {
        this->width = width; // Differentiates between the parameter `width` and the data member `width`
    }

    int getWidth() {
        return this->width; // Accesses the `width` data member
    }

    // Fluent Interface Example
    Rectangle& setHeight(int height) {
        this->height = height; // Sets the `height` attribute
        return *this; // Allows method chaining
    }

    Rectangle& setWidthAndHeight(int width, int height) {
        this->width = width;   // Sets the `width` attribute
        this->height = height; // Sets the `height` attribute
        return *this;          // Allows method chaining
    }

private:
    int width;
    int height;
};
```

In this example, `width` and `height` are **attributes** of the `Rectangle` class, and `setWidth`, `getWidth`, `setHeight`, and `setWidthAndHeight` are **methods**.

## Summary

Here’s an overview of the `this->` keyword and its uses:

| **Keyword** | **Description**                                                                                                  |
|-------------|------------------------------------------------------------------------------------------------------------------|
| `this`      | An implicit pointer that refers to the current object of the class.                                             |
| `this->`    | Explicitly accesses members (data or methods) of the class from within its methods.                              |

### Key Points

- **`this`**: Refers to the current object within the class.
- **`this->`**: Used for accessing class members, resolving name conflicts, in templates, and for method chaining.


