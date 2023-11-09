/**
 * @file Zombie.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for methods of the Zombie class.
 * @version 1
 * @date 2023-11-09
 * 
 * @copyright Copyright (c) 2023
 */

#include "Zombie.class.hpp"
#include "Defines.hpp"

Zombie::Zombie(void) {
	std::cout << FG_GREEN << "Zombie created!" << RESET << std::endl;
}

Zombie::~Zombie(void) {
	std::cout << FG_RED << _name << " destroyed!" << RESET << std::endl;
}

void Zombie::setName(std::string name) {
	// aparentemente da pra fazer isso sem o this se os nomes forem diferentes
	_name = name;
}

void Zombie::announce(void) {
	std::cout << FG_CYAN << _name << ": BraiiiiiiinnnzzzZ..." << RESET
		<< std::endl;
}
