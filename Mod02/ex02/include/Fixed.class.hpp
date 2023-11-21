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
# include <cmath>
# define SIGNAL_BITWISE (0b1U << 31)
# define EXPONENT_BITWISE (0b11111111111111111111111 << 8)
# define FRACTIONAL_BITWISE 0b11111111
# define FRACTIONAL_FACTOR(bits) (0b1 << bits)

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
		static Fixed const& min(Fixed const& a, Fixed const& b);
		static Fixed const& max(Fixed const& a, Fixed const& b);
};

std::ostream& operator<<(std::ostream& oStream, Fixed const& that);

#endif
