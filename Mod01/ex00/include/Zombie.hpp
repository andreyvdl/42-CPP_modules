/**
 * @file Zombie.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief A zombie class file.
 * @version 1
 * @date 2023-11-08
 * 
 * @copyright Copyright (c) 2023
 */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie {
	private:
		std::string _name;

	public:
		Zombie(void);
		~Zombie(void);

		void announce(void);
		void setName(std::string name);
		std::string getName(void);
};
Zombie* newZombie(std::string name);
void randomChump(std::string name);

#endif
