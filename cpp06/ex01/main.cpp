#include "Serializer.hpp"
#include <iomanip>
#include <stdint.h>
#include <iostream>

int main(void)
{
	Data *ptr = new Data();
	ptr->data = 42;

	std::cout << std::setw(20) << "Original pointer" << " : " << ptr << std::endl;
	std::cout << std::setw(20) << "Original value" << " : " << ptr->data << std::endl;
	
	uintptr_t raw = Serializer::serialize(ptr);
	
	std::cout << std::setw(20) << "Serialized value" << " : " << raw << std::endl;
	
	ptr = Serializer::deserialize(raw);
	
	std::cout << std::setw(20) << "Deserialized pointer" << " : " << ptr << std::endl;
	std::cout << std::setw(20) << "Deserialized value" << " : " << ptr->data << std::endl;
	
	delete ptr;
}
