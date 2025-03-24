
# include "../includes/ScalarConverter.hpp"
# include "../includes/Generally_Header.hpp"

static bool isNumber(std::stringstream &ss) 
{
	char c;
	if (!(ss >> c))
	{
		return true;
	}
	return false;
}

std::string deleteLastChar_f(const std::string& str)
{
	if (str[str.length() - 1] == 'f')
		return str.substr(0, str.length() - 1);
	return str;
}

static bool isInt(const std::string& str) 
{
    std::stringstream ss(str);
    int nbr;

	if (ss >> nbr)
	{ 
		size_t dotPos = str.find('.');
    	if (dotPos == std::string::npos)
			return isNumber(ss);
		else 
		{	// check string befor dot and after dot!
			std::stringstream ss1(str.substr(0, dotPos));
			if (ss1 >> nbr)
				if(isNumber(ss1))
				{
					std::stringstream ss2(str.substr(dotPos + 1));
					if (ss2 >> nbr)
						return isNumber(ss2);
				}
		}
	}
	return false;
}

static bool isChar(const std::string& str)
{
	if (isInt(str))
	{
		std::stringstream ss(str);
    	int nbr;
		ss >> nbr;
		if (nbr > -1 && nbr < 128)
			return true;
		else
			return false;
	}
	else if (str.length() == 1)
		return true;
	return false;
}

static bool isFloat(const std::string& str) 
{
	std::stringstream ss(str);
    float nbr;

	if (ss >> nbr)
	{
		if (nbr < std::numeric_limits<float>::max() 
			&& nbr > -std::numeric_limits<float>::max())
		{
			return isNumber(ss);
		}
	}
    return false;
}

static bool isDouble(const std::string& str) 
{
   	std::stringstream ss(str);
    double nbr;

	if (ss >> nbr)
	{
		if (nbr < std::numeric_limits<double>::max() 
			&& nbr > -std::numeric_limits<double>::max())
		{
			return isNumber(ss);
		}
	}
   return false;
}


static bool isInvalid(const std::string& str)
{
	for (std::size_t i = 0; i < str.length(); ++i) 
	{
		if ((int)str[i] < 32 || (int)str[i] >= 127)
			return true;
	}
	return false;
}

e_datatype Check_datatype(const std::string& str)
{
	std::string tmp_string;
	if (	str == "+inff"
		|| 	str == "+inf"
		|| 	str == "-inff"
		|| 	str == "-inf"
		|| 	str == "nan"
		||	str == "nanf")
	{
		return SPECIAL;
	}
	tmp_string = deleteLastChar_f(str);
	if (isChar(tmp_string))
		return CHAR;
	if (isInt(tmp_string))
		return INT;
	if (isFloat(tmp_string))
		return FLOAT;
	if (isDouble(tmp_string))
		return DOUBLE;
	if (isInvalid(tmp_string))
		return INVALID;
	return INVALID;
}








