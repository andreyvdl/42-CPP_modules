/**
 * @file bsp.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the function Binary Space Partitioning.
 * @version 1
 * @date 2023-11-21
 * 
 * @copyright Copyright (c) 2023
 */

#include "Point.class.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	if (point == a || point == b || point == c)
		return (false);
	if (a == b || a == c || b == c)
		return (false);

	
}
