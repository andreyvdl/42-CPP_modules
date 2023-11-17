/**
 * @file Fixed.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for methods implementation of Fixed class.
 * @version 1
 * @date 2023-11-17
 * 
 * @copyright Copyright (c) 2023
 */

#include "Fixed.class.hpp"
#include <iostream>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed(void) : _fixedNbrValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& that) {
	std::cout << "Copy constructor called" << std::endl;
	*this = that;
}

Fixed::Fixed(const int raw) {
	std::cout << "Int constructor called" << std::endl;
	this->_fixedNbrValue = raw << Fixed::_fractionalBits;
}

