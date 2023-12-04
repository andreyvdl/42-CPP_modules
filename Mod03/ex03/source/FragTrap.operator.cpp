/**
 * @file FragTrap.operator.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the operator overloads of the FragTrap class.
 * @version 1
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
 */

#include "FragTrap.class.hpp"
#include "defines.hpp"
#include <iostream>

FragTrap& FragTrap::operator=(FragTrap const& that) {
	std::cout << FG_UL_GREEN << "FragTrap assignation operator called."
		<< RESET << std::endl;
	if (this != &that) {
		_name = that.getName();
		_hp = that.getHitPoints();
		_ep = that.getEnergyPoints();
		_damage = that.getDamage();
	}
	return (*this);
}
