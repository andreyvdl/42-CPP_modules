/**
 * @file Fixed.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for methods implementation of Fixed class.
 * @version 1
 * @date 2023-11-20
 * 
 * @copyright Copyright (c) 2023
 */

#include "Fixed.class.hpp"

const int Fixed::_fractionalBits = 8;

int Fixed::getRawBits(void) const {
	return (_fixedNbrValue);
}

void Fixed::setRawBits(int const raw) {
	_fixedNbrValue = raw;
}

float Fixed::toFloat(void) const {
	return ((float)_fixedNbrValue / FRACTIONAL_FACTOR(_fractionalBits));
}

int Fixed::toInt(void) const {
	return ((_fixedNbrValue & EXPONENT_BITWISE) >> _fractionalBits);
}
