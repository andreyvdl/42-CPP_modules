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

class FragTrap: virtual public ClapTrap {
	protected:
		static const int _defaultHp = 100;
		static const int _defaultDamage = 30;

	public:
		FragTrap(void);
		FragTrap(std::string name);
		FragTrap(FragTrap const& that);
		~FragTrap(void);
		FragTrap& operator=(FragTrap const& that);

		void highFivesGuys(void);
};

#endif
