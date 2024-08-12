< [back](cpp00_00_lerning.md)| [main](/) | [forward](cpp00_02_iostreams.md) >

---
# namespace

You know the `struckt`' s and `enum` in C. Namespace are more nicer than this both.
### Key Differences

1. **Namespace vs. Struct**:
    
    - **Namespace**: Organizes code into logical groups, prevents name collisions, can contain variables, functions, classes, and other namespaces.
    - **Struct**: Groups different data types into a single entity, useful for modeling complex data structures.
2. **Namespace vs. Enum**:
    
    - **Namespace**: Can contain a variety of members (variables, functions, classes), helps in preventing name conflicts.
    - **Enum**: Defines a type consisting of a set of named integral constants, useful for creating a set of related named values.
3. **Struct vs. Enum**:
    
    - **Struct**: Can contain multiple variables of different types.
    - **Enum**: Contains a set of named integral constants.

## Example 

```c++
# include <stdio.h>

int g_var = 1;
int f(void) {return 2;}

namespace n_max
{
	int g_var = 2;
	int f(void) {return 3;}
}

namespace n_elisa
{
	int g_var = 3;
	int f(void) {return 4;}
}

namespace n_andrea
{
	int g_var = 4;
	int f(void) {return 5;}
}

namespace n_kaey
{
	int g_var = 5;
	int f(void) {return 6;}
}

namespace n_kathrina
{
	int g_var = 6;
	int f(void) {return 7;}
}

namespace n_martin
{
	int g_var = 7;
	int f(void) {return 8;}
}

int main(void)
{
	printf("global var: [%d]\n", g_var);
	printf("global return: [%d]\n\n", f());
	  
	printf("global var: [%d]\n", ::g_var);
	printf("global return: [%d]\n\n", ::f());
	
	printf("global var max: [%d]\n", n_max::g_var);
	printf("global return max: [%d]\n\n", n_max::f());
	
	printf("global var elisa: [%d]\n", n_elisa::g_var);
	printf("global return elisa: [%d]\n\n", n_elisa::f());
	
	printf("global var andrea: [%d]\n", n_andrea::g_var);
	printf("global return andrea: [%d]\n\n", n_andrea::f());
	
	printf("global var kaey: [%d]\n", n_kaey::g_var);
	printf("global return kaey: [%d]\n\n", n_kaey::f());
	
	printf("global var kathrina: [%d]\n", n_kathrina::g_var);
	printf("global return kathrina: [%d]\n\n", n_kathrina::f());
	
	printf("global var martin: [%d]\n", n_martin::g_var);
	printf("global return martin: [%d]\n\n", n_martin::f());
	
	return (0); 
}
```