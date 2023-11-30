/**
 * @file ScavTrap.tructor.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File with the constructors and destructors of the ScavTrap class.
 * @version 1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 */

#include "ScavTrap.class.hpp"
#include "defines.hpp"
#include <iostream>

ScavTrap::ScavTrap(void): ClapTrap() {
	std::cout << FG_BD_GREEN "ScavTrap default constructor called." RESET
		<< std::endl;
	_hp = 100;
	_ep = 50;
	_damage = 20;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name) {
	std::cout << FG_BD_GREEN "ScavTrap name constructor called." RESET
		<< std::endl;
	_hp = 100;
	_ep = 50;
	_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap const& that) {
	std::cout << FG_BD_GREEN "ScavTrap copy constructor called." RESET
		<< std::endl;
	*this = that;
}

ScavTrap::~ScavTrap(void) {
	std::cout << FG_BD_RED "ScavTrap destructor called." RESET
		<< std::endl;
}
