/**
 * @file zombieHorde.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the function zombieHorde.
 * @version 1
 * @date 2023-11-09
 * 
 * @copyright Copyright (c) 2023
 */

#include "Zombie.class.hpp"

Zombie* zombieHorde(int N, std::string name) {
	Zombie* horde = new Zombie[N];

	for (int i = 0; i < N; i++)
		horde[i].setName(name);
	return (horde);
}
