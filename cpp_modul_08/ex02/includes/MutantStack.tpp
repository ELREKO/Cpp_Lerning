#include "MutantStack.hpp"

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack() 
{}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T,  Container> &copy)
{ *this = copy;}

template<typename T, typename Container>
MutantStack<T, Container> &MutantStack<T, Container>::operator=(const MutantStack<T, Container>& src) {
	if (this != &src) {
		this->c = src.c; // Zugriff auf den internen Container von std::stack
	}
	return *this;
}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack()
{}

// template<typename T, typename Container>
// iterator MutantStack<T, Container>::begin() { return this->c.begin(); }
// iterator end() { return this->c.end(); }
// const_iterator begin() const { return this->c.begin(); }
//  const_iterator end() const { return this->c.end(); }