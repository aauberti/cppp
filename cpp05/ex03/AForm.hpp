#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include "Bureaucrat.hpp"

class AForm
{
	private:
		bool				_isSigned;
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
	public:
		AForm(void);
		AForm(const std::string name, const int signGrade, const int execGrade);
		AForm(const AForm &other);
		virtual ~AForm(void);

		AForm &operator=(const AForm &other);

		std::string getName(void) const;		
		int getExecGrade(void) const;
		int getSignGrade(void) const;
		bool getIsSigned(void) const;

		void beSigned(const Bureaucrat &other);
		virtual void execute(const Bureaucrat &executor) const = 0;
		
		class GradeTooHighException;
		class GradeTooLowException;
		class FormNotSigned;
		class openFileFailed;

};

class AForm::GradeTooHighException : public std::exception
{
	public:
		const char *what() const throw();
};

class AForm::GradeTooLowException : public std::exception
{
	public:
		const char *what() const throw();
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

std::ostream &operator<<(std::ostream &out, const AForm &form);

#endif
