/**
 * @file Animal.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Methods for the Animal class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "Animal.class.hpp"

/* TRUCTORS ================================================================= */

Animal::Animal(void): _type("Unknown") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const& that) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = that;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
}

/* OPERATORS ================================================================ */

Animal& Animal::operator=(Animal const& that) {
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &that) {
		_type = that._type;
	}
	return (*this);
}

/* METHODS ================================================================== */

void Animal::makeSound(void) const {
	std::cout << "* " << _type << " makes an animal sound *" << std::endl;
}

std::string Animal::getType(void) const {
	return (_type);
}
