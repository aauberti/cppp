#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExecute;

	public:
		Form();
		Form(std::string const name, int gradeToSign, int gradeToExecute);
		Form(const Form& other);
		~Form();

		Form& operator=(const Form& other);

		std::string getName() const;
		bool isSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat& bureaucrat);

		class GradeTooHighException;
		class GradeTooLowException;

	};
class Form::GradeTooHighException : public std::exception
{
	public:
		const char	*what(void) const throw();
};
	
class Form::GradeTooLowException : public std::exception
{
	public:
		const char	*what(void) const throw();
};

std::ostream& operator<<(std::ostream& out, const Form& form);
		
#endif
