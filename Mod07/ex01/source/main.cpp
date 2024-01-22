#include "../include/iter.template.hpp"
#include "../include/defines.hpp"
#include <iostream>

void isEven(int const& n)
{
	std::cout << std::boolalpha << (n % 2 == 0) << std::endl;
}

void ftStrLen(std::string& str)
{
	std::cout << str.length() << std::endl;
}

namespace tests
{
	void inting(void)
	{
		int arr[5] = {1, 2, 3, 4, 5};

		iter(arr, 5, isEven);
	}

	void stringing(void)
	{
		std::string arr[5] = {"hello", "world", "42", "marvin", "andrey"};

		iter(arr, 5, ftStrLen);
	}
}


int main(void)
{
	std::cout << FG_YELLOW "TESTING WITH INTS" RESET << std::endl;
	tests::inting();
	std::endl(std::cout);
	std::cout << FG_YELLOW "TESTING WITH STRINGS" RESET << std::endl;
	tests::stringing();
	return (0);
}
