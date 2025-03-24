#ifndef PMERGEME_CLASS_H
# define PMERGEME_CLASS_H

# include <iostream>
# include <sstream>
# include <vector>
# include <deque>
# include <algorithm>
# include <sys/time.h>
# include <cstring>
# include <limits>

# define DEBUG_PRINT false 

enum printColor {
    RED = 31,   
    GREEN = 32,  
    YELLOW = 33,
    BLUE = 34,  
	MAGENTA = 35,
	CYAN = 36, 
	GTAY = 30,
	WHITE = 37,
    RESET = 0  
};

template<typename T, template <typename, typename> class Container>
class PmergeMe 
{
public:
	PmergeMe<T, Container>(void);
	PmergeMe<T, Container>(const PmergeMe<T, Container> &copy);
	~PmergeMe<T, Container>(void);
	PmergeMe<T, Container>	&operator =(const PmergeMe<T, Container> &src);

	Container<T, std::allocator<T> > sortiern(const Container<T, std::allocator<T> > &givenContainer) ;

private:
	Container<std::pair<T, T>, std::allocator<T> > MergeLeftRight(Container<std::pair<T, T>, std::allocator<T> > leftSide, Container<std::pair<T, T>, std::allocator<T> > rightSide, int recusionCount);
	Container<std::pair<T, T>, std::allocator<T> > SortPairs(Container<std::pair<T, T>, std::allocator<T> > &containerOfPairs, int recusionCount);
	Container<T, std::allocator<T> > BinarySearchInsertion(Container<T, std::allocator<T> > &contain, size_t start, T insertNum);

};



template <typename T>
bool ReservePlace(T &container, typename T::size_type size);
template <typename T, typename U>
bool ReservePlace(std::vector<T, U> &container, typename std::vector<T, U>::size_type size);

// Print Funktion see at the end of the template for debugging 
void debugPrintBeschreibung(std::string beschreibung, printColor color, bool BOLD);
void debugPrintStartLine(std::string Beschreibung);
void debugPrintEndLine();
template<typename T, template <typename, typename> class Container>
void debugPrintLoopContainerValue(const Container<T, std::allocator<T> > &container, std::string beschreibung);
template<typename T, template <typename, typename> class Container>
void debugPrintLoopContainerOfPairsValue(const Container<std::pair<T, T>, std::allocator<T> > &containerOfPairs, std::string beschreibung);

template <typename Container1, typename Container2>
bool checkArgumentOkay(int argc, char *argv[], Container1& vec, Container2 &deq);

#include "../src/PmergeMe.tpp"

#endif
