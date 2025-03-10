#include "AForm.hpp"
#include <iostream>

AForm::AForm(void):
	_isSigned(false),
	_name("AForm"),	
	_signGrade(150),
	_execGrade(150) {}

AForm::AForm(const std::string name, const int signGrade, const int execGrade):
	_isSigned(false),
	_name(name),
	_signGrade(signGrade),
	_execGrade(execGrade) {}

AForm::AForm(const AForm &other):
	_isSigned(other._isSigned),
	_name(other._name),
	_signGrade(other._signGrade),
	_execGrade(other._execGrade) {}

AForm::~AForm(void) {}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return *this;
}

std::string AForm::getName(void) const { return (_name); }		
int AForm::getSignGrade(void) const { return (_signGrade); }
int AForm::getExecGrade(void) const { return (_execGrade); }
bool AForm::getIsSigned(void) const { return (_isSigned); }

void	AForm::beSigned(const Bureaucrat &other)
{
	if (getSignGrade() < other.getGrade())
	{
		std::cout << other.getName() << " couldn't sign " << this->_name << " because of grade too low." << std::endl;
		throw AForm::GradeTooLowException();
	}
	std::cout << other.getName() << " sign " << this->_name << "." << std::endl;
	this->_isSigned = true;
}

void AForm::execute(const Bureaucrat &other) const
{
	if (other.getGrade() > _execGrade)
	{
		std::cout << other.getName() << " couldn't execute " << this->_name << " because of grade too low." << std::endl; 
        throw AForm::GradeTooLowException();
	}
	if (!_isSigned)
	{
		std::cout << other.getName() << " couldn't execute " << this->_name << " because of form not signed." << std::endl;
		throw AForm::FormNotSigned();
	}
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too High.");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too Low.");
}

const char *AForm::FormNotSigned::what(void) const throw()
{
	return ("Form not signed.");
}

const char *AForm::openFileFailed::what(void) const throw()
{
	return ("Open failed.");
}

std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "Name : " << form.getName() << std::endl;
	out << "Is signed : " << (form.getIsSigned() ? "true" : "false") << std::endl;
	out << "Grade to sign : " << form.getSignGrade() << std::endl;
	out << "Grade to execute : " << form.getExecGrade() << std::endl;

	return (out);
}
