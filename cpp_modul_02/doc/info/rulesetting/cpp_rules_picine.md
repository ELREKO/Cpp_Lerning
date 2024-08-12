< [Main](/) | [Lerning](../Lerning/cpp02_00_lerning.md)

--- 
# Rules for Implamantat the C++ Modul
This are the Rules from the mandotoy [subjeckt file](../../PDF/cpp_00_modul_subject.pdf) 

## Compile
- use this flages `-Wall -Wextra -Werror`
- use flag `-std=c++98` --> Only [cpp 98 Standart](cpp_stanard_lib.md) is alowed 

## Formatting 
- exercise folder like `ex00`, `ex01`, `..`
- class names must be wirten in `UpperCamelCase`
	- `ClassName.hpp` -- `hpp` --> Header file
	- `ClassName.tpp` -- `tpp` --> Template Implementation File file
	- `ClassName.cpp` -- `cpp` 
- Output must end by a `newline`
- Goodbye `Norminette`
- Each class should have his ohne header 
- Use [include guards](cpp_rules_include_guards.md)

## Forbinden 
- no external libarys, no `C++11`, no `Boost libraries`, also forbbiden is `printf()`, `alloc()`, `free()`
- `namespace` and **friend keywords** forbidden

## Allowed 
- Standardt libarys in C++
- additional files if is needed

--- 
### Look also

- **[Good Practiec](cpp_rules_good_practice.md)**

- **[Lerning](../Lerning/cpp01_00_lerning.md)**

- **[cpp 98 Standart Libary Headers](cpp_stanard_lib.md)**

- **[Standart cpp 98](../../PDF/std_cpp_98_tutorial.pdf)**

