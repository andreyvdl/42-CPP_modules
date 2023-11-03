/**
 * @file PhoneBook.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File with implementation of the PhoneBook class.
 * @version 1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 */

#include "../include/Defines.hpp"
#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	std::cout << FG_GREEN << "PhoneBook created." << RESET << std::endl;
}

PhoneBook::~PhoneBook(void) {
	std::cout << FG_RED << "PhoneBook destroyed." << RESET << std::endl;
}

Contact* PhoneBook::getContact(unsigned short int idx) const {
	if (idx > 7) {
		std::cout << FG_BD_YELLOW << "Invalid index." << RESET << std::endl;
		return (NULL);
	}
	return (const_cast<Contact*>(&this->contacts[idx]));
}

void PhoneBook::addContact(void) {
	std::wstring input;
	this->nbrOfContactsAdded++;
}
