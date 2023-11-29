/**
 * @file ClapTrap.operator.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief operators overload for the ClapTrap class.
 * @version 1
 * @date 2023-11-24
 * 
 * @copyright Copyright (c) 2023
 */

#include "ClapTrap.class.hpp"
#include "defines.hpp"

ClapTrap& ClapTrap::operator=(ClapTrap const& that) {
	std::cout << FG_CYAN "ClapTrap assignation operator called" << std::endl;
	if (this != &that) {
		_name = that._name;
		_hp = that._hp;
		_ep = that._ep;
		_damage = that._damage;
	}
	return (*this);
}
