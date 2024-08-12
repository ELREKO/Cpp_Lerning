< [back](cpp00_02_iostreams.md)| [main](/) | [forward](cpp00_04_initialization_list.md) >

---

# The Main of Using a Class 

The Constructer and Deconstructer doesn't have a `return` value

creat `*.hpp` file 
```c++
# ifndef SAMPLE_CLASS_H
# define SAMPLE_CLASS_H

class sample
{
	private:
	
	public:
		sample(void);
		~sample(void);
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
```
- creat your `main.cpp` and use the class 
```c++
# include "sample.class.cpp"

int main (void)
{
	sample test_samp;
	return (0);
}
```

The output 
```shell
c4b10c3% g++ -Wall -Wextra -Werror test/main.cpp 
c4b10c3% ./a.out 
Using Constructer called
Using Deconstruckter called
```
