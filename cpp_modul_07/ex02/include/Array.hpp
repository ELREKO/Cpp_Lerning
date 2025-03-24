
# ifndef ARRAY_HPP
# define ARRAY_HPP

#include <string>
#include <iostream>
#include <exception>
#include <cstdlib>  
#include <ctime>   

template <typename T>
class Array
{
	private:
		T *_arr;
		unsigned int _size;

	public:
		// Construcktor and Destructor
		Array();
		Array(unsigned int size);

		Array(const Array &copy);
		Array &operator=(const Array &src);
		T const &at(unsigned int size) const;
		T &operator[](unsigned int i);
		T const &operator[](unsigned int i) const;
		
		~Array();

		unsigned int size() const;
		
		class OutOfRangeUpperException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

# include "Array.tpp"


#endif