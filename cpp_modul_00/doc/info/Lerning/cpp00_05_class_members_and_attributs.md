< [back](cpp00_04_initialization_list.md)| [main](/) | [forward](cpp00_06_visibality.md) >

---

# Class - Members and Attributs 

## 1. Class Members 
**Members**of a class are the components defined within the class. They include **data members** (attributes) and **functions** (methods). Here’s a detailed overview of the different types of class members: 

| **Member Type**       | **Description**                                                                              |
| --------------------- | -------------------------------------------------------------------------------------------- |
| **Data Members**      | Variables within a class that hold the state of an object.                                   |
| **Functions**         | Methods within a class that define the behavior of an object.                                |
| **Constructors**      | Special methods called when an object is created to initialize it.                           |
| **Destructors**       | Special methods called when an object is destroyed to release resources.                     |
| **Access Specifiers** | Define the visibility of members: `public`, `protected`, and `private`.                      |
| **Static Members**    | Members that belong to the class itself rather than to any particular instance of the class. |
## 2. Attributes of a Class

**Attributes** are specifically **data members** of a class that store the state of an object. They are variables defined within the class and used by class instances (objects).

- **Example**:
```cpp
`class Person 
{
public:     
	std::string name;  // Attribute    
	int age;           // Attribute
};
```

Here, `name` and `age` are **attributes** of the `Person` class.

## 3. Methods vs. Attributes

- **Methods** (Functions) define **the behavior** of an object.
- **Attributes** (Data Members) define **the state** of an object.

Here’s a comparison between **methods** and **attributes**:

|**Term**|**What Is It?**|**Example**|
|---|---|---|
|**Method**|A function inside a class that defines behavior|`void introduce() {...}`|
|**Attribute**|A variable inside a class that stores state|`std::string name;`|

creat `*.hpp` file 
```c++
# ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class sample
{
	private:
		// Attributes (Data Members)
		int multiplier;
	public:
		sample(void);
		~sample(void);

		int double_int();
		void print (int age);
};

# endif
```

creat `*.cpp` file
```c++
# include <iostream>
# include "sample.class.hpp"

sample::sample (void)

{
	std::cout << "Using Constructer called" << std::endl;
	return ;
}

sample::~sample (void)
{
	std::cout << "Using Deconstruckter called" << std::endl;
	return ;
}

int sample::double_int()
{
	return (multiplier * 2);
}

void sample::print (int age)
{
	std::cout << "given Age is: " << age << std::endl;
}
```

using the class 
```c++
# include "sample.class.cpp"

int main (void)
{
	sample test_samp;
	test_samp.multiplier = 51;
	test_samp.print(test_samp.double_int());
	return (0);
}
```

The output 
```shell
c4b10c3% ./a.out                                
Using Constructer called
given Age is: 102
Using Deconstruckter called
c4b10c3% 
```
