#ifndef EASYFINDER_HPP
#define EASYFINDER_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm> // für std::find
#include <exception>
#include <ctime>
#include <cstdlib> 

class NotFoundException : public std::exception 
{
	public: 
		const char* what() const throw()
		{
			return "value not in the container!";
		}
};

#include "easyfind.tpp"

#endif