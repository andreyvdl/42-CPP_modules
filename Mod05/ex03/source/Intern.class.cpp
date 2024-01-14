#include "../include/Intern.class.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/RobotomyRequestForm.class.hpp"
#include "../include/ShrubberyCreationForm.class.hpp"

// TRUCTOR ====================================================================

Intern::Intern(void) {};

Intern::Intern(Intern const& that)
{
	*this = that;
}

Intern::~Intern(void) {};

// OPERATOR ===================================================================

Intern& Intern::operator=(Intern const& that)
{
	// ...
	(void)that;
	return (*this);
}


// METHOD =====================================================================

// de acordo com o pdf isso aqui é ilegivel pq tem if else
// if (formName == "presidential pardon") {
// 	return (new PresidentialPardonForm(target));
// } else if (formName == "robotomy request") {
// 	return (new RobotomyRequestForm(target));
// } else if (formName == "shrubbery creation") {
// 	return (new ShrubberyCreationForm(target));
// } 
// std::cout << formName << " isn't valid!" << std::endl;
// return (NULL);


AForm* Intern::makeForm(std::string const& formName,
	std::string const& target
) const
{
	std::string const formNames[3] = { "presidential pardon",
		"robotomy request", "shrubbery creation"
	};

	for (int i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			std::cout << "Intern creates " << formName << std::endl;
			switch (i) {
				case 0:
					return (new PresidentialPardonForm(target));
				case 1:
					return (new RobotomyRequestForm(target));
				case 2:
					return (new ShrubberyCreationForm(target));
			}
		}
	}
	std::cout << formName << " is an invalid form!" << std::endl;
	return (NULL);
}
