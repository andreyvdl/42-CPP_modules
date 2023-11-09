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

		void setName(std::string name);
		std::string getName(void);

		/**
		 * @brief Prints the name of the zombie followed by the phrase
		 * "BraiiiiiiinnnzzzZ...".
		 */
		void announce(void);
};

/**
 * @brief Creates a zombie object on the heap.
 * 
 * @param name the name of the zombie.
 * @return A pointer to the zombie.
 */
Zombie* newZombie(std::string name);

/**
 * @brief Create a zombie object on the stack that will call announce.
 * 
 * @param name the name of the zombie.
 */
void randomChump(std::string name);

#endif
