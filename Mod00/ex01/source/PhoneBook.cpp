/**
 * @file PhoneBook.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File with implementation of the PhoneBook class.
 * @version 1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 */

#include "Defines.hpp"
#include "PhoneBook.hpp"
#include <string>
#include <iomanip>
#include <cstdio> // for fflush
#include <cstdlib> // for std::atoi
#include <limits> // for std::numeric_limits

namespace utilsPhoneBook {
	void clearCin(void) {
		std::cin.eof();
		fflush(stdin);
		std::clearerr(stdin);
		std::cin.clear();
	}

	bool validPhoneNbr(std::string phone) {
		if (phone.size() > 10 || phone.size() < 7)
			return (true);
		for (size_t i = 0; i < phone.size(); ++i) {
			if (i < 4 && !std::isdigit(phone[i]))
				return (true);
			else if (i > 3 && i < 6 && phone[i] != '-'
			&& !std::isdigit(phone[i]))
				return (true);
			else if (i > 6 && !std::isdigit(phone[i]))
				return (true);
		}
		return (false);
	}

	bool parseName(std::string name) {
		if (name.empty())
			return (false);
		for (std::string::iterator it = name.begin(); it != name.end(); ++it) {
			if (!isalpha(*it))
				return (false);
		}
		return (true);
	}

	bool parsePhone(std::string phone) {

		if (phone.empty() || validPhoneNbr(phone))
			return (false);
		return (true);
	}

	bool parseIndex(std::string index, size_t limit) {
		if (index.size() > 1 || index.empty()
		|| !std::isdigit(index[0]))
			return (false);
		if (limit < 8) {
			if (static_cast<size_t>(std::atol(index.c_str())) >= limit)
				return (false);
		}
		else
			if (std::atoi(index.c_str()) >= 8)
				return (false);
		return (true);
	}

	void printStartOfTable(void) {
		std::cout << FG_CYAN << "|---INDEX--|---FNAME--|--LNAME---|-NICKNAME-|"
			<< RESET << std::endl;
	}

	void printEndOfTable(void) {
		std::cout << FG_CYAN << "|----------|----------|----------|----------|"
			<< RESET << std::endl;
	}

	void printIndex(int idx) {
		std::cout << FG_CYAN << "|" << RESET;
		std::cout << std::setw(10) << idx << FG_CYAN << "|" << RESET
			<< std::flush;
	}

	void printContactField(std::string field) {
		std::string strCopy;
		int len = 10 - static_cast<int>(field.size());

		if (len < 0) {
			strCopy = field.substr(0, 9);
			std::cout << strCopy << "." << FG_CYAN << "|" << RESET << std::flush;
		}
		else {
			std::cout << std::setw(10) << field << FG_CYAN << "|" << RESET
				<< std::flush;
		}
	}

	void printThisContact(Contact* contact) {
		std::cout << "First name: " << contact->getFirstName() << std::endl;
		std::cout << "Last name: " << contact->getLastName() << std::endl;
		std::cout << "Nickname: " << contact->getNickname() << std::endl;
		std::cout << "Phone number: " << contact->getPhoneNumber() << std::endl;
		std::cout << "Darkest secret: " << contact->getDarkSecret() << std::endl;
	}
}

/* Class methods =========================================================== */

PhoneBook::PhoneBook(void) {}

PhoneBook::~PhoneBook(void) {}

Contact* PhoneBook::getContact(unsigned short int idx) const {
	return (const_cast<Contact*>(&this->_contacts[idx]));
}

void PhoneBook::addContact(void) {
	std::string fName;
	std::string lName;
	std::string nName;
	std::string phoneNbr;
	std::string dSecret;

	while (true) {
		if (std::cin.eof() || std::cin.fail())
			utilsPhoneBook::clearCin();
		std::cout << "First name: " << std::flush;
		std::getline(std::cin, fName);
		if (utilsPhoneBook::parseName(fName)) {
			utilsPhoneBook::clearCin();
			break;
		}
		std::cout << FG_BD_RED << "Invalid name." << RESET << std::endl;
		fName.clear();
	}
	utilsPhoneBook::clearCin();
	while (true) {
		if (std::cin.eof() || std::cin.fail())
			utilsPhoneBook::clearCin();
		std::cout << "Last name: " << std::flush;
		std::getline(std::cin, lName);
		if (utilsPhoneBook::parseName(lName)) {
			utilsPhoneBook::clearCin();
			break;
		}
		std::cout << FG_BD_RED << "Invalid name." << RESET << std::endl;
		lName.clear();
	}
	utilsPhoneBook::clearCin();
	while (true) {
		if (std::cin.eof() || std::cin.fail())
			utilsPhoneBook::clearCin();
		std::cout << "Nickname: " << std::flush;
		std::getline(std::cin, nName);
		if (!nName.empty()) {
			utilsPhoneBook::clearCin();
			break;
		}
		std::cout << FG_BD_RED << "Invalid nickname." << RESET << std::endl;
	}
	utilsPhoneBook::clearCin();
	while (true) {
		if (std::cin.eof() || std::cin.fail())
			utilsPhoneBook::clearCin();
		std::cout << "Phone number: " << std::flush;
		std::getline(std::cin, phoneNbr);
		if (utilsPhoneBook::parsePhone(phoneNbr)) {
			utilsPhoneBook::clearCin();
			break;
		}
		std::cout << FG_BD_RED << "Invalid phone number." << RESET << std::endl;
		phoneNbr.clear();
	}
	utilsPhoneBook::clearCin();
	while (true) {
		if (std::cin.eof() || std::cin.fail())
			utilsPhoneBook::clearCin();
		std::cout << "Your darkest secret: " << std::flush;
		std::getline(std::cin, dSecret);
		if (!dSecret.empty()) {
			utilsPhoneBook::clearCin();
			break;
		}
		std::cout << FG_BD_RED << "Invalid secret." << RESET << std::endl;
	}
	this->_contacts[this->_nbrOfContactsAdded % 8].setFirstName(fName);
	this->_contacts[this->_nbrOfContactsAdded % 8].setLastName(lName);
	this->_contacts[this->_nbrOfContactsAdded % 8].setNickname(nName);
	this->_contacts[this->_nbrOfContactsAdded % 8].setPhoneNumber(phoneNbr);
	this->_contacts[this->_nbrOfContactsAdded % 8].setDarkSecret(dSecret);
	this->_nbrOfContactsAdded++;
}

void PhoneBook::searchContact(void) {
	if (this->_nbrOfContactsAdded == 0) {
		std::cout << FG_BD_YELLOW << "Your contact list is empty." << RESET <<
			std::endl;
		return;
	}

	utilsPhoneBook::printStartOfTable();
	if (this->_nbrOfContactsAdded < 8) {
		for (size_t i = 0; i < this->_nbrOfContactsAdded; ++i) {
			utilsPhoneBook::printIndex(i);
			utilsPhoneBook::printContactField(this->_contacts[i].getFirstName());
			utilsPhoneBook::printContactField(this->_contacts[i].getLastName());
			utilsPhoneBook::printContactField(this->_contacts[i].getNickname());
			std::cout << std::endl;
		}
	}
	else {
		for (size_t i = 0; i < 8; ++i) {
			utilsPhoneBook::printIndex(i);
			utilsPhoneBook::printContactField(this->_contacts[i].getFirstName());
			utilsPhoneBook::printContactField(this->_contacts[i].getLastName());
			utilsPhoneBook::printContactField(this->_contacts[i].getNickname());
			std::cout << std::endl;
		}
	}
	utilsPhoneBook::printEndOfTable();

	std::string idx;

	while (true) {
		if (std::cin.eof() || std::cin.fail())
			utilsPhoneBook::clearCin();
		std::cout << "Select an index: " << std::flush;
		std::getline(std::cin, idx);
		if (utilsPhoneBook::parseIndex(idx, this->_nbrOfContactsAdded))
			break;
		std::cout << FG_BD_RED << "Invalid index." << RESET << std::endl;
	}
	utilsPhoneBook::clearCin();
	utilsPhoneBook::printThisContact(&this->_contacts[std::atoi(idx.c_str())]);
}

size_t PhoneBook::_nbrOfContactsAdded = 0;
