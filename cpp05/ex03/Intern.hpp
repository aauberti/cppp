#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include "AForm.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(const Intern &copy);
		~Intern(void);

		Intern &operator=(Intern const &copy);

		AForm *makeForm(const std::string &name, const std::string &target);
		
		class unknownForm;
};

class Intern::unknownForm : public std::exception
{
	public:
		const char *what() const throw();
};

#endif