#include "iter.hpp"

// class Awesome
// {
//   public:
//     Awesome( void ) : _n( 42 ) { return; }
//     int get( void ) const { return this->_n; }
//   private:
//     int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs )
// {
//   o << rhs.get();
//   return o;
// }

// template< typename T >
// void print( T& x )
// {
//   std::cout << x << std::endl;
//   return;
// }

// int main() {
//   int tab[] = { 0, 1, 2, 3, 4 };
//   Awesome tab2[5];

//   iter( tab, 5, print<const int> );
//   iter( tab2, 5, print<Awesome> );

//   return 0;
// }


int main(void) 
{

    std::cout << std::endl << "------------------------- Test Int Array ----------------------" << std::endl << std::endl;
    int i_testArray[] = {2,4,6,8,1};
    iter(i_testArray, 5, printElement<int>);

    std::cout << std::endl << "------------------------- Test float Array ----------------------" << std::endl << std::endl;
    float f_testArray[] = {-2.1, 4.3, 6.1, 8.2, 0.1};
   iter(f_testArray, 5, printElement<float>);

    std::cout << std::endl << "------------------------- Test String Array ----------------------" << std::endl << std::endl;
    std::string str_testArray[] = {"Hallo ", "Guten ", "Morgen", "Test", "Template", "cpp07"};
    iter(str_testArray, 2, printElement<std::string>);

    return 0;
}