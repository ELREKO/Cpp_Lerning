#include "../includes/span.hpp"
		
Span::Span() {}

Span::Span(unsigned int N) : _max_size(N) {}

Span::~Span() {}

Span::Span(const Span &copy)
{
	*this = copy;
}

Span &Span::operator=(const Span &src)
{
	if (this != &src)
	{
		this->_max_size = src._max_size;
		this->_vec_number = src._vec_number;
	}
	return (*this);
}

bool Span::checkVecFull()
{
	if (this->_vec_number.size() >= this->_max_size)
	{
		throw std::out_of_range("Span is full!");
		return false;
	}
	return true;
}

void Span::addNumber(int nbr)
{
	try
	{
		if (checkVecFull())
			this->_vec_number.push_back(nbr);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}


int Span::shortestSpan() const
{
	int min;
	int span;
	if (this->_vec_number.size() < 2)
		throw std::logic_error("Not enough Elements!");
	min = std::numeric_limits<int>::max();
	for (size_t i = 0; i < this->_vec_number.size(); ++i)
	{
		for (size_t j = i + 1; j < this->_vec_number.size(); ++j)
		{
			span = std::abs(this->_vec_number[j] - this->_vec_number[i]);
			if(span < min)
			{
				min = span;
			}
		}
	}
	return min;
}

int Span::longestSpan() const
{

	if (this->_vec_number.size() < 2)
		throw std::logic_error("Not enough Elements!");
	int maxNbr = this->_vec_number[0];
	int minNbr = this->_vec_number[0];

	for (size_t i = 0; i < this->_vec_number.size() ;++i)
	{
		if (maxNbr < this->_vec_number[i])
			maxNbr = this->_vec_number[i];
		if (minNbr > this->_vec_number[i])
			minNbr = this->_vec_number[i];
	}
	return (maxNbr - minNbr);
}

void Span::trySpanFkt(int (Span::*f)() const) const 
{
    try {
        int result = (this->*f)(); // Aufruf der Methode über den Funktionszeiger
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

void Span::printSpan() const
{
	std::cout << "Numbers in Span: " ;
	for (size_t i = 0; i < this->_vec_number.size(); ++i)
	{
		std::cout << this->_vec_number[i] << " "; 
	}
	std::cout << std::endl;
}

// template <typename InputIt>
// void Span::addRange(InputIt first, InputIt last) {
//     try {
//         for (InputIt it = first; it != last; ++it) {
//             if (checkVecFull()) {
//                 this->addNumber(*it);  // Fügt den Wert des Iterators hinzu
//             }
//         }
//     } catch (const std::exception &e) {
//         std::cerr << e.what() << std::endl;
//     }
// }

/*
void Span::addRangeOfNumbers(unsigned int begin, unsigned int end) 
{
	try
	{
		if (begin >= end)
			throw std::out_of_range("Start and End not a range");
		for (unsigned int i = begin; i <= end; ++i)
		{
			if (checkVecFull())
				this->addNumber(begin++);
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}
*/