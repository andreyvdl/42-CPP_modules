#include "../include/Bureaucrat.class.hpp"
#include "../include/ShrubberyCreationForm.class.hpp"
#include "../include/RobotomyRequestForm.class.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/defines.hpp"
#include "../include/Intern.class.hpp"
#include <iostream>

namespace tests
{
	void payday(void)
	{
		Intern someone;
		AForm *form = someone.makeForm("shrubbery creation", "apartament");
		AForm *form2 = someone.makeForm("robotomy request", "Alex Murphy");
		AForm *form3 = someone.makeForm("presidential pardon", "Marvin");
		Bureaucrat boss("Boss", 1);

		boss.signForm(*form);
		boss.executeForm(*form);
		boss.signForm(*form2);
		boss.executeForm(*form2);
		boss.signForm(*form3);
		boss.executeForm(*form3);

		delete form;
		delete form2;
		delete form3;
	}

	void day1(void)
	{
		Intern other;
		AForm* wrongForm = other.makeForm("promotion request", "Sponge Bob");

		if (wrongForm) {
			std::cout << "Isn't null??????" << std::endl;
		} else {
			std::cout << "NULL" << std::endl;
		}
	}
}

int main (void)
{
	std::cout << FG_YELLOW "VALID TEST" RESET << std::endl;
	tests::payday();
	std::cout << std::endl;
	std::cout << FG_YELLOW "INVALID TEST" RESET << std::endl;
	tests::day1();
}
