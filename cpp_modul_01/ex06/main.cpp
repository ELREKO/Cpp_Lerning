#include "src/Harl.hpp"

int translate_harl(std::string str)
{
	std::string level[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 1 ; i < 5; i++)
	{
		if (str == level[i - 1])
			return i;
	}
	return 0;
}

int switch_harl(int nbr)
{
	Harl harl;
	while (nbr < 5)
	{
		switch (nbr)
		{
			case 1:
				harl.complain("DEBUG");
				break;
			case 2:
				harl.complain("INFO");
				break;
			case 3:
				harl.complain("WARNING");
				break;
			case 4:
				harl.complain("ERROR");
				break;
			default:
				std::cout << "[ Probably complaining about insignificant problems ]" << std::endl << std::endl;
				return 1;
		}
		nbr++;
	}
	return 0;
}

int main (int arg , char **argv)
{
	if (arg != 2)
	{
	 	std::cout << "Wrong number of Argument given!"  << std::endl;
		return (1);
	}

	return (switch_harl(translate_harl(argv[1])));
}
