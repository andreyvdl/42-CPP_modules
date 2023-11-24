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

bool triangleIsInvalid(Point const a, Point const b, Point const c);
float heronFormula(Point const a1, Point const b1, Point const c1);
Fixed getHeight(Point const a2, Point const b2);

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	Fixed triangleArea;
	Fixed subArea1;
	Fixed subArea2;
	Fixed subArea3;

	if (triangleIsInvalid(a, b, c))
		return (false);
	if (point == a || point == b || point == c)
		return (false);
	triangleArea = Fixed(heronFormula(a, b, c));
	subArea1 = Fixed(heronFormula(a, b, point));
	subArea2 = Fixed(heronFormula(a, c, point));
	subArea3 = Fixed(heronFormula(b, c, point));
	if (subArea1.toFloat() == 0.0f || subArea2.toFloat() == 0.0f
		|| subArea3.toFloat() == 0.0f
	)
		return (false);
	if (triangleArea != (subArea1 + subArea2 + subArea3))
		return (false);
	return (true);
}

bool triangleIsInvalid(Point const a, Point const b, Point const c) {
	if (a == b || a == c || b == c)
		return (true);
	if ((a.getX() == b.getX() && a.getX() == c.getX())
		|| (a.getY() == b.getY() && a.getY() == c.getY())
	)
		return (true);
	return (false);
}

float heronFormula(Point const a1, Point const b1, Point const c1) {
	Fixed sqrArea;
	// A = 0.5(|1x(2y - 3y) + 2x(3y - 1y) + 3x(1y - 2y)|)

	sqrArea = (a1.getX() * getHeight(b1, c1) + b1.getX() * getHeight(c1, a1)
		+ c1.getX() * getHeight(a1, b1)
	);
	return (fabs(sqrArea.toFloat()) * 0.5f);
}

Fixed getHeight(Point const a2, Point const b2) {
	return (Fixed(a2.getY().toFloat() - b2.getY().toFloat()));
}
