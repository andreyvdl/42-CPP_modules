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
	return (Fixed(toFloat() + that.toFloat()));
}

Fixed Fixed::operator-(Fixed const& that) const {
	return (Fixed(toFloat() - that.toFloat()));
}

Fixed Fixed::operator/(Fixed const& that) const {
	if (that.toFloat() == 0.000000000f) {
		std::cout << "WARNING YOUR PC WILL EXPLODE!!!!!!!!!!!!!!" << std::endl;
		return (Fixed(0));
	}
	return (Fixed(toFloat() / that.toFloat()));
}

Fixed Fixed::operator*(Fixed const& that) const {
	return (Fixed(toFloat() * that.toFloat()));
}

Fixed& Fixed::operator++(void) {
	_fixedNbrValue += 1; // 🤡
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);

	++(*this);
	return (temp);
}

Fixed& Fixed::operator--(void) {
	_fixedNbrValue -= 1; // 🤡
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);

	--(*this);
	return (temp);
}
