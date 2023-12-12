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

Cure::Cure(void): AMateria("cure") {}

Cure::Cure(Cure const& that)
{
	*this = that;
}

Cure::~Cure(void) {}

/* OPERATORS ================================================================ */

Cure& Cure::operator=(Cure const& that)
{
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
