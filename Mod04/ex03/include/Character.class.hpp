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
# include <iostream>
# include "ICharacter.interface.hpp"

class Character: public ICharacter
{
	private:
		AMateria* _inventory[4];
		std::string _name;

	public:
		Character(void);
		Character(std::string const& name);
		Character(Character const& that);
		~Character(void);
		Character& operator=(Character const& that);
};

#endif
