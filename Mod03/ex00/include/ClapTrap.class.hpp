/**
 * @file ClapTrap.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Definition of the ClapTrap class.
 * @version 1
 * @date 2023-11-24
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef CLAPTRAP_CLASS_H
# define CLAPTRAP_CLASS_H
# include <iostream>

// hp = hit points
// ep = energy points
class ClapTrap {
	private:
		std::string _name;
		int _hp;
		int _ep;
		int _damage;

	public:
		ClapTrap(void);
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const& that);
		~ClapTrap(void);
		ClapTrap& operator=(ClapTrap const& that);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		void setHitPoints(int newHp);
		int getHitPoints(void) const;
		void setEnergyPoints(int newEp);
		int getEnergyPoints(void) const;
		void setDamage(int newDamage);
		int getDamage(void) const;
		void setName(std::string newName);
		std::string getName(void) const;
};

#endif
