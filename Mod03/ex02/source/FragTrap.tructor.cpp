/**
 * @file FragTrap.tructor.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File with constructors and destructors for the FragTrap class.
 * @version 1
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
 */

#include "FragTrap.class.hpp"
#include "defines.hpp"
#include <iostream>

FragTrap::FragTrap(void): ClapTrap() {
	std::cout << FG_UL_GREEN << "FragTrap default constructor called."
		<< RESET << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setDamage(30);
}

FragTrap::FragTrap(std::string name): ClapTrap(name) {
	std::cout << FG_UL_GREEN << "FragTrap name constructor called."
		<< RESET << std::endl;
	setHitPoints(100);
	setEnergyPoints(100);
	setDamage(30);
}

FragTrap::FragTrap(FragTrap const& that) {
	std::cout << FG_UL_GREEN << "FragTrap copy constructor called."
		<< RESET << std::endl;
	*this = that;
}

FragTrap::~FragTrap(void) {
	std::cout << FG_UL_RED << "FragTrap destructor called."
		<< RESET << std::endl;
}
