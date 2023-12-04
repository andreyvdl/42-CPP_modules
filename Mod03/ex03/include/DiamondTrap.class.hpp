/**
 * @file DiamondTrap.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File with the DiamondTrap class definition.
 * @version 1
 * @date 2023-12-04
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef DIAMONDTRAP_CLASS_HPP
# define DIAMONDTRAP_CLASS_HPP

# include <iostream>
# include "FragTrap.class.hpp"
# include "ScavTrap.class.hpp"

class DiamondTrap: public FragTrap, public ScavTrap {
	private:
		std::string _name;
		FragTrap::_hp;
		ScavTrap::_ep;
		FragTrap::_damage;

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const& that);
		~DiamondTrap(void);
		DiamondTrap& operator=(DiamondTrap const& that);

		// overload for printing right name
		void attack(const std::string& target);
		void guardGate(void);
		void highFivesGuys(void);

		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		void whoAmI(void);
};

#endif
