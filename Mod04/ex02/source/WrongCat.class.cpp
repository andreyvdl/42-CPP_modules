/**
 * @file WrongCat.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Methods of the WrongCat class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "WrongCat.class.hpp"

/* TRUCTORS ================================================================= */

WrongCat::WrongCat(void) : WrongAnimal() {
	std::cout << "WrongCat default constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const& that) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = that;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << std::endl;
}

/* OPERATORS ================================================================ */

WrongCat& WrongCat::operator=(WrongCat const& that) {
	if (this != &that) {
		_type = that._type;
	}
	return (*this);
}

/* METHODS ================================================================== */

void WrongCat::makeSound(void) const {
	// https://youtu.be/fhkgNTmrXFY?si=6AokfQR7U6YtvDbX
	std::cout << "OVO!" << std::endl;
}
