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
	void (Harl::*methods[4])(void) = {&Harl::debug, &Harl::info,
		&Harl::warning, &Harl::error
	};
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
		levels[i] == level ? (this->*methods[i])() : void(0);
}

// Quotes from: http://www.developerexcuses.com/

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
