/**
 * @file Point.tructor.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File with constructor and destructor of the Point class.
 * @version 1
 * @date 2023-11-23
 * 
 * @copyright Copyright (c) 2023
 */

#include "Point.class.hpp"

Point::Point(void) : _x(0), _y(0) {};

Point::Point(Point const& that) {
	if (this != &that) {
		const_cast<Fixed&>(_x) = that.getX();
		const_cast<Fixed&>(_y) = that.getY();
	}
}

Point::Point(float const x, float const y) : _x(x), _y(y) {};

Point::~Point(void) {};
