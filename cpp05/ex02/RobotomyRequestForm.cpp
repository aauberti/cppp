#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <sys/wait.h>
#include <iostream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(void):
	AForm("RobotomyRequestForm", 72, 45) {}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
	AForm("RobotomyRequestForm", 72, 45),
	_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) { *this = other; }

RobotomyRequestForm::~RobotomyRequestForm(void) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}

	return (*this);
}

std::string RobotomyRequestForm::getTarget(void) const { return (this->_target); }

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{	
	AForm::execute(executor);

	std::srand(std::time(0));
	int headOrTail = std::rand() % 2;

	if (headOrTail)
	{
		std::cout << getTarget() << " has been robotomized successfully." << std::endl;
	}
	else 
	{
		std::cout << "Robotomy failed." << std::endl;
	}
}
