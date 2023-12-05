/**
 * @file ScavTrap.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the ScavTrap class.
 * @version 1
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
 */

#include "ScavTrap.class.hpp"
#include "defines.hpp"
#include <iostream>

void ScavTrap::attack(const std::string& target) {
	if (_ep == 0) {
		std::cout << FG_BD_BLUE "ScavTrap " << getName()
			<< " is out of energy!" << RESET << std::endl;
		return;
	}
	if (_hp < 1) {
		std::cout << FG_BD_BLUE "ScavTrap " << getName()
			<< " is dead!" << RESET << std::endl;
		return;
	}
	std::cout << FG_BD_MAGENTA "ScavTrap " << getName() << " attacks "
		<< target << ", causing " << getDamage() << " points of damage!"
		<< RESET << std::endl;
	_ep -= 1;
}

void ScavTrap::guardGate(void) {
	std::cout << FG_BD_MAGENTA "ScavTrap " << getName()
		<< " has entered in Gate keeper mode." << RESET << std::endl;
}
