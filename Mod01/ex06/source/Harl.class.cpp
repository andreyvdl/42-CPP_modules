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
			this->debug();
		case 1:
			this->info();
		case 2:
			this->warning();
		case 3:
			this->error();
			break;
		default:
			std::cout
				<< "[ Probably complaining about insignificant problems ]"
				<< std::endl;
	}
}

#define CRLF "\r\n"
void Harl::debug(void) {
	std::cout << "[ DEBUG ]"CRLF << "I thought I fixed that." << std::endl;
}

void Harl::info(void) {
	std::cout << "[ INFO ]"CRLF
		<< "No one told me so I was forced to assume which way to do that."
		<< std::endl;
}

void Harl::warning(void) {
	std::cout << "[ WARNING ]"CRLF
		<< "You must have the wrong version." << std::endl;
}

void Harl::error(void) {
	std::cout << "[ ERROR ]"CRLF
		<< "I can't make that a priority right now." << std::endl;
}
