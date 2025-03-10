#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include <exception>
#include <iostream>

void UnknownForm(void)
{
	Bureaucrat bob("bob", 1);
	std::cout << bob;
	Intern luke;
	AForm *form = luke.makeForm("Random shit", "Darth Vader");
	std:: cout << *form;
	form->beSigned(bob);
	form->execute(bob);
	delete form;
}

void ShrubberyForm(void)
{
	Bureaucrat bob("bob", 1);
	std::cout << bob;
	Intern luke;
	AForm *form = luke.makeForm("Shrubbery creation", "bob");
	std::cout << *form;
	form->beSigned(bob);
	form->execute(bob);
	delete form;
}

void RobotomyForm(void)
{
	Bureaucrat bob("bob", 1);
	std::cout << bob;
	Intern luke;
	AForm *form = luke.makeForm("Robotomy request", "bob");
	std::cout << *form;
	form->beSigned(bob);
	form->execute(bob);
	delete form;
}

void PresidentialForm(void)
{
	Bureaucrat bob("bob", 1);
	std::cout << bob;
	Intern luke;
	AForm *form = luke.makeForm("Presidential pardon", "bob");
	std::cout << *form;
	form->beSigned(bob);
	form->execute(bob);
	delete form;
}

int main(void) 
{

	try { UnknownForm(); }
	catch (const std::exception &e) { std::cerr << "An error occurred: " << e.what() << std::endl; }
	std::cout << std::endl;
	
	try { ShrubberyForm(); }
	catch (const std::exception &e) { std::cerr << "An error occurred: " << e.what() << std::endl; }
	std::cout << std::endl;
	
	try { RobotomyForm(); }
	catch (const std::exception &e) { std::cerr << "An error occurred: " << e.what() << std::endl; }
	std::cout << std::endl;
	
	try { PresidentialForm(); }
	catch (const std::exception &e) { std::cerr << "An error occurred: " << e.what() << std::endl; }
	std::cout << std::endl;
	
    return (0);
}