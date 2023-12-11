/**
 * @file ICharacter.interface.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Definition of the ICharacter class.
 * @version 1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef ICHARACTER_INTERFACE_HPP
# define ICHARACTER_INTERFACE_HPP
# include "AMateria.abstract.hpp"

class ICharacter
{
	public:
		virtual ~ICharacter(void);
		virtual std::string const& getName(void) const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif
