/**
 * @file HumanA.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for HumanA class methods.
 * @version 1
 * @date 2023-11-09
 * 
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include "HumanA.class.hpp"

HumanA::HumanA(std::string name, Weapon weapon) : _name(name),
_weapon(weapon) {};

HumanA::~HumanA(void) {};

void HumanA::attack(void) const {
	std::cout << _name << " attack with their " << _weapon.getType()
		<< std::endl;
}
