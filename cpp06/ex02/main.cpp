#include "Base.hpp"
#include <iostream>

int main() {
    std::cout << "Testing generate function:" << std::endl;
    Base* obj1 = generate();
    Base* obj2 = generate();
    Base* obj3 = generate();
    
    std::cout << "\nTesting identify with pointers:" << std::endl;
    identify(obj1);
    identify(obj2);
    identify(obj3);
    
    std::cout << "\nTesting identify with references:" << std::endl;
    identify(*obj1);
    identify(*obj2);
    identify(*obj3);
    
    delete obj1;
    delete obj2;
    delete obj3;
    
    return 0;
}