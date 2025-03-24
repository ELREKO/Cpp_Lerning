#include "Wahtever.hpp"

// class Awesome
// {
//   public:
//     Awesome(void) : _n(0) {}
//     Awesome( int n ) : _n( n ) {}
//     Awesome & operator= (Awesome & a) { _n = a._n; return *this; }
//     bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
//     bool operator!=( Awesome const & rhs ) const{ return (this->_n != rhs._n); }
//     bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
//     bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
//     bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
//     bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
//     int get_n() const { return _n; }
//   private:
//     int _n;
// };
// std::ostream & operator<<(std::ostream & o, const Awesome &a) { o << a.get_n(); return o; }

// int main(void)
// {
// 	Awesome a(2), b(4);

//         swap(a, b);
//         std::cout << a << " " << b << std::endl;
//         std::cout << max(a, b) << std::endl;
//         std::cout << min(a, b) << std::endl;
//         return (0);
// }
//--------------------------------------------

int main(void) 
{

    std::cout << "------------------------- Test Swap ----------------------" << std::endl << std::endl;

    {

        std::cout << std::endl << "---------Swap string--------" << std::endl << std::endl; 

        int a = 12;
        int b = 13;
        std::cout << "Befor Swapl a: " << a << " b: " << b << std::endl;
        swap(a, b);
        std::cout << "After Swapl a: " << a << " b: " << b << std::endl;

        std::cout << std::endl << "---------Swap string--------" << std::endl << std::endl; 
        std::string str_A = "string A";
        std::string str_B = "string B";
        std::cout << "Befor Swapl a: " << str_A << " b: " << str_B << std::endl;
        swap(str_A, str_B);
        std::cout << "After Swapl a: " << str_A << " b: " << str_B << std::endl;
        std::cout << std::endl << std::endl; 

    }

    std::cout << "------------------------- Test MIN ----------------------" << std::endl << std::endl;
    
    {
        int a = 12;
        int b = 13;
        std::cout << "a: " << a << " b: " << b << std::endl;
        std::cout << min(a, b) << std::endl;


        std::cout << std::endl << "---------min string--------" << std::endl << std::endl; 
        std::string str_A = "string C";
        std::string str_B = "string B";
        std::cout << min(str_A, str_B) << std::endl;
        std::cout << std::endl << std::endl; 
    }

    std::cout << "------------------------- Test MAX ----------------------" << std::endl << std::endl;
    
    {
        float a = 12.01;
        float b = 13.01;
        std::cout << "a: " << a << " b: " << b << std::endl;
        std::cout << max(a, b) << std::endl;
        std::cout << std::endl << "---------max string--------" << std::endl << std::endl; 
        std::string str_A = "string C";
        std::string str_B = "string B";
        std::cout << max(str_A, str_B) << std::endl;
        std::cout << std::endl << std::endl; 

    }

    std::cout << "------------------------- subject Example ----------------------" << std::endl << std::endl;

    {
        int a = 2;
        int b = 3;
        ::swap( a, b );
        std::cout << "a = " << a << ", b = " << b << std::endl;
        std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
        std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
        
        std::string c = "chaine1";
        std::string d = "chaine2";
        ::swap(c, d);
        std::cout << "c = " << c << ", d = " << d << std::endl;
        std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
        std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    }
    return 0;
}