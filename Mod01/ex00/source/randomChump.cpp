/**
 * @file randomChump.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the creation of a zombie in the stack
 * @version 1
 * @date 2023-11-08
 * 
 * @copyright Copyright (c) 2023
 */

#include "Zombie.hpp"

void randomChump(std::string name) {
	Zombie zombie;

	zombie.setName(name);
	zombie.announce();
}
