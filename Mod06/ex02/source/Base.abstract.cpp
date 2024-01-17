#include "../include/Base.abstract.hpp"
#include "../include/A.class.hpp"
#include "../include/B.class.hpp"
#include "../include/C.class.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

Base::~Base() {};

Base* generate(void)
{
	static bool first = true;

	if (first) {
		std::srand(std::time(NULL));
		first = false;
	}
	switch (rand() % 3) {
		case 0:
			return (new A());
		case 1:
			return (new B());
		case 2:
			return (new C());
		default:
			return (NULL);
	}
}

void identify(Base* p)
{
	if (isA(p)) {
		std::cout << "this base is A" << std::endl;
	} else if (isB(p)) {
		std::cout << "this base is B" << std::endl;
	} else if (isC(p)) {
		std::cout << "this base is C" << std::endl;
	} else {
		std::cout << "this base is invalid" << std::endl;
	}
}

void identify(Base& p)
{
	if (isA(p))
		std::cout << "this base is A" << std::endl;
	else if (isB(p))
		std::cout << "this base is B" << std::endl;
	else if (isC(p))
		std::cout << "this base is C" << std::endl;
}
