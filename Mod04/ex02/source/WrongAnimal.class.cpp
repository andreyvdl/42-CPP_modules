/**
 * @file WrongAnimal.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Methods for the WrongAnimal class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "WrongAnimal.class.hpp"

/* TRUCTORS ================================================================= */

WrongAnimal::WrongAnimal(void): _type("Unknown") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& that) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = that;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

/* OPERATORS ================================================================ */

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& that) {
	if (this != &that) {
		_type = that._type;
	}
	return (*this);
}

/* METHODS ================================================================== */

void WrongAnimal::makeSound(void) const {
	std::cout << "* " << _type << " makes a non animal sound *" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return (_type);
}
