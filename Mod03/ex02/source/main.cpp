/**
 * @file main.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File with main tests for the ClapTrap class.
 * @version 1
 * @date 2023-11-29
 * 
 * @copyright Copyright (c) 2023
 */

#include <cstdlib>
#include <ctime>
#include "FragTrap.class.hpp"

namespace tests {
	void round(FragTrap& attacker, FragTrap& adversary) {
		switch (rand() % 3) {
			case 0:
				attacker.attack(adversary.getName());
				adversary.takeDamage(attacker.getDamage());
				break;
			case 1:
				attacker.beRepaired(rand() % 10 + 1);
				break;
			case 2:
				attacker.highFivesGuys();
		}
	}

	void fight(FragTrap& fragA, FragTrap& fragB) {
		std::srand(std::time(NULL));
		while (fragA.getHitPoints() > 0 && fragB.getHitPoints() > 0
			&& fragA.getEnergyPoints() > 0 && fragB.getEnergyPoints() > 0
		) {
			switch (rand() % 2) {
				case 0:
					round(fragA, fragB);
					break;
				case 1:
					round(fragB, fragA);
			}
		}
	}
}

int main(void) {
	FragTrap frag_trap("Athena");
	FragTrap fr4g_7r4p;
	FragTrap fr4g_7r4p2(frag_trap);

	fr4g_7r4p.setName("Nisha");
	fr4g_7r4p2.setName("Aurelia");
	tests::fight(frag_trap, fr4g_7r4p);
	frag_trap.setHitPoints(100);
	frag_trap.setEnergyPoints(100);
	std::cout << std::endl;
	tests::fight(frag_trap, fr4g_7r4p2);
	fr4g_7r4p.setHitPoints(100);
	fr4g_7r4p2.setHitPoints(100);
	fr4g_7r4p.setEnergyPoints(100);
	fr4g_7r4p2.setEnergyPoints(100);
	std::cout << std::endl;
	tests::fight(fr4g_7r4p, fr4g_7r4p2);
}
