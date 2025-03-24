# include "../includes/ScalarConverter.hpp"
	

ScalarConverter::ScalarConverter()
{}
ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	*this = copy;
}

    // Operater Overload
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &src)
{
	if (this == &src)
		return (*this);
	return (*this);
}

    // Deconstructor 
ScalarConverter::~ScalarConverter()
{}


void ScalarConverter::convert(const std::string &input)
{
	e_datatype data = Check_datatype(input);
	//Data data = new Data;
	
	switch (data)
	{
	case SPECIAL:
		{
			convert_special(input);
		}
		break;
	case CHAR:
		{
			convert_char(input);
		}
		break;
	case INT:
		{
			convert_int(input);
		}
		break;
	case FLOAT:
		{
			convert_float(input);
		}
		break;
	case DOUBLE:
		{
			convert_double(input);
		}
		break;
	case INVALID:
		{
			convert_invalid(input);
		}
		break;
	default:
		std::cout << "Invalied!" << std::endl;
		break;
	}
}