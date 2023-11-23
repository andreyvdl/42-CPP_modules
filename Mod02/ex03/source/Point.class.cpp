/**
 * @file Point.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File with methods of the Point class.
 * @version 1
 * @date 2023-11-23
 * 
 * @copyright Copyright (c) 2023
 */

#include "Point.class.hpp"

Fixed const& Point::getX(void) const {
	return (_x);
}

Fixed const& Point::getY(void) const {
	return (_y);
}
