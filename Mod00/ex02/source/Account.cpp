// ************************************************************************** //
//                                                                            //
//                Account.cpp for GlobalBanksters United                      //
//                Created on  : Tue Nov 07 15:18:12 2023                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//         Made by : Andrey "QA" Leal <adantas-@student.42sp.org.br>          //
//                                                                            //
// ************************************************************************** //

#include "Account.hpp"
#include <iostream>
#include <ctime>
#define TIMESTAMP_SIZE 17 // [+year+month+day+_+hour+minute+second+]

Account::Account(int initial_deposit) : _amount(initial_deposit) {
	this->_displayTimestamp();

	this->_nbAccounts++;
}

Account::~Account(void) {
	this->_displayTimestamp();

	this->_nbAccounts--;
}


void Account::_displayTimestamp(void) {
	time_t rawtime;
	struct tm* timeinfo;
	char buffer[TIMESTAMP_SIZE];

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, TIMESTAMP_SIZE, "[%Y%m%d_%H%M%S]", timeinfo);
	std::cout << buffer << " ";
}

int Account::_nbAccounts = 0;
