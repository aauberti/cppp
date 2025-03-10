#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <exception>
#include <iostream>

void ShrubberyTooLowToSign(void)
{
	Bureaucrat bob("bob", 146);
	std::cout << bob;

	ShrubberyCreationForm form("Form");
	std::cout << form;
	form.beSigned(bob);
	form.execute(bob);
}

void ShrubberyTooLowToExecute(void)
{
	Bureaucrat bob("bob", 138);
	std::cout << bob;

	ShrubberyCreationForm form("Form");
	std::cout << form;
	form.beSigned(bob);
	form.execute(bob);
}

void RobotomyTooLowToSign(void)
{
	Bureaucrat bob("bob", 73);
	std::cout << bob;

	RobotomyRequestForm form("Form");
	std::cout << form;
	form.beSigned(bob);
	form.execute(bob);
}

void RobotomyTooLowToExecute(void)
{
	Bureaucrat bob("bob", 46);
	std::cout << bob;

	RobotomyRequestForm form("Form");
	std::cout << form;
	form.beSigned(bob);
	form.execute(bob);
}

void PresidentialTooLowToSign(void)
{
	Bureaucrat bob("bob", 26);
	std::cout << bob;

	PresidentialPardonForm form("Form");
	std::cout << form;
	form.beSigned(bob);
	form.execute(bob);
}

void PresidentialTooLowToExecute(void)
{
	Bureaucrat bob("bob", 6);
	std::cout << bob;

	PresidentialPardonForm form("Form");
	std::cout << form;
	form.beSigned(bob);
	form.execute(bob);
}

void ShrubberyNotSigned(void)
{
	Bureaucrat bob("bob", 1);
	std::cout << bob;

	ShrubberyCreationForm form("Form");
	std::cout << form;
	form.execute(bob);
}

void RobotomyNotSigned(void)
{
	Bureaucrat bob("bob", 1);
	std::cout << bob;

	RobotomyRequestForm form("Form");
	std::cout << form;
	form.execute(bob);
}

void PresidentialNotSigned(void)
{
	Bureaucrat bob("bob", 1);
	std::cout << bob;

	PresidentialPardonForm form("Form");
	std::cout << form;
	form.execute(bob);
}

void GoodShrubbery(void)
{
	Bureaucrat bob("bob", 1);
	std::cout << bob;

	ShrubberyCreationForm form("Form");
	std::cout << form;
	form.beSigned(bob);
	form.execute(bob);
}

void GoodRobotomy(void)
{
	Bureaucrat bob("bob", 1);
	std::cout << bob;

	RobotomyRequestForm form("Form");
	std::cout << form;
	form.beSigned(bob);
	form.execute(bob);
}

void GoodPresidential(void)
{
	Bureaucrat bob("bob", 1);
	std::cout << bob;

	PresidentialPardonForm form("Form");
	std::cout << form;
	form.beSigned(bob);
	form.execute(bob);
}

int main(void) 
{
	try { ShrubberyTooLowToSign(); }
	catch (const std::exception &e) { std::cerr << "An error occurred: " << e.what() << std::endl; }
	std::cout << std::endl;
  
	try { ShrubberyTooLowToExecute(); }
	catch (const std::exception &e) { std::cerr << "An error occurred: " << e.what() << std::endl; }
	std::cout << std::endl;
   
	try { RobotomyTooLowToSign(); }
	catch (const std::exception &e) { std::cerr << "An error occurred: " << e.what() << std::endl; }
	std::cout << std::endl;
   
	try { RobotomyTooLowToExecute(); }
	catch (const std::exception &e) { std::cerr << "An error occurred: " << e.what() << std::endl; }
	std::cout << std::endl;
   
	try { PresidentialTooLowToSign(); }
	catch (const std::exception &e) { std::cerr << "An error occurred: " << e.what() << std::endl; }
	std::cout << std::endl;
   
	try { PresidentialTooLowToExecute(); }
	catch (const std::exception &e) { std::cerr << "An error occurred: " << e.what() << std::endl; }
	std::cout << std::endl;
   
	try { ShrubberyNotSigned(); }
	catch (const std::exception &e) { std::cerr << "An error occurred: " << e.what() << std::endl; }
	std::cout << std::endl;
   
	try { RobotomyNotSigned(); }
	catch (const std::exception &e) { std::cerr << "An error occurred: " << e.what() << std::endl; }
	std::cout << std::endl;
   
	try { PresidentialNotSigned(); }
	catch (const std::exception &e) { std::cerr << "An error occurred: " << e.what() << std::endl; }
	std::cout << std::endl;
   
	try { GoodShrubbery(); }
	catch (const std::exception &e) { std::cerr << "An error occurred: " << e.what() << std::endl; }
	std::cout << std::endl;
   
	try { GoodRobotomy(); }
	catch (const std::exception &e) { std::cerr << "An error occurred: " << e.what() << std::endl; }
	std::cout << std::endl;
   
	try { GoodPresidential(); }
	catch (const std::exception &e) { std::cerr << "An error occurred: " << e.what() << std::endl; }
	std::cout << std::endl;
   
	return (0);
}
