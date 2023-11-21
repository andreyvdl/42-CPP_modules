/**
 * @file Point.operator.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File with operator overloads of the Point class.
 * @version 1
 * @date 2023-11-21
 * 
 * @copyright Copyright (c) 2023
 */

#include "Point.class.hpp"
#include "Fixed.class.hpp"

Point& Point::operator=(Point const& that) {
	if (this != &that) {
		const_cast<Fixed&>(_x) = that.getX();
		const_cast<Fixed&>(_y) = that.getY();
	}
	return (*this);
}

bool Point::operator==(Point const& that) const {
	if (this == &that)
		return (true);
	return (getX() == that.getX() && getY() == that.getY() ? true : false);
}

bool Point::operator!=(Point const& that) const {
	if (this == &that)
		return (false);
	return (getX() != that.getX() || getY() != that.getY() ? true : false);
}
