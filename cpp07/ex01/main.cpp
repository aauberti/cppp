#include <iostream>
#include "Iter.hpp"

template <typename T>
void printElement(T const & element) {
	std::cout << element << " ";
}

template <typename T>
void squareElement(T & element) {
	element = element * element;
}

int main() {
	int intArray[] = {1, 2, 3, 4, 5};
	size_t intArrayLength = sizeof(intArray) / sizeof(int);
	
	std::cout << "Original int array: ";
	iter(intArray, intArrayLength, printElement<int>);
	std::cout << std::endl;

	iter(intArray, intArrayLength, squareElement<int>);
	
	std::cout << "After applying square function: ";
	iter(intArray, intArrayLength, printElement<int>);
	std::cout << std::endl;
	
	std::string strArray[] = {"Hello", "CPP", "Module", "07"};
	size_t strArrayLength = sizeof(strArray) / sizeof(std::string);
	
	std::cout << "String array: ";
	iter(strArray, strArrayLength, printElement<std::string>);
	std::cout << std::endl;
	
	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	size_t charArrayLength = sizeof(charArray) / sizeof(char);
	
	std::cout << "Char array: ";
	iter(charArray, charArrayLength, printElement<char>);
	std::cout << std::endl;
	
	return 0;
}