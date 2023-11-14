/**
 * @file main.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Main file for tests.
 * @version 1
 * @date 2023-11-09
 * 
 * @copyright Copyright (c) 2023
 */

#include "Weapon.class.hpp"
#include "HumanA.class.hpp"
#include "HumanB.class.hpp"
#include "Defines.hpp"
#include <iomanip>

namespace tests {
	void metalSlug(void) {
		Weapon rocket("Rocket Launcher");
		Weapon heavy("Heavy Machine Gun");
		Weapon chaser("Enemy Chaser");
		Weapon laser("Laser Gun");
		HumanA marco("Marco", rocket);
		HumanB tarma("Tarma");
		HumanA eri("Eri", heavy);
		HumanB fio("Fio");

		std::cout << std::endl << BG_YELLOW << std::setw(21) << RESET
			<< FG_BD_YELLOW << " METAL SLUG 42 " << RESET << BG_YELLOW
			<< std::setw(21) << RESET << std::endl;

		tarma.setWeapon(laser);
		fio.setWeapon(chaser);
		marco.attack();
		tarma.attack();
		eri.attack();
		fio.attack();
		std::cout << std::endl;
		fio.setWeapon(rocket);
		eri.setWeapon(laser);
		tarma.setWeapon(heavy);
		marco.setWeapon(chaser);
		marco.attack();
		tarma.attack();
		eri.attack();
		fio.attack();
	}
}

int main(void)
{
	// aparentemente isso cria um fake scope e os objs sao destuidos.
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	tests::metalSlug();
	return (0);
}
