/**
 * @file ScavTrap.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the ScavTrap class definition.
 * @version 1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef SCAVTRAP_CLASS_H
# define SCAVTRAP_CLASS_H
# include <iostream>
# include "ClapTrap.class.hpp"

class ScavTrap: public ClapTrap {
	private:
		std::string _name;
		int _hp;
		int _ep;
		int _damage;

	public:
		ScavTrap(void);
		ScavTrap(ScavTrap const& that);
		~ScavTrap(void);
		ScavTrap& operator=(ScavTrap const& that);
};

#endif
