/**
 * @file Fixed.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for creating methods for Fixed class.
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

Fixed::~Fixed(void) {
	std::cout << "Fixed destructor" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& that) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &that)
		_fixedNbrValue = that.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (_fixedNbrValue);
}

void Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_fixedNbrValue = raw;
}
