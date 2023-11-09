/**
 * @file Weapon.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the Weapon class.
 * @version 1
 * @date 2023-11-09
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

#include <iostream>

class Weapon {
	private:
		std::string _type;

	public:
		Weapon(std::string type);
		~Weapon(void);

		const std::string& getType(void) const;
		void setType(std::string type);
};

#endif
