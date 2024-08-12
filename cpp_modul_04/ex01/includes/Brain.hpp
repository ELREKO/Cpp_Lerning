#include <string>
#include <iostream>
#include <stdexcept>
#include "../../lib/console_setting/color.h"

# define MAX_IDEAS 100

# ifndef BRAIN_HPP
# define BRAIN_HPP

class Brain
{
private: 
	std::string _ideas[MAX_IDEAS];

public:
	// Constructor 
	Brain();
	Brain(const Brain &copy);
	
	// operator Overload
	Brain &operator=(const Brain &src);

	// Deconstructor
	virtual ~Brain();

	// Getter 
	std::string getIdea(unsigned int nbr) const;

	// Setter
	void setIdea(unsigned int nbr, const std::string idea); 

};

#endif


