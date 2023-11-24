/**
 * @file ClapTrap.tructor.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Constructor and Destruction functions for ClapTrap class.
 * @version 1
 * @date 2023-11-24
 * 
 * @copyright Copyright (c) 2023
 */

#include "ClapTrap.class.hpp"
#include "defines.hpp"

ClapTrap::ClapTrap(void) : _name("NoName"), _hp(10), _ep(10), _attack(0) {
	std::cout << FG_GREEN "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10),
_attack(0) {
	std::cout << FG_GREEN "ClapTrap name constructor called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const& that) {
	std::cout << FG_GREEN "ClapTrap copy constructor called" << std::endl;
	*this = that;
}

ClapTrap::~ClapTrap(void) {
	std::cout << FG_RED "ClapTrap destructor called" << std::endl;
}
