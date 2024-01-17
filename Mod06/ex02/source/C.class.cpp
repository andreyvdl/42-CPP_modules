#include "../include/C.class.hpp"
#include <stdexcept>

bool isC(Base* ptr)
{
	C* test = dynamic_cast<C*>(ptr);

	return (test != NULL);
}

bool isC(Base& ref)
{
	try {
		C& test = dynamic_cast<C&>(ref);

		static_cast<void>(test);
		return (true);
	} catch (std::exception& e) {
		static_cast<void>(e);
		return (false);
	}
}
