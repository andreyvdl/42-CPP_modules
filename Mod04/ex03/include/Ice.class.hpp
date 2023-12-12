/**
 * @file Ice.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Definition of the Ice class.
 * @version 1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef ICE_CLASS_HPP
# define ICE_CLASS_HPP
# include "AMateria.abstract.hpp"

class Ice: public AMateria
{
	private:

	public:
		Ice(void);
		Ice(Ice const& that);
		~Ice(void);
		Ice& operator=(Ice const& that);

		AMateria* clone(void) const;
		void use(ICharacter& target);
};

#endif
