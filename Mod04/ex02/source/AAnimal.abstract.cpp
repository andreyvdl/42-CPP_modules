/**
 * @file Animal.abstract.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Methods for the AAnimal class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "AAnimal.abstract.hpp"

/* TRUCTORS ================================================================= */

AAnimal::AAnimal(void): _type("Unknown") {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const& that) {
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = that;
}

AAnimal::~AAnimal(void) {
	std::cout << "AAnimal destructor called" << std::endl;
}

/* OPERATORS ================================================================ */

AAnimal& AAnimal::operator=(AAnimal const& that) {
	std::cout << "AAnimal assignation operator called" << std::endl;
	if (this != &that) {
		_type = that._type;
	}
	return (*this);
}

/* METHODS ================================================================== */

std::string AAnimal::getType(void) const {
	return (_type);
}
