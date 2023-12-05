/**
 * @file FragTrap.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the methods of the FragTrap class.
 * @version 1
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
 */

#include "FragTrap.class.hpp"
#include "defines.hpp"
#include <iostream>

void FragTrap::highFivesGuys(void) {
	std::cout << FG_UL_MAGENTA "FragTrap " << getName()
		<< " wants a high five!" RESET << std::endl;
}
