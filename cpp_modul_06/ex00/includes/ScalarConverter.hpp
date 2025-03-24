


# ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include "Generally_Header.hpp"

// # define MAX_INT  std::numeric_limits<int>::max(); //2147483647
// # define MIN_INT  std::numeric_limits<int>::max(); //-2147483648
// # define MAX_DOUBLE  std::numeric_limits<double>::max(); //1.79769e+308
// # define MIN_DOUBLE  std::numeric_limits<double>::max(); //-1.79769e+308
// # define MAX_FLOAT  std::numeric_limits<float>::max(); //3.40282e+38 "3.40282e+38"
// # define MIN_FLOAT  std::numeric_limits<float>::max(); //-3.40282e+38

enum e_datatype
{
  SPECIAL = 0, // -inff ; +inff; nan; nanf
  CHAR = 1,
  INT = 2,
  FLOAT = 3,
  DOUBLE = 4,
  INVALID = -1
};

class ScalarConverter
{
	private:
    std::string _input;
    //std::char _char;
    // Constructor 
    ScalarConverter();
    ScalarConverter(const ScalarConverter& copy);

    // Operater Overload
    ScalarConverter &operator=(const ScalarConverter &src);

    // Deconstructor 
    virtual ~ScalarConverter();
    
  public:

    // Member
    static void convert(const std::string &input);
};

e_datatype Check_datatype(const std::string& str);
std::string deleteLastChar_f(const std::string& str);
void convert_char(const std::string& str);
void convert_int(const std::string& str);
void convert_float(const std::string& input);
void convert_double(const std::string& input);
void convert_special(const std::string& input);
void convert_invalid(const std::string& input);

#endif