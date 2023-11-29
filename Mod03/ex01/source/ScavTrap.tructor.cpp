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

ScavTrap::ScavTrap(void) : _name("NoName"), _hp(100), _ep(50), _damage(20) {
	std::cout << FG_GREEN "ScavTrap default constructor called." RESET
		<< std::endl;
}

ScavTrap::ScavTrap(std::string name) : _name(name), _hp(100), _ep(50),
_damage(20) {
	std:cout << FG_GREEN "ScavTrap name constructor called." RESET
		<< std::endl;
}
