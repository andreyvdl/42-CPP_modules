/**
 * @file newZombie.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the creation of zombies on heap.
 * @version 1
 * @date 2023-11-08
 * 
 * @copyright Copyright (c) 2023
 */

#include "Zombie.hpp"

Zombie* newZombie(std::string name) {
	Zombie* zombie = new Zombie;

	zombie->setName(name);
	return (zombie);
}
