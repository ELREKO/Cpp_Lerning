#include "includes/ScalarConverter.hpp"



int main(int argv, char* argc[]) 
{
    if (argv != 2)
    {
        std::cout   << "Please give only one argument as \"char\", \"int\", \"float\" or \"double\""
                    << std::endl;
    }
    else 
    {
        ScalarConverter::convert(argc[1]);  
    }
    
    // Testen mit float werten! 
    // std::string test3 = "3.4e+38"; // Maximaler float-Wert als wissenschaftliche Notation
    // std::string test4 = "1.0e+39"; // Größer als maximaler float-Wert

    // Testen mit double werten! 
    // std::string test3 = "1.79e+308"; // Maximaler double-Wert als wissenschaftliche Notation
    // std::string test4 = "1.79e+309"; // Größer als maximaler double-Wert

    // zum Programmtest nutze die limits z.B.
    // double maxDouble = std::numeric_limits<double>::max()

    return 0;
}