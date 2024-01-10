#include "../include/Bureaucrat.class.hpp"
#include "../include/Form.class.hpp"
#include "../include/defines.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace tests
{
	void invalidForms(void)
	{
		std::cout << FG_CYAN "Higher sign grade" RESET << std::endl;
		try {
			Form f("FORM", -42, 42);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << FG_CYAN "Higher exec grade" RESET << std::endl;
		try {
			Form f("FORM", 42, -42);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << FG_CYAN "lower sign grade" RESET << std::endl;
		try {
			Form f("FORM", 42000, 42);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << FG_CYAN "lower exec grade" RESET << std::endl;
		try {
			Form f("FORM", 42, 42000);
		} catch (std::exception& e) {
			std::cout << e.what() << std::endl;
		}

		std::cout << FG_CYAN "Bureaucrat without grade enough" RESET
			<< std::endl;
		Form f("Le Bomb", 42, 42);
		Bureaucrat b("Ohpemraimer", 84);

		b.signForm(f);
	}

	void validForms(void)
	{
		Form f1("Building destruction", 25, 60);
		Bureaucrat b1("COO", 5);
		Form f2("Building construction", 10, 25);
		Bureaucrat b2("CEO", 1);
		Form f3(f1);
		Form f4;


		std::cout << FG_CYAN "Bureaucrat with grade enough" RESET
			<< std::endl;
		b1.signForm(f1);
		b2.signForm(f2);

		f4 = f2;
		std::cout << f3 << std::endl;
		std::cout << f4 << std::endl;
	}
}

int main (void)
{
	std::cout << FG_YELLOW "INVALID FORMS" RESET << std::endl;
	tests::invalidForms();

	std::cout << std::endl;
	std::cout << FG_YELLOW "VALID FORMS" RESET << std::endl;
	tests::validForms();
	return(0);
}
