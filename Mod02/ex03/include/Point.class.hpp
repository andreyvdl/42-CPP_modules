/**
 * @file Point.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the Point class declaration.
 * @version 1
 * @date 2023-11-21
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef POINT_CLASS_HPP
# define POINT_CLASS_HPP
# include "Fixed.class.hpp"

class Point {
	private:
		Fixed const _x;
		Fixed const _y;

	public:
		Point(void);
		Point(Point const& that);
		~Point(void);
		Point& operator=(Point const& that);

		Point(float const x, float const y);
		Fixed const& getX(void) const;
		Fixed const& getY(void) const;
		bool operator==(Point const& that) const;
		// bool operator!=(Point const& that) const;
};

#endif
