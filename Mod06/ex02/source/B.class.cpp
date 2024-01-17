#include "../include/B.class.hpp"
#include <stdexcept>

bool isB(Base* ptr)
{
	B* test = dynamic_cast<B*>(ptr);

	return (test != NULL);
}

bool isB(Base& ref)
{
	try {
		B& test = dynamic_cast<B&>(ref);

		static_cast<void>(test);
		return (true);
	} catch (std::exception& e) {
		static_cast<void>(e);
		return (false);
	}
}
