/**
 * @file FragTrap.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the methods of the FragTrap class.
 * @version 1
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
 */

#include "FragTrap.class.hpp"
#include "defines.hpp"
#include <iostream>

void FragTrap::attack(const std::string& target) {
	if (_ep == 0) {
		std::cout << FG_UL_BLUE "FragTrap " << getName()
			<< " is out of energy!" << RESET << std::endl;
		return;
	}
	if (_hp < 1) {
		std::cout << FG_UL_BLUE "FragTrap " << getName()
			<< " is dead!" << RESET << std::endl;
		return;
	}
	std::cout << FG_UL_MAGENTA "FragTrap " << getName() << " attacks "
		<< target << ", causing " << getDamage() << " points of damage!"
		<< RESET << std::endl;
	_ep -= 1;
}

void FragTrap::takeDamage(unsigned int amount) {
	if (_hp < 1) {
		std::cout << FG_UL_BLUE "FragTrap " << getName()
			<< " is already dead!" << RESET << std::endl;
		return;
	}
	std::cout << FG_UL_MAGENTA "FragTrap " << getName() << " takes "
		<< amount << " points of damage!" << RESET << std::endl;
	_hp -= amount;
	if (_hp < 1) {
		std::cout << FG_UL_RED "FragTrap " << getName()
			<< " is dead!" << RESET << std::endl;
	}
}

void FragTrap::beRepaired(unsigned int amount) {
	if (_hp < 1) {
		std::cout << FG_UL_BLUE "FragTrap " << getName()
			<< " is already dead!" << RESET << std::endl;
		return;
	}
	if (_ep == 0) {
		std::cout << FG_UL_BLUE "FragTrap " << getName()
			<< " is out of energy!" << RESET << std::endl;
		return;
	}
	std::cout << FG_UL_MAGENTA "FragTrap " << getName() << " is repaired with "
		<< amount << " points of energy!" << RESET << std::endl;
	_hp += amount;
	_ep -= 1;
}

void FragTrap::highFivesGuys(void) {
	std::cout << FG_UL_MAGENTA "FragTrap " << getName()
		<< " wants a high five!" RESET << std::endl;
}
