/**
 * @file Dog.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Methods for the Dog class
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "Dog.class.hpp"

/* TRUCTORS ================================================================= */

Dog::Dog(void): Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog(Dog const& that) {
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain();
	*this = that;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

/* OPERATORS ================================================================ */

Dog& Dog::operator=(Dog const& that) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &that) {
		_type = that._type;
		*_brain = *(that._brain);
	}
	return (*this);
}

/* METHODS ================================================================== */

void Dog::makeSound(void) const {
	std::cout << "AU AU!" << std::endl;
}

Brain* Dog::getBrain(void) const {
	return (_brain);
}
