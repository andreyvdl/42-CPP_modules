/**
 * @file HumanB.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the HumanB class.
 * @version 1
 * @date 2023-11-09
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef HUMAN_B_CLASS_HPP
# define HUMAN_B_CLASS_HPP

#include "Weapon.class.hpp"
#include <iostream>

class HumanB {
	private:
		std::string _name;
		Weapon* _weapon;

	public:
		HumanB(std::string name);
		~HumanB(void);

		void setWeapon(Weapon& weapon);
		void attack(void) const;
};

#endif
