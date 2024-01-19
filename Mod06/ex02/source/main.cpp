#include "../include/Base.abstract.hpp"
#include "../include/A.class.hpp"
#include "../include/B.class.hpp"
#include "../include/C.class.hpp"
#include "../include/defines.hpp"
#include <iostream>

int main(void)
{
	for (int i = 0; i < 10; i++) {
		Base* base = generate();

		std::cout << FG_YELLOW << i <<  " identify(Base*): " RESET << std::endl;
		identify(base);
		std::cout << FG_CYAN <<  i <<  " identify(Base&): " RESET << std::endl;
		identify(*base);

		delete base;
		std::endl(std::cout);
	}

	identify(NULL);
}
