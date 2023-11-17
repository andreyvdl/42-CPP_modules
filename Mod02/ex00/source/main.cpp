/**
 * @file main.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Main file for tests.
 * @version 1
 * @date 2023-11-17
 * 
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include "Fixed.class.hpp"
#include "Defines.hpp"
#define CRLF "\r\n"

namespace tests {
	void test1(void) {
		std::cout << FG_YELLOW << CRLF"STARTING TEST 1" << RESET << std::endl;

		Fixed d;
		Fixed e(d);

		std::cout << "Before d: " << d.getRawBits() << std::endl;
		std::cout << "Before e: " << e.getRawBits() << std::endl;
		e.setRawBits(42);
		std::cout << "After d: " << d.getRawBits() << std::endl;
		std::cout << "After e: " << e.getRawBits() << std::endl;
	}

	void test2(void) {
		std::cout << FG_YELLOW << CRLF"STARTING TEST 2" << RESET << std::endl;

		Fixed f;
		Fixed g(f);

		std::cout << "Before f: " << f.getRawBits() << std::endl;
		std::cout << "Before g: " << g.getRawBits() << std::endl;
		f.setRawBits(42);
		std::cout << "After f: " << f.getRawBits() << std::endl;
		std::cout << "After g: " << g.getRawBits() << std::endl;
	}
}

int main( void ) {
	Fixed a;
	Fixed b( a );
	Fixed c;

	c = b;

	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	tests::test1();
	tests::test2();
	return 0;
}
