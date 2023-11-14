/**
 * @file HumanA.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the HumanA class.
 * @version 1
 * @date 2023-11-09
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef HUMAN_A_CLASS_HPP
# define HUMAN_A_CLASS_HPP

#include <iostream>
#include "Weapon.class.hpp"

class HumanA {
	private:
		std::string _name;
		Weapon* _weapon;

	public:
		HumanA(std::string name, Weapon& weapon);
		~HumanA(void);

		void setWeapon(Weapon& weapon);
		void attack(void) const;
};

#endif
