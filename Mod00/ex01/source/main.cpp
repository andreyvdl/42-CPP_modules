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
#include <iomanip>
#include "../include/PhoneBook.hpp"

namespace utils {
	void youAreGoingToBrazil(void) {
		std::locale::global(std::locale("pt-BR.UTF-8"));
		std::wcout.imbue(std::locale());
	}
}

int main(void) {
	PhoneBook book;

	utils::youAreGoingToBrazil();
	std::wcout << "WELCOME TO BRÁZIL'S PHONEBOOK" << std::endl;
	return (0);
}
