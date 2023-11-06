/**
 * @file Contact.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Implementation of the Contact class.
 * @version 1
 * @date 2023-11-02
 *
 * @copyright Copyright (c) 2023
 */

#include "../include/Contact.hpp"
#include "../include/Defines.hpp"

Contact::Contact(void) {
	Contact::_constructorCalls++;
	std::cout << FG_GREEN << "Contact " << Contact::_constructorCalls <<
		" created" << RESET << std::endl;
}
Contact::~Contact(void) {
	std::cout << FG_RED << "Contact " << Contact::_constructorCalls <<
		" destroyed" << RESET << std::endl;
	Contact::_constructorCalls--;
}

void Contact::setFirstName(std::string firstName) {
	this->_firstName = firstName;
}

std::string Contact::getFirstName(void) const {
	return (this->_firstName);
}

void Contact::setLastName(std::string lastName) {
	this->_lastName = lastName;
}

std::string Contact::getLastName(void) const {
	return (this->_lastName);
}

void Contact::setNickname(std::string nickname) {
	this->_nickname = nickname;
}

std::string Contact::getNickname(void) const {
	return (this->_nickname);
}

void Contact::setPhoneNumber(std::string phoneNumber) {
	this->_phoneNumber = phoneNumber;
}

std::string Contact::getPhoneNumber(void) const {
	return (this->_phoneNumber);
}

void Contact::setDarkSecret(std::string darkestSecret) {
	this->_darkestSecret = darkestSecret;
}

std::string Contact::getDarkSecret(void) const {
	return (this->_darkestSecret);
}

int	Contact::_constructorCalls = 0;
