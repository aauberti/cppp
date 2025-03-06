#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
	try {
		Bureaucrat bob("Bob", 50);
		Bureaucrat john("John", 100);

		Form taxForm("Tax Form", 60, 100);
		std::cout << taxForm << std::endl;

		bob.signForm(taxForm);
		john.signForm(taxForm);

		std::cout << taxForm << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}
}
