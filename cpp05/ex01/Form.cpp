#include "Form.hpp"
#include <iostream>

Form::Form(void):
	_name("Form"),	
	_signed(false),
	_signGrade(150),
	_execGrade(150) {}

Form::Form(const std::string name, const int signGrade, const int execGrade):
	_name(name),
	_signed(false),
	_signGrade(signGrade),
	_execGrade(execGrade)
	{
		if (_signGrade > 150 || _execGrade > 150)
			throw Form::GradeTooLowException();
		if (_signGrade < 1 || _execGrade < 1)
			throw Form::GradeTooHighException();
	}

Form::Form(const Form &other):
	_name(other._name),
	_signed(other._signed),
	_signGrade(other._signGrade),
	_execGrade(other._execGrade) {}

Form::~Form(void) {}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_signed = other._signed;
		//_signGrade = other._signGrade;
		//_execGrade = other._execGrade;
	}
	return *this;
}

bool Form::getSigned(void) const { return(_signed); }
std::string Form::getName(void) const { return(_name); }
int Form::getSignGrade(void) const { return (_signGrade); }
int Form::getExecGrade(void) const { return (_execGrade); }

void	Form::beSigned(const Bureaucrat &other)
{
	if (getSignGrade() < other.getGrade())
	{
		std::cout << other.getName() << " couldn't sign " << this->_name << " because of grade too low." << std::endl;
		throw Form::GradeTooLowException();
	}
	std::cout << other.getName() << " sign " << this->_name << "." << std::endl;
	this->_signed = true;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too High.");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too Low.");
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Name : " << form.getName() << std::endl;
	out << "Is signed : " << (form.getSigned() ? "true" : "false") << std::endl;
	out << "Grade to sign : " << form.getSignGrade() << std::endl;
	out << "Grade to execute : " << form.getExecGrade() << std::endl;

	return (out);
}