/**
 * @file Zombie.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the Zombie class.
 * @version 1
 * @date 2023-11-09
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

		void setName(std::string name);
		void announce(void);
};

/**
 * @brief Creates a horde of zombies on the heap.
 * 
 * @param N the number of zombies to be created.
 * @param name the name of ALL zombies.
 * @return A pointer to the zombie at the start of the horde.
 */
Zombie* zombieHorde(int N, std::string name);

#endif
