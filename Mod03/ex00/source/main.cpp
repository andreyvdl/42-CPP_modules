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
#include "ClapTrap.class.hpp"

namespace tests {
	void turnAction(ClapTrap& attacker, ClapTrap& adversary) {
		switch (rand() % 2) {
			case 0:
				attacker.attack(adversary.getName());
				adversary.takeDamage(attacker.getDamage());
				break;
			case 1:
				attacker.beRepaired(rand() % 10);
		}
	}

	void fight(ClapTrap& claptrapA, ClapTrap& claptrapB) {
		srand(time(NULL));
		while ((claptrapA.getHitPoints() > 0 && claptrapB.getHitPoints() > 0)
			|| (claptrapA.getEnergyPoints() > 0
				&& claptrapB.getEnergyPoints() > 0)
		)
			switch (rand() % 2) {
				case 0:
					turnAction(claptrapA, claptrapB);
					break;
				case 1:
					turnAction(claptrapB, claptrapA);
			}
	}
}

int main(void) {
	ClapTrap claptrap("Roland");
	ClapTrap cl4p_tp;
	ClapTrap cl4p_tp2(claptrap);

	claptrap.setDamage(2);
	cl4p_tp.setDamage(3);
	cl4p_tp2.setDamage(1);
	cl4p_tp2.setName("Lilith");
	tests::fight(cl4p_tp, cl4p_tp2);
	claptrap.setHitPoints(10);
	cl4p_tp2.setHitPoints(10);
	std::cout << std::endl;
	tests::fight(claptrap, cl4p_tp2);
	claptrap.setHitPoints(10);
	cl4p_tp.setHitPoints(10);
	std::cout << std::endl;
	tests::fight(claptrap, cl4p_tp);
}
