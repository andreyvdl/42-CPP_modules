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
#include "ScavTrap.class.hpp"

namespace tests {
	void round(ScavTrap& attacker, ScavTrap& adversary) {
		switch (rand() % 3) {
			case 0:
				attacker.attack(adversary.getName());
				adversary.takeDamage(attacker.getDamage());
				break;
			case 1:
				attacker.beRepaired(rand() % 10 + 1);
				break;
			case 2:
				attacker.guardGate();
		}
	}

	void fight(ScavTrap& scavA, ScavTrap& scavB) {
		std::srand(std::time(NULL));
		while (scavA.getHitPoints() > 0 && scavB.getHitPoints() > 0
			&& scavA.getEnergyPoints() > 0 && scavB.getEnergyPoints() > 0
		) {
			switch (rand() % 2) {
				case 0:
					round(scavA, scavB);
					break;
				case 1:
					round(scavB, scavA);
			}
		}
	}
}

int main(void) {
	ScavTrap scav_trap("Maya");
	ScavTrap sc4v_7r4p;
	ScavTrap sc4v_7r4p2(scav_trap);

	sc4v_7r4p.setName("Zer0");
	sc4v_7r4p2.setName("Handsome Jack");
	tests::fight(scav_trap, sc4v_7r4p);
	scav_trap.setHitPoints(100);
	scav_trap.setEnergyPoints(50);
	std::cout << std::endl;
	tests::fight(scav_trap, sc4v_7r4p2);
	sc4v_7r4p.setHitPoints(100);
	sc4v_7r4p2.setHitPoints(100);
	sc4v_7r4p.setEnergyPoints(50);
	sc4v_7r4p2.setEnergyPoints(50);
	std::cout << std::endl;
	tests::fight(sc4v_7r4p, sc4v_7r4p2);
}
