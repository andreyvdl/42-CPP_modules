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
#include <cmath>
#define SIGNAL_BITWISE 0b10000000000000000000000000000000
#define EXPONENT_BITWISE 0b01111111111111111111111100000000

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
	// Setting exponent bit
	_fixedNbrValue = ((raw << _fractionalBits) & EXPONENT_BITWISE);
	// Setting signal bit
	_fixedNbrValue |= (raw & SIGNAL_BITWISE);
}

Fixed::Fixed(const float raw) {
	std::cout << "Float constructor called" << std::endl;
	// NAO E POSIVEL QUE E SO MULTIPLICAR https://stackoverflow.com/a/187808
	_fixedNbrValue = roundf(raw * (1 << _fractionalBits));
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& that) {
	std::cout << "Assignation operator called" << std::endl;
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

float Fixed::toFloat(void) const {
	return ((float)_fixedNbrValue / (1 << _fractionalBits));
}

int Fixed::toInt(void) const {
	int exponent = (_fixedNbrValue & EXPONENT_BITWISE) >> _fractionalBits;

	return (exponent);
}

std::ostream& operator<<(std::ostream& oStream, const Fixed& that) {
	// o ostream automaticamente remove 0 extras do float, diferente da printf
	oStream << that.toFloat();
	return (oStream);
}
