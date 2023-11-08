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

Zombie::Zombie(void) {
	std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << "Zombie destroyed" << std::endl;
}

void Zombie::announce(void) {
	std::cout << this->getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->_name = name;
}

std::string Zombie::getName(void) {
	return (this->_name);
}
