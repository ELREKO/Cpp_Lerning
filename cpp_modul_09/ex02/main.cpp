#include "include/PmergeMe.hpp"

typedef unsigned long long timestamp_t;

static timestamp_t getTimestampActuell ()
{
	struct timeval now;
	gettimeofday (&now, NULL);
	return  now.tv_usec + (timestamp_t)now.tv_sec * 1000000;
}

int main(int argc, char *argv[])
{
	timestamp_t timeStart, timeEnd;
	int calTimeVec, calTimeDeq;
	std::vector<int> vec;
	std::deque<int> deq;

	// --------------------------------------------Check Arguments -----------------------------------------
	if (!checkArgumentOkay(argc, argv, vec, deq))
		return (1);
	// ---------------------------------------- Step Print for Debugging -----------------------------------
	debugPrintStartLine("Given Number");
	debugPrintLoopContainerValue(vec, "given Vektor:");
	debugPrintLoopContainerValue(deq, "given Deque:");

	// ----------------------------------------- Vektor Sort -----------------------------------------------
	timeStart = getTimestampActuell();
	
	PmergeMe<int, std::vector> classVector;
	std::vector<int> vector_sorted = classVector.sortiern(vec);

	timeEnd = getTimestampActuell();
	calTimeVec = timeEnd - timeStart;
	
	// ----------------------------------------- Deque Sort -----------------------------------------------
	timeStart = getTimestampActuell();
	
	PmergeMe<int, std::deque> classDeque;
	std::deque<int> deque_sorted = classDeque.sortiern(deq);

	timeEnd = getTimestampActuell();
	calTimeDeq = timeEnd - timeStart;

	// ----------------------------------------- Check -----------------------------------------------
	std::vector<int> sorted;
	std::copy(vec.begin(), vec.end(), std::back_inserter(sorted));
	std::sort(sorted.begin(), sorted.end());

	if (sorted.size() != vector_sorted.size() || sorted.size() != deque_sorted.size())
	{
		std::cerr << getColorCode (RED) << "Error: different size" << std::endl;
		return (1);
	}
	for (size_t i = 0; i < sorted.size(); i++)
	{
		if (sorted[i] != vector_sorted[i] || sorted[i] != deque_sorted[i])
		{
			std::cerr << getColorCode (RED) << "Error: bad sort" << std::endl;
			return (1);
		}
	}	

	// -------------------------------------------- Output ---------------------------------------------
	std::cout << getColorCode (RESET) <<"Before: ";
	for (size_t i = 0; i < vec.size(); i++)
		std::cout << vec[i] << " ";
	std::cout << std::endl;
	std::cout << getColorCode(YELLOW) <<"After: ";
	for (size_t i = 0; i < sorted.size(); i++)
		std::cout << sorted[i] << " ";
	std::cout << std::endl;

	std::cout << getColorCode(CYAN)<< "Time to process a range of " << vec.size() << " elements with std::vector : " << calTimeVec << " us" << std::endl;
	std::cout << getColorCode(GREEN)<< "Time to process a range of " << deq.size() << " elements with std::deque  : " << calTimeDeq << " us" << std::endl;
}
