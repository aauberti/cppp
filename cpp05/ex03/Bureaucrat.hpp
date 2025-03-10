#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &other);
		~Bureaucrat(void);

		Bureaucrat &operator=(Bureaucrat const &other);

		std::string getName(void) const;
		int getGrade(void) const;

		void promotion(void);
		void demotion(void);
		void signForm(AForm &form);
		void executeForm(const AForm &form);

		class GradeTooHighException;
		class GradeTooLowException;

};

class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
		const char *what() const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
		const char *what() const throw();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);

#endif
