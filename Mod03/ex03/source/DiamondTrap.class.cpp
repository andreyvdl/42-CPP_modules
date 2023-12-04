/**
 * @file DiamondTrap.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File with methods of the DiamondTrap class.
 * @version 1
 * @date 2023-12-04
 * 
 * @copyright Copyright (c) 2023
 */

#include "DiamondTrap.class.hpp"
#include "defines.hpp"

void DiamondTrap::attack(const std::string& target) {
	if (_ep == 0) {
		std::cout << BG_BLUE "DiamondTrap " getName() " is out of energy!"
			<< RESET << std::endl;
		return;
	}
	if (_hp < 1) {
		std::cout << BG_BLUE "DiamondTrap " getName() " is dead!" RESET
			<< std::endl;
		return;
	}
	std::cout << BG_MAGENTA "DiamondTrap " getName() " attacks " target
		<< ", causing " getDamage() " points of damage!" RESET << std::endl;
	_ep -= 1;
}

void DiamondTrap::guardGate(void) {
	std::cout << BG_MAGENTA "DiamondTrap " getName()
		<< " has entered in Gate keeper mode." RESET << std::endl;
}

void DiamondTrap::highFivesGuys(void) {
	std::cout << BG_MAGENTA "DiamondTrap " getName() " wants a high five!"
		<< RESET << std::endl;
}

void DiamondTrap::takeDamage(unsigned int amount) {
	if (_hp < 1) {
		std::cout << BG_BLUE "DiamondTrap " _name " is already dead!"
			<< std::endl;
		return;
	}
	std::cout << BG_MAGENTA "DiamondTrap " _name " takes " amount
		<< " points of damage!" << std::endl;
	_hp -= amount;
	if (_hp < 1)
		std::cout << BG_RED "DiamondTrap " _name " is dead!" << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount) {
	if (_hp < 1) {
		std::cout << BG_BLUE "DiamondTrap " _name " is already dead!"
			<< std::endl;
		return;
	}
	if (_ep == 0) {
		std::cout << BG_BLUE "DiamondTrap " _name " is out of energy!"
			<< std::endl;
		return;
	}
	std::cout << BG_MAGENTA "DiamondTrap " _name " is repaired with "
		<< amount " points of energy!" << std::endl;
	_hp += amount;
	_ep -= 1;
}

void DiamondTrap::whoAmI(void) {
	std::cout << BG_MAGENTA "DiamondTrap " _name " is " getName() "!"
		<< std::endl;
}
