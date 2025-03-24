# ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Generally_Header.hpp"


struct Data
{
   int i_value;
   char c_value;
   long l_value;
   double d_value;
   std::string str_array[3];
};


class Serializer
{
private:
    Serializer();
    Serializer(const Serializer &copy);
    Serializer &operator=(const Serializer &src);
    ~Serializer();
    
public:

    static uintptr_t serialize(Data* ptr);
    static Data* deserialize(uintptr_t raw);


};




#endif