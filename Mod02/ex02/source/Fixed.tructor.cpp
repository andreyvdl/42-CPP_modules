/**
 * @file Fixed.tructor.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File with constructor and destructor implementation of Fixed class.
 * @version 1
 * @date 2023-11-21
 * 
 * @copyright Copyright (c) 2023
 */

#include "Fixed.class.hpp"

Fixed::Fixed(void) : _fixedNbrValue(0) {}

Fixed::Fixed(Fixed const& that) {
	*this = that;
}

Fixed::Fixed(int const raw) {
	_fixedNbrValue = ((raw << _fractionalBits) & EXPONENT_BITWISE);
	_fixedNbrValue |= (raw & SIGNAL_BITWISE);
}

Fixed::Fixed(float const raw) {
	_fixedNbrValue = roundf(raw * (1 << _fractionalBits));
}

Fixed::~Fixed(void) {}
