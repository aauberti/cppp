#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(void):
	_name("Bureaucrat"),
	_grade(150) {}

Bureaucrat::Bureaucrat(std::string const name, int grade):
	_name(name),
	_grade(grade) 
{
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) { *this = other; }

Bureaucrat::~Bureaucrat(void) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
	{
		(std::string)this->_name = other._name;
		this->_grade = other._grade;
	}

	return (*this);
}

std::string Bureaucrat::getName(void) const { return (_name); }
int Bureaucrat::getGrade(void) const { return (_grade); }

void Bureaucrat::promotion(void)
{
	if (this->_grade == 1)
			throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

void Bureaucrat::demotion(void)
{
	if (this->_grade == 150)
			throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

void Bureaucrat::signForm(AForm &form)
{
	form.beSigned(*this);
}

void Bureaucrat::executeForm(const AForm &form)
{
	if(!form.getIsSigned())
	{
		std::cout << form.getName() << " cannot be executed because it is not signed." << std::endl;
		throw AForm::FormNotSigned();
	}
	else if (form.getExecGrade() < this->_grade)
	{
		std::cout << getName() << " cannot execute " << form.getName() << " because his grade is too low." <<std::endl;
		throw Bureaucrat::GradeTooLowException();
	}

	form.execute(*this);
	std::cout << getName() << " executed " << form.getName()  << std::endl;
}

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too High.");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too Low.");
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << "." << std::endl;

	return (out);
}
