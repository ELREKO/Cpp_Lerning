template <typename T>
typename T::iterator easyfind(T& container, int value)
{
		typename T::iterator ite =  container.end();
		for (typename T::iterator it = container.begin(); 
			it != ite; ++it )
		{
			if (value == (*it)) // Maybe use static_cast<int>(*it) --> to be sure thats a int 
				return (it);
		}
		throw NotFoundException();
		
		// // Use Algorithm

		// typename T::iterator itee = std::find(container.begin(), container.end(), value);
		// if (itee == container.end()) {
		// 	throw NotFoundException();
		// }
		// return itee;
}

template <typename T>
void tryEasyfind(T& container, int value)
{
	try
	{
		typename T::iterator ef = easyfind(container, value);
		int position = std::distance(container.begin(), ef);
		std::cout << "found: " << *ef << " at position: " << position <<" !" << std::endl;
	}
	catch(NotFoundException &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

// fill a Container with a Random Number
template <typename T>
void fillWithRandom(T& container, int max_nbr, int minValue = 0, int maxValue = 100) {
    srand(static_cast<unsigned int>(time(0)));

    for (int i = 0; i < max_nbr; ++i) {
        int randomValue = minValue + rand() % (maxValue - minValue + 1);  // Zufallszahl im Bereich [minValue, maxValue]
        container.insert(container.end(), randomValue);  // Fügt eine Zufallszahl am Ende ein
    }
}

// print Container 
template <typename T>
void printContainer(T& container)
{
	typename T::iterator ite =  container.end();
		for (typename T::iterator itb = container.begin(); 
			itb != ite; ++itb )
		{
			std::cout << *itb << " "; // std::endl;
		}
}





