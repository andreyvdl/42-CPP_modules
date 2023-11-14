/**
 * @file HumanB.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for HumanB class methods.
 * @version 1
 * @date 2023-11-09
 * 
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include "HumanB.class.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {};

HumanB::~HumanB(void) {};

void HumanB::setWeapon(Weapon& weapon) {
	_weapon = &weapon;
}

void HumanB::attack(void) const {
	std::cout << _name << " attack with their "
		<< (_weapon != NULL ? _weapon->getType() : "hand") << std::endl;
}
