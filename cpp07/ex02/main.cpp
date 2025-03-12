#include <iostream>
#include "Array.hpp"

#define MAX_VAL 10

int main() {
    Array<int> numbers(MAX_VAL);
    Array<int> copyNumbers;

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = i * 10;
    }

    std::cout << "Array 'numbers' : " << std::endl;
    for (int i = 0; i < MAX_VAL; i++) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }

    copyNumbers = numbers;
    std::cout << "\nArray 'copyNumbers' after assignment: " << std::endl;
    for (int i = 0; i < MAX_VAL; i++) {
        std::cout << "copyNumbers[" << i << "] = " << copyNumbers[i] << std::endl;
    }

    Array<int> copyOfNumbers(numbers);
    std::cout << "\nArray 'copyOfNumbers' after copy constructor: " << std::endl;
    for (int i = 0; i < MAX_VAL; i++) {
        std::cout << "copyOfNumbers[" << i << "] = " << copyOfNumbers[i] << std::endl;
    }

    copyOfNumbers[0] = 1000;
    std::cout << "\nAfter modifying copyOfNumbers[0] to 1000: " << std::endl;
    std::cout << "copyOfNumbers[0] = " << copyOfNumbers[0] << std::endl;
    std::cout << "numbers[0] = " << numbers[0] << std::endl;
    try {
        std::cout << "Accessing with a negative index: " << numbers[-1] << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        std::cout << "Accessing with an index too large: " << numbers[MAX_VAL] << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        numbers[MAX_VAL] = 999;
    } catch (const std::exception &e) {
        std::cerr << "Caught exception during modification: " << e.what() << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = i * 5;
    }

    std::cout << "\nArray 'numbers' after modification: " << std::endl;
    for (int i = 0; i < MAX_VAL; i++) {
        std::cout << "numbers[" << i << "] = " << numbers[i] << std::endl;
    }

    return 0;
}
