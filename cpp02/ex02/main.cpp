#include "Fixed.hpp"

// int main( void ) {
// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;
// 	return 0;
// }

#include "Fixed.hpp"

int main() {
    std::cout << "======== FIXED CLASS TESTS ========" << std::endl;
    
    // Constructors test
    std::cout << "\n----- Constructors -----" << std::endl;
    Fixed a;
    Fixed b(10);
    Fixed c(42.4219f);
    Fixed d(b);
    
    std::cout << "a (default): " << a << std::endl;
    std::cout << "b (int): " << b << std::endl;
    std::cout << "c (float): " << c << std::endl;
    std::cout << "d (copy of b): " << d << std::endl;
    
    // Assignment operator test
    std::cout << "\n----- Assignment Operator -----" << std::endl;
    a = c;
    std::cout << "a = c: " << a << std::endl;
    
    // Comparison operators test
    std::cout << "\n----- Comparison Operators -----" << std::endl;
    std::cout << "b > c: " << (b > c) << std::endl;
    std::cout << "b < c: " << (b < c) << std::endl;
    std::cout << "b >= d: " << (b >= d) << std::endl;
    std::cout << "b <= d: " << (b <= d) << std::endl;
    std::cout << "b == d: " << (b == d) << std::endl;
    std::cout << "b != c: " << (b != c) << std::endl;
    
    // Arithmetic operators test
    std::cout << "\n----- Arithmetic Operators -----" << std::endl;
    Fixed e = b + c;
    Fixed f = c - b;
    Fixed g = b * c;
    Fixed h = c / b;
    
    std::cout << "b + c = " << e << std::endl;
    std::cout << "c - b = " << f << std::endl;
    std::cout << "b * c = " << g << std::endl;
    std::cout << "c / b = " << h << std::endl;
    
    // Increment/decrement operators test
    std::cout << "\n----- Increment/Decrement Operators -----" << std::endl;
    Fixed i(5.05f);
    std::cout << "initial i: " << i << std::endl;
    
    std::cout << "++i: " << ++i << std::endl;
    std::cout << "i after ++i: " << i << std::endl;
    
    std::cout << "i++: " << i++ << std::endl;
    std::cout << "i after i++: " << i << std::endl;
    
    std::cout << "--i: " << --i << std::endl;
    std::cout << "i after --i: " << i << std::endl;
    
    std::cout << "i--: " << i-- << std::endl;
    std::cout << "i after i--: " << i << std::endl;
    
    // Min and max functions test
    std::cout << "\n----- Min and Max Functions -----" << std::endl;
    
    // Non-const version
    Fixed j(100.5f);
    Fixed k(200.75f);
    
    std::cout << "j: " << j << ", k: " << k << std::endl;
    std::cout << "min(j, k): " << Fixed::min(j, k) << std::endl;
    std::cout << "max(j, k): " << Fixed::max(j, k) << std::endl;
    
    // Const version
    const Fixed l(300.25f);
    const Fixed m(150.125f);
    
    std::cout << "l (const): " << l << ", m (const): " << m << std::endl;
    std::cout << "min(l, m): " << Fixed::min(l, m) << std::endl;
    std::cout << "max(l, m): " << Fixed::max(l, m) << std::endl;
    
    // Reference modification test
    std::cout << "\n----- Reference Modification -----" << std::endl;
    Fixed& minRef = Fixed::min(j, k);
    std::cout << "Reference to min before modification: " << minRef << std::endl;
    minRef.setRawBits(minRef.getRawBits() + 1000);
    std::cout << "j after minRef modification: " << j << std::endl;
    std::cout << "k after minRef modification: " << k << std::endl;
    
    return 0;
}