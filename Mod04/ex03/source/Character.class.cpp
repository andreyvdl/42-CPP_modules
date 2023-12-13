/**
 * @file Character.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Methods of the Character class.
 * @version 1
 * @date 2023-12-12
 * 
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include "Character.class.hpp"
#include "ICharacter.interface.hpp"
#include "AMateria.abstract.hpp"

void removeMateria(int idx, AMateria** inventory, AMateria** dropped);
void cloneDropped(AMateria** dropped, AMateria** that);
void cloneInventory(AMateria** inventory, AMateria** that);
void deleteDropped(AMateria** dropped);
void deleteInventory(AMateria** inventory);
void initDropped(AMateria** dropped);
void initInventory(AMateria** inventory);

/* TRUCTORS ================================================================= */

Character::Character(void)
{
	_name = "noName";
	initInventory(_inventory);
	initDropped(_dropped);
}

Character::Character(std::string const& name)
{
	_name = name;
	initInventory(_inventory);
	initDropped(_dropped);
}

Character::Character(Character const& that)
{
	initInventory(_inventory);
	initDropped(_dropped);
	*this = that;
}

Character::~Character(void)
{
	deleteInventory(_inventory);
	deleteDropped(_dropped);
}

/* OPERATORS ================================================================ */

Character& Character::operator=(Character const& that)
{
	if (this != &that)
	{
		_name = that._name;
		deleteInventory(_inventory);
		deleteDropped(_dropped);
		cloneInventory(_inventory, const_cast<AMateria**>(that._inventory));
		cloneDropped(_dropped, const_cast<AMateria**>(that._dropped));
	}
	return (*this);
}

/* METHODS ================================================================== */

std::string const& Character::getName(void) const
{
	return (_name);
}

void Character::equip(AMateria* m)
{
	for (size_t i = 0; i < 4; i++) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return ;
		}
	}
	std::cout << "Invetory is full." << std::endl;
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx > 3) {
		std::cout << "Invalid index." << std::endl;
	}
	else if (_inventory[idx] == NULL) {
		std::cout << "No materia equiped!" << std::endl;
	}
	else {
		removeMateria(idx, _inventory, _dropped);
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx > 3) {
		std::cout << "Invalid index." << std::endl;
	}
	else if (_inventory[idx] == NULL) {
		std::cout << "No materia for use!" << std::endl;
	}
	else {
		_inventory[idx]->use(target);
	}
}

void initInventory(AMateria** inventory)
{
	for (size_t i = 0; i < 4; i++) {
		inventory[i] = NULL;
	}
}

void initDropped(AMateria** dropped)
{
	for (size_t i = 0; i < MAX_DROP; i++) {
		dropped[i] = NULL;
	}
}

void deleteInventory(AMateria** inventory)
{
	for (size_t i = 0; i < 4; i++) {
		if (inventory[i] != NULL) {
			delete inventory[i];
			inventory[i] = NULL;
		}
	}
}

void deleteDropped(AMateria** dropped)
{
	for (size_t i = 0; i < MAX_DROP; i++) {
		if (dropped[i] != NULL) {
			delete dropped[i];
			dropped[i] = NULL;
		}
	}
}

void cloneInventory(AMateria** inventory, AMateria** that)
{
	for (size_t i = 0; i < 4; i++) {
		if (that[i] != NULL) {
			inventory[i] = that[i]->clone();
		}
	}
}

void cloneDropped(AMateria** dropped, AMateria** that)
{
	for (size_t i = 0; i < MAX_DROP; i++) {
		if (that[i] != NULL) {
			dropped[i] = that[i]->clone();
		}
	}
}

void removeMateria(int idx, AMateria** inventory, AMateria** dropped)
{
	size_t i = 0;

	while (i < MAX_DROP) {
		if (dropped[i] == NULL) {
			break;
		}
		++i;
	}
	if (i == MAX_DROP) {
		std::cout << "Floor is full, deleting materia..." << std::endl;
		delete inventory[idx];
	}
	else {
		dropped[i] = inventory[idx];
	}
	inventory[idx] = NULL;
}
