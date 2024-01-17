#include "../include/A.class.hpp"
#include <stdexcept>

bool isA(Base* ptr)
{
	A* test = dynamic_cast<A*>(ptr);

	return (test != NULL);
}

bool isA(Base& ref)
{
	try {
		A& test = dynamic_cast<A&>(ref);

		static_cast<void>(test);
		return (true);
	} catch (std::exception& e) {
		static_cast<void>(e);
		return (false);
	}
}
