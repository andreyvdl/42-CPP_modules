/**
 * @file Fixed.operator.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File with operator overloads of the Fixed class.
 * @version 1
 * @date 2023-11-21
 * 
 * @copyright Copyright (c) 2023
 */

#include "Fixed.class.hpp"

Fixed& Fixed::operator=(Fixed const& that) {
	_fixedNbrValue = that.getRawBits();
	return (*this);
}

std::ostream& operator<<(std::ostream& oStream, Fixed const& that) {
	oStream << that.toFloat();
	return (oStream);
}

// new functions

bool Fixed::operator>(Fixed const& that) const {
	return (_fixedNbrValue > that.getRawBits() ? true : false);
}

bool Fixed::operator>=(Fixed const& that) const {
	return (_fixedNbrValue >= that.getRawBits() ? true : false);
}

bool Fixed::operator<(Fixed const& that) const {
	return (_fixedNbrValue < that.getRawBits() ? true : false);
}

bool Fixed::operator<=(Fixed const& that) const {
	return (_fixedNbrValue <= that.getRawBits() ? true : false);
}

bool Fixed::operator==(Fixed const& that) const {
	return (_fixedNbrValue == that.getRawBits() ? true : false);
}

bool Fixed::operator!=(Fixed const& that) const {
	return (_fixedNbrValue != that.getRawBits() ? true : false);
}

Fixed Fixed::operator+(Fixed const& that) const {
	return (Fixed(this->toFloat() + that.toFloat()));
}

Fixed Fixed::operator-(Fixed const& that) const {
	return (Fixed(this->toFloat() - that.toFloat()));
}

Fixed Fixed::operator/(Fixed const& that) const {
	if (that.toFloat() == 0.000000000f) {
		std::cout << "WARNING YOUR PC WILL EXPLODE!!!!!!!!!!!!!!" << std::endl;
		return (Fixed(0));
	}
	return (Fixed(this->toFloat() / that.toFloat()));
}

Fixed Fixed::operator*(Fixed const& that) const {
	float total = this->toFloat() * that.toFloat();
	
	return (Fixed(total / FRACTIONAL_FACTOR(_fractionalBits)));
}

/*
Fixed& Fixed::operator++(void) {

}
*/
