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
#include <cmath>

bool triangleIsInvalid(Point const a, Point const b, Point const c,
	Point const p
) {
	if ((p == a || p == b || p == c) || (a == b || a == c || b == c))
		return (true);
	if ((a.getX() == b.getX() && a.getX() == c.getX())
		|| (a.getY() == b.getY() && a.getY() == c.getY())
	)
		return (true);
	return (false);
}

Fixed triangleHeight(Point const a, Point const b, Point const c) {
	return (Fixed::max(a.getY(), Fixed::max(b.getY(), c.getY()))
		- Fixed::min(a.getY(), Fixed::min(b.getY(), c.getY()))
	);
}

Fixed triangleWidth(Point const a, Point const b, Point const c) {
	return (Fixed::max(a.getX(), Fixed::max(b.getX(), c.getX()))
		- Fixed::min(a.getX(), Fixed::min(b.getX(), c.getX()))
	);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed triangleArea;
	Fixed subArea1;
	Fixed subArea2;
	Fixed subArea3;

	if (triangleIsInvalid(a, b, c, point))
		return (false);
	triangleArea = Fixed(static_cast<const float>(fabs()));
	// triangleArea = (triangleHeight(a, b, c) * triangleWidth(a, b, c))
	// 	/ Fixed(2.0f);
	// subArea1 = (triangleHeight(a, b, point) * triangleWidth(a, b, point))
	// 	/ Fixed(2.0f);
	// subArea2 = (triangleHeight(a, c, point) * triangleWidth(a, c, point))
	// 	/ Fixed(2.0f);
	// subArea3 = (triangleHeight(b, point, c) * triangleWidth(b, point, c))
	// 	/ Fixed(2.0f);
	// std::cout << "triangleArea: " << triangleArea << std::endl;
	// std::cout << "subArea1: " << subArea1 << std::endl;
	// std::cout << "subArea2: " << subArea2 << std::endl;
	// std::cout << "subArea3: " << subArea3 << std::endl;
	// std::cout << "total sub: " << subArea1 + subArea2 + subArea3 << std::endl;
	// if (subArea1 + subArea2 + subArea3 != triangleArea 
	// 	&& subArea1 + subArea2 + (subArea3 / Fixed(2.0f)) != triangleArea
	// )
	// 	return (false);
	return (true);
}
