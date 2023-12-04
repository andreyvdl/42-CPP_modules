/**
 * @file DiamondTrap.operator.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File with DiamondTrap operator overloads.
 * @version 1
 * @date 2023-12-04
 * 
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include "DiamondTrap.class.hpp"
#include "defines.hpp"

DiamondTrap& DiamondTrap::operator=(DiamondTrap const& that) {
	std::cout << BG_CYAN "DiamondTrap assignation operator called." RESET
		<< std::endl;
	if (this != &that) {
		this->setName(that.getName());
		this->setHitPoints(that.getHitPoints());
		this->setEnergyPoints(that.getEnergyPoints());
		this->setDamage(that.getDamage());
	}
	return (*this);
}
