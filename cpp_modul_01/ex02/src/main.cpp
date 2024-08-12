#include <iostream>
#include <string>

int main() {
    std::string str = "HI THIS IS BRAIN";

    std::string* stringPTR = &str;
    std::string& stringREF = str;


    std::cout << std::endl;
    std::cout << "Memory address of the string variable: " << &str << std::endl;
    std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;
    
    std::cout << std::endl;
    std::cout << "Memory address of the string variable: " << str << std::endl;
    std::cout << "Memory address held by stringPTR: " << *stringPTR << std::endl;
    std::cout << "Memory address held by stringREF: " << stringREF << std::endl;
    std::cout << std::endl;
    return 0;
}