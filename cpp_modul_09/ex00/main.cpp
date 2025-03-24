#include "include/BitcoinExchange.hpp" 

 int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cerr << getColorCode(RED) <<"Error: file Missing file." << getColorCode(RESET) << std::endl;
        return (1);
    }

    try {
        BitcoinCalculator calc("include/data.csv", argv[1]);
        calc.Calculate(',', '|'); 
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
