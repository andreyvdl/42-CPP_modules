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

	public:
		DiamondTrap(void);
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const& that);
		~DiamondTrap(void);
		DiamondTrap& operator=(DiamondTrap const& that);

		void attack(const std::string& target);
		void whoAmI(void);

		std::string getDiamondName(void) const;
		void setDiamondName(std::string name);
};

#endif
