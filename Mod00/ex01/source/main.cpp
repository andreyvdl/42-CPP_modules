/**
 * @file main.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Main file for the phonebook program.
 * @version 1
 * @date 2023-10-31
 * 
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include <string>
#include <cstdio> // for fflush
#include "PhoneBook.hpp"
#include "Defines.hpp"

namespace utils {
	void clearCin(void) {
		fflush(NULL);
		std::clearerr(stdin);
		std::cin.clear();
	}
}

int main(void) {
	PhoneBook book;
	std::string cmd;

	std::cout << FG_BD_CYAN << "Welcome to the phonebook!" << RESET <<
		std::endl;
	while (cmd != "EXIT") {
		if (std::cin.eof() || std::cin.fail())
			utils::clearCin();
		std::cout << "PhoneBook> " << std::flush;
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			book.addContact();
		else if (cmd == "SEARCH")
			book.searchContact();
		else if (cmd == "HELP")
			std::cout << "The commands are HELP, ADD, SEARCH and EXIT." <<
			std::endl;
		else if (cmd != "EXIT")
			std::cout << FG_BD_RED << "Invalid command." << RESET << std::endl;
	}
	utils::clearCin();
	std::cout << "Bye!" << std::endl;
	return (0);
}
