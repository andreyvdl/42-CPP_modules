/**
 * @file FragTrap.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the FragTrap class.
 * @version 1
 * @date 2023-11-30
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef FRAGTRAP_CLASS_HPP
# define FRAGTRAP_CLASS_HPP
# include <iostream>
# include "ClapTrap.class.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const& that);
		~FragTrap(void);
		FragTrap& operator=(FragTrap const& that);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void highFivesGuys(void);
};

#endif
