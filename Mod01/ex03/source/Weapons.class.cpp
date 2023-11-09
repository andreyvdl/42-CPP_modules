/**
 * @file Weapons.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the methods of the Weapon class.
 * @version 1
 * @date 2023-11-09
 * 
 * @copyright Copyright (c) 2023
 */

#include "Weapon.class.hpp"

Weapon::Weapon(std::string type) : _type(type) {};

Weapon::~Weapon(void) {};

const std::string& Weapon::getType(void) const {
	return _type;
}

void Weapon::setType(std::string type) {
	_type = type;
}
