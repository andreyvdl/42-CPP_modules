/**
 * @file main.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Main file to test 
 * @version 1
 * @date 2023-11-09
 * 
 * @copyright Copyright (c) 2023
 */

#include "Zombie.class.hpp"
#include "Defines.hpp"

void intentionalLeak(void);

int main(void) {
	Zombie *horde = zombieHorde(10, "Clicker");

	for (int i = 0; i < 10; i++)
		horde[i].announce();
	delete [] horde;
	// intentionalLeak();
	return (0);
}

void intentionalLeak(void) {
	std::cout << FG_YELLOW
		<< "LEAK TEST ========================================================="
		<< RESET << std::endl;
	Zombie *horde = zombieHorde(10, "LEAKERS");

	for (int i = 0; i < 10; i++)
		horde[i].announce();
	// delete [] horde;
}
