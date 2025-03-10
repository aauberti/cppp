#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

Intern::Intern(void) {}

Intern::Intern(const Intern &copy) { *this = copy; }

Intern::~Intern(void) {}

Intern &Intern::operator=(__attribute__((unused))const Intern &copy) { return (*this); }

AForm* Intern::makeForm(const std::string &name, const std::string &target)
{
    std::string functionTab[3] = {"Shrubbery creation", "Robotomy request", "Presidential pardon"};
    AForm* form = NULL;
    
    for (int i = 0; i < 3; ++i)
	{
        if (functionTab[i] == name)
		{
            switch (i)
			{
                case 0:
                    form = new ShrubberyCreationForm(target);
                    break;
                case 1:
                    form = new RobotomyRequestForm(target);
                    break;
                case 2:
                    form = new PresidentialPardonForm(target);
                    break;
            }
            std::cout << "Intern creates " << functionTab[i] << std::endl;
            return (form);
        }
    }
    std::cerr << "Unknown form type: " << name << std::endl;
	throw Intern::unknownForm();
    return (NULL);
}

const char *Intern::unknownForm::what(void) const throw()
{
	return ("Unknown form.");
}