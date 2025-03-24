#include "includes/Serializer.hpp"

int main (void)
{
    Data data_test;


    data_test.c_value = 't';
    data_test.d_value = 42.4242;
    data_test.i_value = 21212121;
    data_test.l_value = 212121212121211;
    data_test.str_array[0] = "Max";
    data_test.str_array[1] = "Mustermann";
    data_test.str_array[2] = "Musterfrau";


    uintptr_t uintptr_test;
    uintptr_test = Serializer::serialize(&data_test);

    Data *data_deSerializer;
    data_deSerializer = Serializer::deserialize(uintptr_test);

    std::cout << "c_value:  " << data_deSerializer->c_value << std::endl;
    std::cout << "d_value:  " << data_deSerializer->d_value << std::endl;
    std::cout << "l_value:  " << data_deSerializer->l_value << std::endl;
    std::cout << "i_value:  " << data_deSerializer->i_value << std::endl;
    for (int i=0; i<3; i++)
    {
        std::cout << "str_array_" << i << " " << data_deSerializer->str_array[i] << std::endl;
    }
    
}