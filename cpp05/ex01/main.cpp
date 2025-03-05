#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    try {
        std::cout << "--- Test 1: Default Constructor ---" << std::endl;
        Form defaultForm;
        std::cout << defaultForm << std::endl;

        std::cout << "--- Test 2: Parameterized Constructor ---" << std::endl;
        Form importantForm("ImportantDocument", 50, 25);
        std::cout << importantForm << std::endl;


        std::cout << "--- Test 3: Copy Constructor ---" << std::endl;
        Form copiedForm(importantForm);
        std::cout << "Copied Form: \n" << copiedForm << std::endl;


        std::cout << "--- Test 4: Assignment Operator ---" << std::endl;
        Form assignedForm;
        assignedForm = importantForm;
        std::cout << "Assigned Form: \n" << assignedForm << std::endl;

        std::cout << "--- Test 5: Successful Signing ---" << std::endl;
        Bureaucrat bureaucrat1("John", 40);
        importantForm.beSigned(bureaucrat1);
        std::cout << "Form after signing: \n" << importantForm << std::endl;

        std::cout << "--- Test 6: Failed Signing ---" << std::endl;
        Bureaucrat bureaucrat2("Mike", 60);
        try {
            importantForm.beSigned(bureaucrat2);
        } catch (const Form::GradeTooLowException& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        std::cout << "--- Test 7: Grade Too High Exception ---" << std::endl;
        try {
            Form invalidForm("InvalidForm", 0, 10);
        } catch (const Form::GradeTooHighException& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

        std::cout << "--- Test 8: Grade Too Low Exception ---" << std::endl;
        try {
            Form invalidForm("InvalidForm", 151, 10);
        } catch (const Form::GradeTooLowException& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }

    } catch (const std::exception& e) {
        std::cerr << "Unexpected exception: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "\nAll tests completed successfully!" << std::endl;
    return 0;
}