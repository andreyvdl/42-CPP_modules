/**
 * @file Zombie.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the classes constructor and destructor of Zombie.
 * @version 1
 * @date 2023-11-08
 * 
 * @copyright Copyright (c) 2023
 */

#include "Zombie.hpp"
#include "Defines.hpp"

Zombie::Zombie(void) {
	std::cout << FG_GREEN << "Zombie created" << RESET << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << FG_RED << this->getName() << " destroyed" << RESET 
		<< std::endl;
}

std::string Zombie::getName(void) {
	return (this->_name);
}

void Zombie::setName(std::string name) {
	this->_name = name;
}

void Zombie::announce(void) {
	std::cout << FG_CYAN << this->getName() << ": BraiiiiiiinnnzzzZ..."
		<< RESET << std::endl;
}
