/**
 * @file main.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Main file.
 * @version 1
 * @date 2023-11-21
 * 
 * @copyright Copyright (c) 2023
 */

#include "Fixed.class.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}
