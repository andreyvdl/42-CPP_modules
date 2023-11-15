/**
 * @file Harl.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File that contains the Harl class methods.
 * @version 1
 * @date 2023-11-15
 * 
 * @copyright Copyright (c) 2023
 */

#include "Harl.class.hpp"

Harl::Harl(void) {};

Harl::~Harl(void) {};

void Harl::complain(std::string level) {
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int i;

	for (i = 0; i < 4; ++i)
		if (levels[i] == level) break;
	switch (i) {
		case 0:
			std::cout << "[ DEBUG ]" << std::endl;
			this->debug();
		case 1:
			std::cout << "[ INFO ]" << std::endl;
			this->info();
		case 2:
			std::cout << "[ WARNING ]" << std::endl;
			this->warning();
		case 3:
			std::cout << "[ ERROR ]" << std::endl;
			this->error();
			break;
		default:
			std::cout
				<< "[ Probably complaining about insignificant problems ]"
				<< std::endl;
	}
}

void Harl::debug(void) {
	std::cout << "I thought I fixed that." << std::endl;
}

void Harl::info(void) {
	std::cout
		<< "No one told me so I was forced to assume which way to do that."
		<< std::endl;
}

void Harl::warning(void) {
	std::cout << "You must have the wrong version." << std::endl;
}

void Harl::error(void) {
	std::cout << "I can't make that a priority right now." << std::endl;
}
