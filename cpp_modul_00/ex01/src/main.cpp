# include "../includes/phonebook.hpp"

//bool	handle_command(phonebook pbook);

int main()
{
	phonebook 	ph1;
	std::string	str;

	while (str != "EXIT")
	{
		if (std::cin.eof())
		{
			std::cout << std::endl;
			return (0);
		}
		std::cout << "Enter a command > ";
		std::getline(std::cin, str);
		if (str == "ADD")
			ph1.add();
		else if (str == "SEARCH")
		{
			ph1.search();
			std::cin.clear(); // Setzen Sie den EOF-Status zurück
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
	}
	return (0);
}