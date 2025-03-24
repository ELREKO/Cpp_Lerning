#include "../includes/ScalarConverter.hpp"

static int getPrecision (const std::string& input)
{
	if (input.find('.') == std::string::npos)
		return (0);
	return (input.length() - 1) - (input.find('.'));
}

static void printFloatDouble(double nbr, const std::string& input)
{
	float decimal_Place, floatNbr = static_cast<float>(nbr);
	
	// Callc the Prescison
	if (floatNbr > 0)
		decimal_Place = floatNbr - std::floor(floatNbr);
	else
		decimal_Place = (std::floor(floatNbr) + 1) - floatNbr ;

	//std::cout << floatNbr << " |" << std::floor(floatNbr) + 1 << " | "<< decimal_Place << std::endl;

	// Print the Pricision
	std::string tmp_str = deleteLastChar_f(input);
	if (0 == getPrecision(tmp_str) || 
		((1 == getPrecision(tmp_str)) && tmp_str[tmp_str.length() - 1] == '0') || 
		(decimal_Place < 0.00001))
	{
		std::cout << "float: " <<  floatNbr  << ".0f" << std::endl;
		std::cout << "double: " <<  nbr << ".0" << std::endl;
	}
	else
	{
		std::cout << "float: " <<  floatNbr  << "f" << std::endl;
		std::cout << std::fixed << std::setprecision(getPrecision(tmp_str)) << "double: " <<  nbr  << std::endl;
	}
}

void convert_char(const std::string& input)
{
	std::stringstream ss(input);
	int i;
	if (ss >> i)
	{
		if (i > 31 && i < 127)
			std::cout << "Char: " << static_cast<char>(i)<< std::endl;
		else
			std::cout << "Char: " << "not printable" << std::endl;

		double nbr = std::atof(input.c_str());
		std::cout << "int: " << static_cast<int>(nbr) << std::endl;
		printFloatDouble(nbr, input);
	}
	else 

	{
		std::cout << "Char: " << input[0] << std::endl;
		std::cout << "int: " << static_cast<int>(input[0] ) << std::endl;
		std::cout << "float: " << static_cast<float>(input[0] ) << ".0f" << std::endl;
		std::cout << "double: " <<  static_cast<double>(input[0] ) << ".0" << std::endl;
	}
}

void convert_int(const std::string& input)
{
	double nbr = std::atof(input.c_str());
	std::cout << "Char: " << "impossible" << std::endl;
	std::cout << "int: " << static_cast<int>(nbr) << std::endl;
	printFloatDouble(nbr, input);
	}

void convert_float(const std::string& input)
{
	double nbr = std::atof(input.c_str());
	std::cout << "Char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	printFloatDouble(nbr, input);
}

void convert_double(const std::string& input)
{
	double nbr = std::atof(input.c_str());
	std::cout << "Char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	std::cout << "float: " << "impossible"  << std::endl;
	std::cout << std::fixed << std::setprecision(getPrecision(input)) << "double: " << nbr  << std::endl;
}

void convert_special(const std::string& input)
{
	std::cout << "Char: " << "impossible" << std::endl;
	std::cout << "int: " << "impossible" << std::endl;
	if (input == "nan" || input == "nanf")
	{
		std::cout << "float: nanf" <<  std::endl;
		std::cout << "double: nan"<< std::endl;
	}
	if (input == "+inf" || input == "+inff")
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf"<< std::endl;
	}
	if (input == "-inf" || input == "-inff")
	{
		std::cout << "float: -inff" <<   std::endl;
		std::cout << "double: -inf"<< std::endl;
	}
}

void convert_invalid(const std::string& input)
{
	std::cout << "\"" << input << "\" -> Invalid input" << std::endl;
}
