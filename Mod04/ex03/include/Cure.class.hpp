/**
 * @file Cure.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Definition for the Cure class.
 * @version 1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef CURE_CLASS_HPP
# define CURE_CLASS_HPP
# include "AMateria.abstract.hpp"

class Cure: public AMateria
{
	public:
		Cure(void);
		Cure(Cure const& that);
		~Cure(void);
		Cure& operator=(Cure const& that);

		AMateria* clone(void) const;
};


#endif
