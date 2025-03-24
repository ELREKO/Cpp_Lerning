

#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}

//--------------------------------------------------------------------------------------------------------------------------------------------------------------------
// #include <Array.hpp>
// int main(void) 
// {
//     std::cout << std::endl << "------------------------- Array ----------------------" << std::endl << std::endl;
// 	Array<int> emptyArray;
// 	std::cout << "emptyArray size: " << emptyArray.size() << std::endl;
//     std::cout << "test: " << emptyArray[1] << std::endl; 
    
//     Array<std::string> str_Array(3);
//     str_Array[2] = "Morgen";
//     std::cout <<  str_Array[2] << std::endl;
//     //str_Array[-1] = "Hallo";        // Test Exception for Wrong index
//     str_Array[0] = "Hallo Again"; 
//     str_Array[1] = "Test";
 
//     str_Array[3] = "Abend";       // Test Exception for Wrong index

//    std::cout << str_Array[0] << " | " << str_Array[1] << " | " <<  str_Array[2] << std::endl;
//    std::cout << "str_Array size: " << str_Array.size() << std::endl;

//     Array<int> i_arry(10);

//     for (unsigned int i = 0; i < 10; i++)
//         i_arry[i] = i + 77;


//     std::cout << std::endl << "------------------------- Test Copy Assinment Constructor ----------------------" << std::endl << std::endl;

//     emptyArray = i_arry;  // Test Operator overload
//     Array<int> i_test_copy(emptyArray);  // Test Copy Constructor 
//     std::cout << "ARRAY test copy   |ARRAY emptyArray   |ARRAY i_array" << std::endl;

//     for (unsigned int i = 0; i < i_test_copy.size(); i++)
//         std::cout << i_test_copy[i] <<"                |"<< emptyArray[i] << "                |" << i_arry[i] << std::endl;

//     const Array<int> constArray = i_arry;
//     for (unsigned int i = 0; i < constArray.size(); i++)
//         std::cout << constArray[i] << std::endl;
// }