/**
 * @file ClapTrap.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File with methods for the ClapTrap class.
 * @version 1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 */

#include "ClapTrap.class.hpp"
#include "defines.hpp"

void ClapTrap::attack(const std::string& target) {
	if (_ep == 0) {
		std::cout << FG_BLUE "ClapTrap " << _name << " is out of energy!" <<
			std::endl;
		return;
	}
	std::cout << FG_MAGENTA "ClapTrap " << _name << " attacks " << target <<
		", causing " << _damage << " points of damage!" << std::endl;
	_ep -= 1;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hp == 0) {
		std::cout << FG_BLUE "ClapTrap " << _name << " is already dead!" <<
			std::endl;
		return;
	}
	std::cout << FG_MAGENTA "ClapTrap " << _name << " takes " << amount <<
		" points of damage!" << std::endl;
	if (amount >= static_cast<unsigned int>(_hp))
		std::cout << FG_RED "ClapTrap " << _name << " is dead!" << std::endl;
	_hp -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_hp == 0) {
		std::cout << FG_BLUE "ClapTrap " << _name << " is already dead!" <<
			std::endl;
		return;
	}
	else if (_ep == 0) {
		std::cout << FG_BLUE "ClapTrap " << _name << " is out of energy!" <<
			std::endl;
		return;
	}
	std::cout << FG_MAGENTA "ClapTrap " << _name << " is repaired with " <<
		amount << " points of energy!" << std::endl;
	_ep -= 1;
	_hp += amount;
}

int ClapTrap::getHitPoints(void) const {
	return (_hp);
}

int ClapTrap::getEnergyPoints(void) const {
	return (_ep);
}

int ClapTrap::getDamage(void) const {
	return (_damage);
}

std::string ClapTrap::getName(void) const {
	return (_name);
}

void ClapTrap::setHitPoints(int newHp) {
	_hp = newHp;
}

void ClapTrap::setEnergyPoints(int newEp) {
	_ep = newEp;
}

void ClapTrap::setDamage(int newDamage) {
	_damage = newDamage;
}

void ClapTrap::setName(std::string newName) {
	_name = newName;
}
