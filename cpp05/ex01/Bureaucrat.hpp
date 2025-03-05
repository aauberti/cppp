#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <string>

class Bureaucrat {
	private:
		const std::string _name;
		int 	_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(const Bureaucrat& other);
		~Bureaucrat();

		Bureaucrat& operator=(const Bureaucrat& other);

		std::string getName() const;
		int getGrade() const;

		void promotion(void);
		void demotion(void);

		class GradeTooHighException;
		class GradeTooLowException;
};


class Bureaucrat::GradeTooHighException : public std::exception
{
	public:
		const char	*what(void) const throw();
};

class Bureaucrat::GradeTooLowException : public std::exception
{
	public:
		const char	*what(void) const throw();
};

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat);
#endif