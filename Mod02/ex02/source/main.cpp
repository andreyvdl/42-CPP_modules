/**
 * @file main.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Main file.
 * @version 1
 * @date 2023-11-20
 * 
 * @copyright Copyright (c) 2023
 */

#include "Fixed.class.hpp"
#include <iostream>

namespace tests {
	void test1(void) {
		const Fixed e(-42);
		const Fixed f(e);
		Fixed g;

		g = Fixed(-3.141f);
		std::cout << e << std::endl;
		std::cout << f << std::endl;
		std::cout << g << std::endl;
	}
}

int main(void) {
	Fixed a;
	Fixed const b(10);
	Fixed const c(42.42f);
	Fixed const d(b);
	
	a = Fixed(1234.4321f);

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	tests::test1();
	return 0;
}
