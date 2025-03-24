#include "../include/PmergeMe.hpp"

template<typename T, template <typename, typename> class Container>
PmergeMe<T, Container>::PmergeMe(void)
{
	//std::cout << "Construkter! Pergme" << std::endl; 
}

template<typename T, template <typename, typename> class Container>
PmergeMe<T, Container>::PmergeMe(const PmergeMe<T, Container> &copy)
{
	*this = copy;
}

template<typename T, template <typename, typename> class Container>
PmergeMe<T, Container>::~PmergeMe(void)
{
	//std::cout << "Deconstruct! Pergme" << std::endl; 
}

template<typename T, template <typename, typename> class Container>
PmergeMe<T, Container>	&PmergeMe<T, Container>::operator =(const PmergeMe<T, Container> &src)
{
	if (this != &src)
		*this = src;
	return *this;
}

template <typename T>
bool ReservePlace(T &container, typename T::size_type size)
{
	(void) container;
	(void) size;
	return false;
}


template <typename T, typename U>
bool ReservePlace(std::vector<T, U> &container, typename std::vector<T, U>::size_type size)
{
	container.reserve(size);
	return true;
}

template<typename T, template <typename, typename> class Container>
Container<std::pair<T, T>, std::allocator<T> > PmergeMe<T, Container>::MergeLeftRight(Container<std::pair<T, T>, std::allocator<T> > leftSide, Container<std::pair<T, T>, std::allocator<T> > rightSide, int recusionCount)
{
	Container<std::pair<T, T>, std::allocator<T> > returnContainerOfPairs;
	ReservePlace(returnContainerOfPairs, rightSide.size() + rightSide.size());


	debugPrintStartLine("");
	if (DEBUG_PRINT)
		std::cout << "Beginn merge  " << recusionCount << " given Parameter: " << std::endl;
	debugPrintLoopContainerOfPairsValue(leftSide, "first: ");
	debugPrintLoopContainerOfPairsValue(rightSide, "second: ");

	//Compare first pair element add to new return Container and delet this element
	while (leftSide.size() && rightSide.size())
	{
		if (leftSide[0].first < rightSide[0].first)
		{
			returnContainerOfPairs.push_back(leftSide[0]);
			leftSide.erase(leftSide.begin()); 
		}
		else
		{
			returnContainerOfPairs.push_back(rightSide[0]);
			rightSide.erase(rightSide.begin()); 
		}
	}
	
	// In Case on side is bigger the the other side 
	// Add the last emement! 
	while (leftSide.size())
	{
		returnContainerOfPairs.push_back(leftSide[0]);
		leftSide.erase(leftSide.begin()); 
	}
	while (rightSide.size())
	{
		returnContainerOfPairs.push_back(rightSide[0]);
		rightSide.erase(rightSide.begin()); 
	}

	//Debuging debugPrint
	debugPrintLoopContainerOfPairsValue(returnContainerOfPairs, "Resualt Merge: ");
	debugPrintEndLine();
	
	return (returnContainerOfPairs);
}

template<typename T, template <typename, typename> class Container>
Container<std::pair<T, T>, std::allocator<T> > PmergeMe<T, Container>::SortPairs(Container<std::pair<T, T>, std::allocator<T> > &containerOfPairs, int recusionCount)
{
	recusionCount++;

	if (containerOfPairs.size() <= 1)
		return (containerOfPairs);
	
	Container<std::pair<T, T>, std::allocator<T> > resualtContainer;
	//Div right an left side
	Container<std::pair<T, T>, std::allocator<T> > rightSide;
	std::copy(	containerOfPairs.begin() + containerOfPairs.size() / 2, 
				containerOfPairs.end(), 
				std::back_inserter(rightSide)
			);
	Container<std::pair<T, T>, std::allocator<T> > leftSide;
	std::copy(	containerOfPairs.begin(), 
				containerOfPairs.begin() + containerOfPairs.size() / 2, 
				std::back_inserter(leftSide)
			);

	resualtContainer = MergeLeftRight(SortPairs(leftSide, recusionCount), SortPairs(rightSide, recusionCount),recusionCount);

	return (resualtContainer);
}

template<typename T, template <typename, typename> class Container>
Container<T, std::allocator<T> > PmergeMe<T, Container>::BinarySearchInsertion(Container<T, std::allocator<T> > &contain, size_t start, T insertNum) 
{
	// if container ist empty
	if (contain.size() == 0)
	{
		contain.push_back(insertNum);
		return (contain);
	}

	size_t left = start;
	size_t right = contain.size() - 1;

	bool startPosition = contain[left] > insertNum;

	while (left <= right && !startPosition)
	{
		size_t middle = (left + right) / 2;
		if (left == right)
		{
			if (contain[middle] < insertNum)
				left = middle + 1;
			break;
		}
		else if (contain[middle] < insertNum)
			left = middle + 1;
		else
			right = middle - 1;
	}
	if (left > contain.size() - 1)
		contain.insert(contain.end(), insertNum);
	else
		contain.insert(contain.begin() + left, insertNum);

	debugPrintStartLine("");
	if (DEBUG_PRINT)
		std::cout << "Inserting " << insertNum << " at position " << left << " (after " << contain[left - 1] << ")" << std::endl;
	return (contain);
}

template<typename T, template <typename, typename> class Container>
Container<T, std::allocator<T> > PmergeMe<T, Container>::sortiern(const Container<T, std::allocator<T> > &givenContainer) 
{
	if (givenContainer.size() < 2)
		return givenContainer;

	bool isOdd = givenContainer.size() % 2 != 0;
	Container<std::pair<T, T>, std::allocator<T> > pairsContain;
	ReservePlace(pairsContain, givenContainer.size() / 2 + 1);
	for (typename Container<T, std::allocator<T> >::size_type i = 0; i < givenContainer.size(); i+=2)
	{
		if (i + 1 >= givenContainer.size())
			continue; // ignore the last odd element
		else if (givenContainer[i] > givenContainer[i + 1])
			pairsContain.push_back(std::make_pair(givenContainer[i + 1], givenContainer[i]));
		else
			pairsContain.push_back(std::make_pair(givenContainer[i], givenContainer[i + 1]));
	}

	//Debuging Print
	debugPrintEndLine();
	debugPrintBeschreibung("1. Create Pairs", RED, true);
	debugPrintStartLine("");
	debugPrintLoopContainerOfPairsValue(pairsContain, "Create Pairs and sort the pairs: ");
	debugPrintEndLine();
	debugPrintBeschreibung("2. Divide the Container in to a left and right side ", MAGENTA, true);
	debugPrintBeschreibung("   Use recorsive till last is a resualt of 2 pairs  ", MAGENTA, true);
	debugPrintBeschreibung("   For Example: 16 values -> 8 Pairs -> Group 4/4 pairs -> Group 2/2 pairs -> Group 1/1 pairs GLEICH 3 Recursion!", MAGENTA, true);

	Container<std::pair<T, T>, std::allocator<T> > pairsContainSorted = SortPairs(pairsContain, 0);
	
	debugPrintBeschreibung("3. We get a sorted Container of Pairs", YELLOW, true);
	debugPrintStartLine("");
	debugPrintLoopContainerOfPairsValue(pairsContainSorted, "Sorted pairs for the first number: ");
	debugPrintEndLine();

	Container<T, std::allocator<T> > mainChain;
	Container<T, std::allocator<T> > pend;
	ReservePlace(mainChain, givenContainer.size());
	for (typename Container<T, std::allocator<T> >::size_type i = 0; i < pairsContainSorted.size(); i++)
	{
		mainChain.push_back(pairsContainSorted[i].first);
		pend.push_back(pairsContainSorted[i].second);
	}

	//Debuging debugPrint
	debugPrintBeschreibung("4. Split this container of pairs in a to container \"Main Chain\" and a \"Pend Chain\"", BLUE, true);
	debugPrintBeschreibung("   The \"Main Chain\" is sorted! -> the Pend insert", BLUE, true);
	debugPrintStartLine("");
	debugPrintLoopContainerValue(mainChain, "Main Chain (first Nummer from Pairs)");
	debugPrintLoopContainerValue(pend, "Pend Chain (second Nummer from Pairs)");
	debugPrintEndLine();
	debugPrintBeschreibung("5. Insert the values from pend into the \"Main Chain\" ", GREEN, true);
	debugPrintBeschreibung("   In a Loop divide the main Chain in the middle left and right part  ", GREEN, true);
	debugPrintBeschreibung("   Compare the middle value with insert number ", GREEN, true);

	if (isOdd)
		BinarySearchInsertion(mainChain, 0, givenContainer.back());
	debugPrintLoopContainerValue(mainChain, "New mainChain: ");

	for (typename Container<T, std::allocator<T> >::size_type i = 0; i < pairsContainSorted.size(); i++)
	{
		BinarySearchInsertion(mainChain, i+1, pend[0]);
		pend.erase(pend.begin()); 
		debugPrintLoopContainerValue(mainChain, "New mainChain: ");
	}

	debugPrintEndLine();
	return mainChain;
}

//--------------------------------------------------------------------------------------------------------------
//-------------------------------------------------- DEBUG PRINT -----------------------------------------------
//--------------------------------------------------------------------------------------------------------------

std::string getColorCode(printColor color) {
    std::ostringstream oss;
    oss << "\033[" << color << "m";
    return oss.str();
}

void debugPrintBeschreibung(std::string beschreibung, printColor color, bool BOLD)
{
	if (DEBUG_PRINT)
	{
		std::string newString = ""; 
		if (BOLD)
			newString=newString + "\033[1m";
		if (!beschreibung.empty())
			std::cout << newString << getColorCode(color) <<beschreibung << getColorCode(RESET)  << std::endl;
	}
}

void debugPrintStartLine(std::string beschreibung)
{
	if (DEBUG_PRINT)
	{
		std::cout 	<< " --------------------------- "  << std::endl;
		debugPrintBeschreibung(beschreibung, RESET, false);
	}
	return;
}

void debugPrintEndLine()
{
	if (DEBUG_PRINT)
		std::cout 	<< " =========================== "  << std::endl;
	return;
}

template<typename T, template <typename, typename> class Container>
void debugPrintLoopContainerValue(const Container<T, std::allocator<T> > &container, std::string beschreibung)
{
	if (DEBUG_PRINT)
	{
		debugPrintBeschreibung(beschreibung, RESET, false);
		for (typename Container<T, std::allocator<T> >::size_type i = 0; i < container.size(); i++)
			std::cout << container[i] << ", ";
		std::cout  << std::endl;
	}
	return;
}

template<typename T, template <typename, typename> class Container>
void debugPrintLoopContainerOfPairsValue(const Container<std::pair<T, T>, std::allocator<T> > &containerOfPairs, std::string beschreibung)
{
	if (DEBUG_PRINT)
	{
		debugPrintBeschreibung(beschreibung, RESET, false);
		for (typename Container<T, std::allocator<T> >::size_type i = 0; i < containerOfPairs.size(); i++)
			std::cout << "[" << containerOfPairs[i].first << ", " << containerOfPairs[i].second << "], ";
		std::cout  << std::endl;
	}
	return;
}

// ---------------------------------------------------------------------------------------------------------
// ------------------------------------------------- Check Arguments! --------------------------------------
// ---------------------------------------------------------------------------------------------------------


// Check for Duplikate
template <typename Container>
bool addToContainer(Container& container, int num) {
    if (std::find(container.begin(), container.end(), num) != container.end()) {
        std::cerr << getColorCode (RED) << "ERROR: Number " << num << " Duplicate.\n";
        return false;
    }

    container.push_back(num);
    return true;  
}

template <typename Container1, typename Container2>
bool checkArgumentOkay(int argc, char *argv[], Container1& vec, Container2 &deq)
{
if (argc < 2) 
	{
        std::cerr << getColorCode (RED) << "Fehler: Bitte geben Sie eine Liste von Zahlen als Argumente an.\n";
        return (1);
    }

    for (int i = 1; i < argc; ++i)
	{
        int num;
        std::stringstream ss(argv[i]);

		while (ss>>num)
		{
			// std::cout << num << std::endl;
			if (num < 0)
			{ 	
				
				std::cerr << getColorCode (RED) << "ERROR: Number must be postiv: " << num << "\n";
				return false; 
			}
			
			// Check Duplicate
			if (!addToContainer(vec, num) ||
				!addToContainer(deq, num))
					return false;
			
		}
		// Report -> while condition fail! 
		if (!ss.eof()) 
		{
			std::string rest;
			ss.clear(); 
			ss>>rest;
			if (!rest.empty())
			{
				std::cout << getColorCode(RED) << "ERROR: Fail argument! --> | " << rest << getColorCode(RESET) << std::endl;
				return false;
			}
		}
	}
	return true;
}

