#include <iostream>
#include "../include/defines.hpp"
#include "../include/Array.template.hpp"

namespace tests
{
	void invalid(void) {
		Array<int> a(2);
		Array<int> b;

		try {
			a[2] = 42;
		} catch (std::exception& e) {
			std::cout << FG_RED << e.what() << RESET << std::endl;
		}

		try {
			b[0] = 42;
		} catch (std::exception& e) {
			std::cout << FG_RED << e.what() << RESET << std::endl;
		}
	}

	void valid(void) {
		Array<int> a(5);

		std::cout << FG_BLUE "Array a size: " RESET << a.size() << std::endl;
		for (int i = 0; i < 5; i++) {
			a[i] = i * i;
		}

		for (int i = 0; i < 5; i++) {
			std::cout << FG_CYAN "Array a[" << i << "]: " RESET << a[i]
				<< std::endl;
		}

		Array<int> b(a);
		Array<int> c(42);
		Array<int> d;

		std::cout << FG_BLUE "Array b size: " RESET << b.size() << std::endl;
		std::cout << FG_BLUE "Array c size: " RESET << c.size() << std::endl;
		std::cout << FG_BLUE "Array d size: " RESET << d.size() << std::endl;

		for (int i = 0; i < 5; i++) {
			std::cout << FG_CYAN "Array b[" << i << "]: " RESET << b[i]
				<< std::endl;
		}
		std::endl(std::cout);
		for (int i = 0; i < 5; i++) {
			std::cout << FG_CYAN "Array c[" << i << "]: " RESET << c[i]
				<< std::endl;
		}

		c = a;
		d = b;

		std::cout << FG_BLUE "Array c size: " RESET << c.size() << std::endl;
		std::cout << FG_BLUE "Array d size: " RESET << d.size() << std::endl;

		for (int i = 0; i < 5; i++) {
			std::cout << FG_CYAN "Array c[" << i << "]: " RESET << c[i]
				<< std::endl;
		}
		std::endl(std::cout);
		for (int i = 0; i < 5; i++) {
			std::cout << FG_CYAN "Array d[" << i << "]: " RESET << d[i]
				<< std::endl;
		}
		std::endl(std::cout);

		Array<int> e(a);

		for (int i = 0; i < 5; i++) {
			a[i] = i * 42;
		}

		for (int i = 0; i < 5; i++) {
			std::cout << FG_CYAN "Array a[" << i << "]: " RESET << a[i]
				<< std::endl;
		}
		std::endl(std::cout);
		for (int i = 0; i < 5; i++) {
			std::cout << FG_CYAN "Array e[" << i << "]: " RESET << e[i]
				<< std::endl;
		}
	}
}

int main(void)
{
	std::cout << FG_YELLOW "ERROR TESTS" RESET << std::endl;
	tests::invalid();
	std::endl(std::cout);
	std::cout << FG_YELLOW "VALID TESTS" RESET << std::endl;
	tests::valid();
}
