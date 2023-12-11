/**
 * @file Cat.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Mehtods for the Cat class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "Cat.class.hpp"

/* TRUCTORS ================================================================= */

Cat::Cat(void): AAnimal() {
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain;
}

Cat::Cat(Cat const& that) {
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain;
	*this = that;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

/* OPERATORS ================================================================ */

Cat& Cat::operator=(Cat const& that) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &that) {
		_type = that._type;
		*_brain = *(that._brain);
	}
	return (*this);
}

/* METHODS ================================================================== */

void Cat::makeSound(void) const {
	std::cout << "MIAU!" << std::endl;
}

Brain* Cat::getBrain(void) const {
	return (_brain);
}
