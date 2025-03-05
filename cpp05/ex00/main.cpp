#include <iostream>
#include "Bureaucrat.hpp"

int main() {
    try {
        std::cout << "--- Test 1: Normal Constructor ---" << std::endl;
        Bureaucrat john("John", 75);
        std::cout << john;

        std::cout << "--- Test 2: Getter Methods ---" << std::endl;
        std::cout << "Name: " << john.getName() << std::endl;
        std::cout << "Grade: " << john.getGrade() << std::endl;

        std::cout << "--- Test 3: Promotion ---" << std::endl;
        john.promotion();
        std::cout << "After promotion: " << john;

        std::cout << "--- Test 4: Demotion ---" << std::endl;
        john.demotion();
        std::cout << "After demotion: " << john;

        std::cout << "--- Test 5: Copy Constructor ---" << std::endl;
        Bureaucrat jane = john;
        std::cout << "Copied Bureaucrat: " << jane;

        std::cout << "--- Test 6: Assignment Operator ---" << std::endl;
        Bureaucrat mike("Mike", 50);
        mike = john;
        std::cout << "Assigned Bureaucrat: " << mike;

        std::cout << "--- Test 7: Grade Too High Exception ---" << std::endl;
        try {
            Bureaucrat tooHigh("TooHigh", 0);
        } catch (const Bureaucrat::GradeTooHighException& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        std::cout << "--- Test 8: Grade Too Low Exception ---" << std::endl;
        try {
            Bureaucrat tooLow("TooLow", 151);
        } catch (const Bureaucrat::GradeTooLowException& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        std::cout << "--- Test 9: Promotion Limit ---" << std::endl;
        Bureaucrat topBureaucrat("Top", 1);
        try {
            topBureaucrat.promotion();
        } catch (const Bureaucrat::GradeTooHighException& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        std::cout << "--- Test 10: Demotion Limit ---" << std::endl;
        Bureaucrat bottomBureaucrat("Bottom", 150);
        try {
            bottomBureaucrat.demotion();
        } catch (const Bureaucrat::GradeTooLowException& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "All tests completed successfully!" << std::endl;
    return 0;
}