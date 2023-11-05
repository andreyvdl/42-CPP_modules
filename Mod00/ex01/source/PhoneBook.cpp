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

namespace utilsPhoneBook {
	void clearWCin(void) {
		std::wcin.eof();
		fflush(stdin);
		std::wcin.clear();
	}

	void clearCin(void) {
		std::cin.eof();
		fflush(stdin);
		std::cin.clear();
	}

	bool validPhoneNbr(std::string phone) {
		if (phone.size() > 9 || phone.size() < 7)
			return (false);
		for (size_t i = 0; i < phone.size(); ++i) {
			if (i < 4 && !std::isdigit(phone[i]))
				return (false);
			else if (i > 3 && i < 6 && phone[i] != '-'
			&& !std::isdigit(phone[i]))
				return (false);
			else if (i > 6 && !std::isdigit(phone[i]))
				return (false);
		}
		return (true);
	}

	bool parseName(std::wstring name) {
		if (name.empty())
			return (false);
		for (std::wstring::iterator it = name.begin(); it != name.end(); ++it) {
			if (!iswalpha(*it))
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

	void printStartOrEndOfTable(void) {
		std::cout << FG_CYAN << "+---INDEX--+---FNAME--+--LNAME---+-NICKNAME-+"
		<< RESET << std::endl;
	}

	void printIndex(int idx) {
		std::cout << FG_CYAN << "|" << RESET;
		std::cout << std::setw(9) << idx << FG_CYAN << "|" << RESET;
	}

	void printContactField(std::wstring field, int len) {
		std::wstring wStrCopy;

		if (len < 0) {
			wStrCopy = field.substr(0, 9);
			std::wcout << wStrCopy << "." << FG_CYAN << "|" << RESET;
		}
		else
			std::wcout << std::setw(len) << field << FG_CYAN << "|" << RESET;
	}

	void printThisContact(Contact contact) {
		std::wcout << "First name: " << contact.getFirstName() << std::endl;
		std::wcout << "Last name: " << contact.getLastName() << std::endl;
		std::wcout << "Nickname: " << contact.getNickname() << std::endl;
		std::cout << "Phone number: " << contact.getPhoneNumber() << std::endl;
		std::wcout << "Darkest secret: " << contact.getDarkSecret() << std::endl;
	}
}

/* Class methods =========================================================== */

PhoneBook::PhoneBook(void) {
	std::cout << FG_GREEN << "PhoneBook created." << RESET << std::endl;
}

PhoneBook::~PhoneBook(void) {
	std::cout << FG_RED << "PhoneBook destroyed." << RESET << std::endl;
}

Contact* PhoneBook::getContact(unsigned short int idx) const {
	return (const_cast<Contact*>(&this->_contacts[idx]));
}

void PhoneBook::addContact(void) {
	std::wstring fName;
	std::wstring lName;
	std::wstring nName;
	std::string phoneNbr;
	std::wstring dSecret;

	while (true) {
		if (std::wcin.eof())
			utilsPhoneBook::clearWCin();
		std::cout << "First name: ";
		std::wcin >> fName;
		if (utilsPhoneBook::parseName(fName))
			break;
		std::cout << FG_BD_RED << "Invalid name." << RESET << std::endl;
		fName.clear();
	}
	while (true) {
		if (std::wcin.eof())
			utilsPhoneBook::clearWCin();
		std::cout << "Last name: ";
		std::wcin >> lName;
		if (utilsPhoneBook::parseName(lName))
			break;
		std::cout << FG_BD_RED << "Invalid name." << RESET << std::endl;
		lName.clear();
	}
	while (true) {
		if (std::wcin.eof())
			utilsPhoneBook::clearWCin();
		std::cout << "Nickname: ";
		std::wcin >> nName;
		if (!nName.empty())
			break;
		std::cout << FG_BD_RED << "Invalid nickname." << RESET << std::endl;
	}
	while (true) {
		if (std::cin.eof())
			utilsPhoneBook::clearCin();
		std::cout << "Phone number: ";
		std::cin >> phoneNbr;
		if (utilsPhoneBook::parsePhone(phoneNbr))
			break;
		std::cout << FG_BD_RED << "Invalid phone number." << RESET << std::endl;
		phoneNbr.clear();
	}
	while (true) {
		if (std::wcin.eof())
			utilsPhoneBook::clearWCin();
		std::cout << "Your darkest secret: ";
		getline(std::wcin, dSecret);
		if (!dSecret.empty())
			break;
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

	utilsPhoneBook::printStartOrEndOfTable();
	if (this->_nbrOfContactsAdded < 8) {
		for (size_t i = 0; i < this->_nbrOfContactsAdded; ++i) {
			utilsPhoneBook::printIndex(i);
			utilsPhoneBook::printContactField(this->_contacts[i].getFirstName(),
				10 - this->_contacts[i].getFirstName().length());
			utilsPhoneBook::printContactField(this->_contacts[i].getLastName(),
				10 - this->_contacts[i].getLastName().length());
			utilsPhoneBook::printContactField(this->_contacts[i].getNickname(),
				10 - this->_contacts[i].getNickname().length());
		}
	}
	else {
		for (size_t i = 0; i < 8; ++i) {
			utilsPhoneBook::printIndex(i);
			utilsPhoneBook::printContactField(this->_contacts[i].getFirstName(),
				10 - this->_contacts[i].getFirstName().length());
			utilsPhoneBook::printContactField(this->_contacts[i].getLastName(),
				10 - this->_contacts[i].getLastName().length());
			utilsPhoneBook::printContactField(this->_contacts[i].getNickname(),
				10 - this->_contacts[i].getNickname().length());	
		}
	}
	utilsPhoneBook::printStartOrEndOfTable();

	std::string idx;

	while (true) {
		if (std::cin.eof())
			utilsPhoneBook::clearCin();
		std::cout << "Select an index: ";
		std::cin >> idx;
		if (utilsPhoneBook::parseIndex(idx, this->_nbrOfContactsAdded))
			break;
		std::cout << FG_BD_RED << "Invalid index." << RESET << std::endl;
	}
	utilsPhoneBook::clearCin();
	utilsPhoneBook::printThisContact(this->_contacts[std::atoi(idx.c_str())]);
}

size_t PhoneBook::_nbrOfContactsAdded = 0;
