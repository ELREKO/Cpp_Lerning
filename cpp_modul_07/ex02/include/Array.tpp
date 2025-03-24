# ifndef TEMPL_ARRAY_TPP
# define TEMPL_ARRAY_TPP


template <typename T>
Array<T>::Array(): _arr(NULL), _size(0)
{
	std::cout 	<< "Call a Default Array Construcktor" 
				<< std::endl; 
}

template <typename T>
Array<T>::Array(unsigned int size) : _arr(new T[size]), _size(size)
{
	std::cout 	<< "Call a Array size "
				<< _size 
				<< std::endl; 
}

template <typename T>
Array<T>::Array(const Array &copy) : _arr(new T[copy._size]),  _size(copy._size)
{
	std::cout << "Call a Copy Construktor " << std::endl;
	*this = copy;
}

template <typename T>
Array<T>::~Array()
{
	std::cout 	<< "Call Destoucktor"
				<< std::endl;
	delete [] _arr;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &src)
{
	std::cout 	<< "Assignment Operator " 
				<< std::endl;
	
	if (this != &src)
	{
		delete[] _arr;
		_size = src._size;
		_arr = new T[_size];
		for (unsigned int i=0; i < _size; i++)
		{
			_arr[i] = src._arr[i];
		}
	}
	return (*this);
}

template <typename T>
T const &Array<T>::at(unsigned int size) const
{
	try
	{
        if (this->size() == 0)
            throw std::out_of_range("ERROR: Empty Array ");
        if (size >= _size)
            throw Array<T>::OutOfRangeUpperException();
        return _arr[size];
	}
	catch(const Array<T>::OutOfRangeUpperException &e)
    {
        std::cerr << e.what() << "The Size of: " << size << " not possible!" << std::endl
                  << "Max Array Size: " << this->size() << std::endl
                  << "Use Last Array Field" << std::endl << std::endl;
        return _arr[this->size() - 1];
    }
    catch (const std::out_of_range& e)
    {
        std::cerr << "Fehler: Zugriff auf ein leeres Array!" << std::endl << e.what() << std::endl;
        static T dummy_value;
        return dummy_value;
    }
}
// Nicht-konstanter Operator
template <typename T> 
T &Array<T>::operator[](unsigned int size)
{
	return const_cast<T&>(this->at(size));
}

// Konstanter Operator
template <typename T> 
T const &Array<T>::operator[](unsigned int size) const
{
	return this->at(size);
}


template <typename T>
unsigned int Array<T>::size() const
{
	return _size;
}

template <typename T>
const char *Array<T>::OutOfRangeUpperException::what() const throw()
{
	static std::string errorMsg;
    errorMsg = "ERR: Index not in Range!\n" ;
    return errorMsg.c_str();
}
#endif