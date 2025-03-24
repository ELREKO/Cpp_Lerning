

#include "includes/easyfind.hpp"

int main (void)
{
    std::vector<int> vec;
    fillWithRandom(vec, 10, 1, 100);  
    vec.push_back(99);
    //vec.push_back(98);
    std::cout << "Vector: ";
	printContainer(vec);
    std::cout << std::endl;
    tryEasyfind(vec, 99);
    tryEasyfind(vec, 101);
    std::cout << std::endl;

    // std::list<int> lst;
    // fillWithRandom(lst, 10, 1, 200);  
    // lst.push_back(199);
    // std::cout << "List: ";
	// printContainer(lst);
    // std::cout << std::endl;
    // tryEasyfind(lst, 199);
    // tryEasyfind(lst, 201);
    // std::cout << std::endl;

    // std::deque<int> dq;
    // fillWithRandom(dq, 10, 1, 300); 
    // dq.push_back(299);
    // std::cout << "Deque: ";
	// printContainer(dq);
    // std::cout << std::endl;
    // tryEasyfind(dq, 299);
    // tryEasyfind(dq, 301);
    // std::cout << std::endl;
}