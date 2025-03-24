
# ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <string>
#include <iostream>
#include <exception>

template <typename T1, typename T2>
struct isSame
{
  static const bool value = false;
};

template <typename T>
struct isSame <T, T> 
{
  static const bool value = true;
};



template <typename T1, typename T2>
bool arguments_same_datatype()
{
  if (!isSame<T1, T2>::value)
    throw std::runtime_error ("The both Arguments haven't the same Datatype! \n No Change!");
  return true;
}


template <typename T1, typename T2> 
void swap (T1 &a, T2 &b)
{
  try {
    if (arguments_same_datatype<T1, T2>())
    {
      T1 temp = b;
      b = a;
      a = temp;
    }
  }
  catch (std::exception& e) 
  {
    std::cerr << "Error Datatype: " << e.what() << std::endl;
  }
} 

template <typename T1, typename T2> 
T1 min(const T1 &a,const T2 &b)
{
  try
  {
      if (arguments_same_datatype<T1, T2>())
      {
        return (a <= b ? a : b); 
      }
  }
  catch (std::exception &e)
  {
    std::cerr << "Error Datatype: " << e.what() << std::endl;
  }
  return a;
}

template <typename T1, typename T2> 
T1 max(const T1 &a,const  T2 &b)
{
  try
  {
      if (arguments_same_datatype<T1, T2>())
      {
        return (a >= b ? a : b); 
      }
  }
  catch (std::exception &e)
  {
    std::cerr << "Error Datatype: " << e.what() << std::endl;
  }
  return a;
}
#endif