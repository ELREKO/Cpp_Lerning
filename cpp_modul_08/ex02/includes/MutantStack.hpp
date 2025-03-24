#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <vector> 
# include <deque>  
# include <list>
# include <typeinfo> 

template<typename T, typename Container = std::deque<T> > // default --> std::deque
class MutantStack : public std::stack<T, Container>
{
public:
    typedef typename std::stack<T, Container>::container_type container_type; // Get the given Container type std::vector; std::list; or std ::deque
    typedef typename container_type::iterator iterator; // withe container_type -> use the iterator of the container 
    typedef typename container_type::const_iterator const_iterator;

    MutantStack() {}
    ~MutantStack() {}
    MutantStack(const MutantStack& copy) 
    { *this = copy;}

    // Zuweisungsoperator
    MutantStack<T, Container>& operator=(const MutantStack<T, Container>& src)
    {
            if (this != &src) 
            {
                this->c = src.c; // Zugriff auf den internen Container von std::stack
            }
        return *this;
    }

    // Iteratoren
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }

    // Funktion zum Ausgeben des Container-Typs
    void printContainerType() const {
        if (typeid(container_type) == typeid(std::vector<T>))
            std::cout << "Underlying container type: vector" << std::endl;
        else if (typeid(container_type) == typeid(std::list<T>))
            std::cout << "Underlying container type: list" << std::endl;
        else if (typeid(container_type) == typeid(std::deque<T>))
            std::cout << "Underlying container type: deque" << std::endl;
        else
            std::cout << "Underlying container type: unknown" << std::endl;
    }

};

//# include "MutantStack.tpp"

#endif
