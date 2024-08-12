# include "../includes/Brain.hpp"

Brain::Brain()
{
	std::cout << BACKGROUND_BLUE << "Call Constructor Brain" << RESET << std::endl;
}

Brain::Brain(const Brain &copy)
{
	for (int i = 0; i < MAX_IDEAS; i++)
	{
		setIdea(i, copy.getIdea(i));
	}
}

Brain &Brain::operator=(const Brain &src)
{
	if (this != &src)
	{
		for (int i = 0; i < MAX_IDEAS; i++)
		{
			setIdea(i, src.getIdea(i));
		}
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << BACKGROUND_BLUE << "Deconstructor Brain" << RESET << std::endl;
}

std::string Brain::getIdea(unsigned int nbr) const
{
	if (nbr >= MAX_IDEAS)
	{
		std::cout << UNDERLINE << "Error: getIdeas --> given number \"" << nbr << "\" to big" << RESET << std::endl;
		return "";
	}
	return this->_ideas[nbr];
}

void Brain::setIdea(unsigned int nbr, const std::string idea)
{
	if (nbr >= MAX_IDEAS)
	{
		std::cout << "Error: setIdea --> given number \"" << nbr << "\" to big" << RESET << std::endl;
		return ;
	}
	this->_ideas[nbr] = idea;
}

