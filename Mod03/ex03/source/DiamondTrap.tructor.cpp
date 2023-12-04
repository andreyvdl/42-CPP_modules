/**
 * @file DiamondTrap.tructor.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File with the constructors and destructors of the DiamondTrap class.
 * @version 1
 * @date 2023-12-04
 * 
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include "DiamondTrap.class.hpp"
#include "defines.hpp"
#define SUFFIX_NAME "_clap_name"

DiamondTrap::DiamondTrap(void): FragTrap(), ScavTrap() {
	std::cout << BG_GREEN "DiamondTrap default constructor called." RESET
		<< std::endl;
	_name = "noName";
	ClapTrap::_name = "noName" + SUFFIX_NAME;
	_hp = FragTrap::_hp;
	_ep = ScavTrap::_ep;
	_damage = FragTrap::_damage;
}

DiamondTrap::DiamondTrap(std::string name): FragTrap(name), ScavTrap(name) {
	std::cout << BG_GREEN "DiamondTrap name constructor called." RESET
		<< std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const& that) {
	std::cout << BG_GREEN "DiamondTrap copy constructor called." RESET
		<< std::endl;
	*this = that;
}

DiamondTrap::~DiamondTrap(void) {
	std::cout << BG_RED "DiamondTrap destructor called." RESET << std::endl;
}
