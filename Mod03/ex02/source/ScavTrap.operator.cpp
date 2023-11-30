/**
 * @file ScavTrap.operator.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for operators overload of the ScavTrap class.
 * @version 1
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
 */

#include "ScavTrap.class.hpp"
#include "defines.hpp"
#include <iostream>

ScavTrap& ScavTrap::operator=(ScavTrap const& that) {
	std::cout << FG_BD_CYAN "ScavTrap assignation operator called." RESET
		<< std::endl;
	if (this != &that) {
		_name = that.getName();
		_hp = that.getHitPoints();
		_ep = that.getEnergyPoints();
		_damage = that.getDamage();
	}
	return (*this);
}
