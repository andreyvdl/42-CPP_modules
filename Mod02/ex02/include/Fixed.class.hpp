/**
 * @file Fixed.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the Fixed class declaration.
 * @version 1
 * @date 2023-11-20
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
		Fixed(int const raw);
		Fixed(float const raw);
		Fixed(Fixed const& that);
		~Fixed(void);

		Fixed& operator=(Fixed const& that);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		// comparacao
		bool operator>(Fixed const& that) const;
		bool operator<(Fixed const& that) const;
		bool operator>=(Fixed const& that) const;
		bool operator<=(Fixed const& that) const;
		bool operator==(Fixed const& that) const;
		bool operator!=(Fixed const& that) const;
		// aritmetica
		Fixed operator+(Fixed const& that) const;
		Fixed operator-(Fixed const& that) const;
		Fixed operator*(Fixed const& that) const;
		Fixed operator/(Fixed const& that) const;
		// -cremento
		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);
		// min max
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& min(Fixed const& a, Fixed const& b);
		static const Fixed& max(Fixed const& a, Fixed const& b);
};

std::ostream& operator<<(std::ostream& oStream, Fixed const& that);

#endif
