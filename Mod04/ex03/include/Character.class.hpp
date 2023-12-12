/**
 * @file Character.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Definition of the Character class.
 * @version 1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef CHARACTER_CLASS_HPP
# define CHARACTER_CLASS_HPP
# define MAX_DROP 1024 // se quiser taca 4096
# include <iostream>
# include "ICharacter.interface.hpp"
# include "AMateria.abstract.hpp"

class Character: public ICharacter
{
	private:
		AMateria* _inventory[4];
		std::string _name;
		AMateria* _dropped[MAX_DROP];

	public:
		Character(void);
		Character(std::string const& name);
		Character(Character const& that);
		~Character(void);
		Character& operator=(Character const& that);

		std::string const& getName(void) const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif
