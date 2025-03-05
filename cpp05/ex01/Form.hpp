#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <string>

class Form {
	private:
	const std::string	_name;
		bool			_signed;
		const int		_signGrade;
		const int		_execGrade;
	public:
		Form(void);
		Form(const std::string name, const int signGrade, const int execGrade);
		Form(const Form &other);
		~Form(void);

		Form &operator=(const Form &other);
		
		std::string getName(void) const;
		bool getSigned(void) const;
		int getExecGrade(void) const;
		int getSignGrade(void) const;

		void beSigned(const Bureaucrat &other);

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

std::ostream &operator<<(std::ostream &out, const Form &form);

#endif