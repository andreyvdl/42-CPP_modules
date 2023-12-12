/**
 * @file Cure.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Methods for the Cure class.
 * @version 1
 * @date 2023-12-12
 * 
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include "Cure.class.hpp"

/* TRUCTORS ================================================================= */

Cure::Cure(void): AMateria()
{
	std::cout << "Cure default constructor called!" << std::endl;
	this->_type = "cure";
}

Cure::Cure(Cure const& that)
{
	std::cout << "Cure copy constructor called!" << std::endl;
	*this = that;
}

Cure::~Cure(void)
{
	std::cout << "Cure destructor called!" << std::endl;
}

/* OPERATORS ================================================================ */

Cure& Cure::operator=(Cure const& that)
{
	std::cout << "Cure assignation operator called!" << std::endl;
	if (this != &that) {
		this->_type = that._type;
	}
	return (*this);
}

/* METHODS ================================================================== */

AMateria* Cure::clone(void) const
{
	return (new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
