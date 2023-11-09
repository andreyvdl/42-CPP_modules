/**
 * @file main.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Main test file.
 * @version 1
 * @date 2023-11-09
 * 
 * @copyright Copyright (c) 2023
 */

#include "Zombie.hpp"
#include "Defines.hpp"

void intentionalLeak(void);
void impossibleToLeak(void);
void impossibleToLeak2(void);

int main(void) {
	std::cout << FG_YELLOW
		<< "MAIN TEST ========================================================="
		<< RESET << std::endl;
	Zombie* zombie = newZombie("Leon");
	Zombie zombie2;

	zombie2.setName("Ada");
	randomChump("Claire");
	zombie->announce();
	delete zombie;
	zombie2.announce();
	std::cout << FG_YELLOW
		<< "LEAK TEST ========================================================="
		<< RESET << std::endl;
	// intentionalLeak();
	impossibleToLeak();
	impossibleToLeak2();
	std::cout << FG_YELLOW
		<< "SYSTEM KILL ADA ==================================================="
		<< RESET << std::endl;
	return (0);
}

void intentionalLeak(void) {
	Zombie* leaker = newZombie("Boomer");

	leaker->announce();
	//delete leaker;
}

void impossibleToLeak(void) {
	Zombie leaker;

	leaker.setName("Chris");
	leaker.announce();
}

void impossibleToLeak2(void) {
	randomChump("Jill");
}
