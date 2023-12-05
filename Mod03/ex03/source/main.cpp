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
#include "DiamondTrap.class.hpp"
#define SUFFIX_NAME "_clap_name"

namespace tests {
	void round(DiamondTrap& attacker, DiamondTrap& defender) {
		switch (rand() % 5) {
			case 0:
				attacker.attack(defender.getDiamondName());
				defender.takeDamage(attacker.getDamage());
				break;
			case 1:
				attacker.beRepaired(rand() % 10 + 1);
				break;
			case 2:
				attacker.guardGate();
				break;
			case 3:
				attacker.highFivesGuys();
				break;
			case 4:
				attacker.whoAmI();
		}
	}

	void fight(DiamondTrap& diamondA, DiamondTrap& diamondB) {
		srand(time(NULL));
		while (diamondA.getHitPoints() > 0 && diamondB.getHitPoints() > 0
			&& diamondB.getEnergyPoints() > 0 && diamondB.getEnergyPoints() > 0
		) {
			switch (rand() % 2) {
				case 0:
					round(diamondA, diamondB);
					break;
				case 1:
					round(diamondB, diamondA);
			}
		}
	}
}

int main(void) {
	DiamondTrap diamondTrap("Moze");
	DiamondTrap d14m0nd_7r4p;
	DiamondTrap d14m0nd_7r4p2(diamondTrap);

	d14m0nd_7r4p.ClapTrap::setName(std::string("Maya") + SUFFIX_NAME);
	d14m0nd_7r4p.setDiamondName("Amara");
	d14m0nd_7r4p2.ClapTrap::setName(std::string("Angel") + SUFFIX_NAME);
	d14m0nd_7r4p2.setDiamondName("Tyreen");

	tests::fight(diamondTrap, d14m0nd_7r4p);
	std::cout << std::endl;
	diamondTrap.setEnergyPoints(50);
	diamondTrap.setHitPoints(100);
	d14m0nd_7r4p.setEnergyPoints(50);
	d14m0nd_7r4p.setHitPoints(100);
	tests::fight(diamondTrap, d14m0nd_7r4p2);
	std::cout << std::endl;
	d14m0nd_7r4p2.setHitPoints(100);
	d14m0nd_7r4p2.setEnergyPoints(50);
	tests::fight(d14m0nd_7r4p, d14m0nd_7r4p2);

}
