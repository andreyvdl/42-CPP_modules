/**
 * @file main.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Main file.
 * @version 1
 * @date 2023-11-15
 * 
 * @copyright Copyright (c) 2023
 */

#include "Harl.class.hpp"
#include <iostream>

int main(void) {
	Harl harl;

	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");

	std::string levels[4] = {"ERROR", "WARNING", "INFO", "DEBUG"};

	for (int i = 0; i < 4; i++)
		harl.complain(levels[i]);
	return (0);
}
