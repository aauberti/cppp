#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

PresidentialPardonForm::PresidentialPardonForm(void):
	AForm("PresidentialPardonForm", 25, 5),
	_target("Target") {}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
	AForm("PresidentialPardonForm", 25, 5),
	_target(target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) { *this = other; }

PresidentialPardonForm::~PresidentialPardonForm(void) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}

	return (*this);
}

std::string PresidentialPardonForm::getTarget(void) const { return (this->_target); }

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	AForm::execute(executor);

	std::cout << getTarget() << " has been pardonned by Zaphod Beeblebrox" << std::endl;
}
