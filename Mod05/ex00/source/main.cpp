#include "../include/Bureaucrat.class.hpp"
#include "../include/defines.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

namespace tests
{
	void validSituation(void)
	{
		Bureaucrat b1("JohnDoe", 1);
		Bureaucrat b2("JaneDoe", 150);
		Bureaucrat b3;
		Bureaucrat b4(b1);
		Bureaucrat b5;

		b5 = b2;

		std::cout << FG_GREEN "B1> " RESET << b1 << std::endl;
		std::cout << FG_GREEN "B2> " RESET << b2 << std::endl;
		std::cout << FG_GREEN "B3> " RESET << b3 << std::endl;
		std::cout << FG_GREEN "B4> " RESET << b4 << std::endl;
		std::cout << FG_GREEN "B5> " RESET << b5 << std::endl;

		b1.downGrade();
		b2.upGrade();

		std::cout << FG_GREEN "B1> " RESET << b1 << std::endl;
		std::cout << FG_GREEN "B2> " RESET << b2 << std::endl;
	}

	void invalidSituation(void)
	{
		try {
			std::cout << FG_CYAN "creaing a bureaucrat with -42 grade" RESET
				<< std::endl;
			Bureaucrat b1("Error", -42);

			std::cout << b1 << std::endl;
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}

		try {
			std::cout << FG_CYAN "creaing a bureaucrat with 404 grade" RESET
				<< std::endl;
			Bureaucrat b1("404", 404);

			std::cout << b1 << std::endl;
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}

		try {
			Bureaucrat b1("CEO", 1);

			std::cout << b1 << std::endl;
			std::cout << FG_CYAN "upgrading a bureaucrat" RESET << std::endl;
			b1.upGrade();
			std::cout << b1 << std::endl;
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}

		try {
			Bureaucrat b1("Intern", 150);

			std::cout << b1 << std::endl;
			std::cout << FG_CYAN "downgrading a bureaucrat" RESET << std::endl;
			b1.downGrade();
			std::cout << b1 << std::endl;
		} catch(const std::exception& e) {
			std::cerr << e.what() << '\n';
		}

		try {
			srand(time(NULL));

			Bureaucrat b1("Random", (rand() % 151) + 1);
			void (Bureaucrat::*f)(void);

			std::cout << b1 << std::endl;
			if (b1.getGrade() > 75) {
				f = &Bureaucrat::downGrade;
			} else {
				f = &Bureaucrat::upGrade;
			}
			while (true) {
				(b1.*f)();
			}
		} catch (const std::exception& e) {
			std::cerr << e.what() << '\n';
		}
	}
}

int main (void)
{
	std::cout << FG_YELLOW "VALID SITUATION" RESET << std::endl;
	tests::validSituation();
	std::cout << std::endl;

	std::cout << FG_YELLOW "INVALID SITUATION" RESET << std::endl;
	tests::invalidSituation();
	std::cout << std::endl;
	return(0);
}
