#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <list>
#include <deque>
// #include <algorithm> 
#include <exception>
#include <limits>
#include <cstdlib>
#include <functional>
#include <ctime> 

class Span 
{
	private:
		unsigned int _max_size;
		std::vector<int> _vec_number;
		Span();
		bool checkVecFull();

	public:
		Span(unsigned int N);
		Span(const Span &copy);
		Span &operator=(const Span &src);
		~Span();

		void addNumber(int nbr);
		
		int longestSpan() const;
		int shortestSpan() const;
		void trySpanFkt(int (Span::*f)() const) const ;
		void printSpan() const;
		//void addRangeOfNumbers(unsigned int begin, unsigned int end) ;
		template <typename InputIt>
		void addRange(InputIt first, InputIt last) {
			try {
				for (InputIt it = first; it != last; ++it) {
					if (checkVecFull()) {
						this->addNumber(*it);  // Fügt den Wert des Iterators hinzu
					}
				}
			} catch (const std::exception &e) {
				std::cerr << e.what() << std::endl;
			}
		}
};

template<typename T>
T randomContainerList(unsigned int max_numbers, int min_range, int max_range) {

    std::srand(static_cast<unsigned int>(std::time(0))); 

    T container ;

    for (unsigned int i = 0; i < max_numbers; ++i) {
        int random_number = std::rand() % (max_range - min_range + 1) + min_range; // Zufallszahlen im Bereich [min_range, max_range]
        container.push_back(random_number);
    }

    return container;
}

#endif