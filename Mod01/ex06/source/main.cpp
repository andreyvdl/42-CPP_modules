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
#include "Defines.hpp"
#include <iostream>

namespace utils {
	void printUsage(void) {
		std::cout << "Usage: " << FG_GREEN << "./harl " << FG_UL_RED
			<< "level" << RESET << std::endl;
	}

	void printErr(std::string type) {
		std::cout << FG_RED << "Error: " << type << RESET << std::endl;
	}
}

int main(int argC, char** argV) {
	if (argC != 2) {
		switch (argC) {
			case 1:
				utils::printErr("No arguments provided.");
				utils::printUsage();
				break;
			default:
				utils::printErr("Too many arguments.");
				utils::printUsage();
		}
		return (argC);
	}
	Harl harlV2;

	harlV2.complain(argV[1]);
	return (0);
}
