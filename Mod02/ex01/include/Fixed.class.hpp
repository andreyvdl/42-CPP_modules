/**
 * @file Fixed.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the Fixed class declaration.
 * @version 1
 * @date 2023-11-17
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP
# include <iostream>

class Fixed {
	private:
		int _fixedNbrValue;
		static const int _fractionalBits;

	public:
		Fixed(void);
		Fixed(const Fixed& that);
		~Fixed(void);
		Fixed& operator=(const Fixed& that);

		int getRawBits(void) const;
		void setRawBits(const int raw);

		Fixed(const int raw);
		Fixed(const float raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& oStream, const Fixed& that);

#endif
