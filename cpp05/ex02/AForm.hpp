#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class AForm {
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		AForm();
		AForm(std::string const name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		~AForm();

		AForm& operator=(const AForm& other);

		std::string getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& bureaucrat);
		virtual void execute(const Bureaucrat &executor) const = 0;

		class GradeTooHighException;
		class GradeTooLowException;
		class FormNotSigned;
		class openFileFailed;

	};
class AForm::GradeTooHighException : public std::exception
{
	public:
		const char	*what(void) const throw();
};
	
class AForm::GradeTooLowException : public std::exception
{
	public:
		const char	*what(void) const throw();
};

class AForm::FormNotSigned : public std::exception
{
	public:
		const char *what() const throw();
};

class AForm::openFileFailed : public std::exception
{
	public:
		const char *what() const throw();
};


std::ostream& operator<<(std::ostream& out, const AForm& form);
		
#endif
