/**
 * @file Fixed.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File with declaration of Fixed(OCF) class.
 * @version 1
 * @date 2023-11-16
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef FIXED_CLASS_HPP
# define FIXED_CLASS_HPP

class Fixed {
	private:
		int _fixedNbrValue;
		static const int _fractionalBits;

	public:
		Fixed(void);
		Fixed(const Fixed& that);
		~Fixed(void);
		Fixed& operator = (const Fixed& that);

		int getRawBits(void) const;
		void setRawBits(const int raw);
};

#endif
