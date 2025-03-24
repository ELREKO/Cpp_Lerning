#ifndef TEMPL_ITER_HPP
#define TEMPL_ITER_HPP

#include <stdexcept>
#include <exception>
#include <iostream>

class OutOfRangeUpperException : public std::exception
{
public:
    virtual const char *what() const throw();
};

const char* OutOfRangeUpperException::what() const throw()
{
    static const std::string errorMsg = "ERR: Index not in Range!\n";
    return errorMsg.c_str();
}

// Funktionsobjekt zur Validierung der Länge
// template <typename T>
// struct LengthValidator
// {
//     int actualLength;

//     LengthValidator(int length) : actualLength(length) {}

//     void operator()(int providedLength) const
//     {
//         if (providedLength > actualLength)
//             throw OutOfRangeUpperException();
//     }
// };

template <typename T, typename F>
void iter(T* arrary, int length, F function)
{
    try
    {
        if (!function)
            throw std::invalid_argument("ERROR: No valid function!");
        // int sizeOfArray = sizeof(arrary) / sizeof(arrary[0]);
        // std::cout << sizeOfArray << std::endl;
        // //if (sizeOfArray<length) 
        //     throw OutOfRangeUpperException();

        for (int i = 0; i < length; i++)
        {
            function(arrary[i]);
        }
    }
    catch(const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

template <typename T> 
void printElement(const T& element)
{
    std::cout << element << std::endl;
}

#endif
