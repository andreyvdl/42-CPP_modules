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

void DiamondTrap::attack(std::string const& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void) {
	std::cout << BG_MAGENTA "DiamondTrap name is " << _name
		<< " ClapTrap name is "<< ClapTrap::getName() << "!" RESET << std::endl;
}

std::string DiamondTrap::getDiamondName(void) const {
	return (_name);
}

void DiamondTrap::setDiamondName(std::string name) {
	_name = name;
}
