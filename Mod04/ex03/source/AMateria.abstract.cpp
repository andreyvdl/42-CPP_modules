/**
 * @file AMateria.abstract.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Methods for the AMateria class.
 * @version 1
 * @date 2023-12-12
 * 
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include "AMateria.abstract.hpp"
#include "ICharacter.interface.hpp"

/* TRUCTORS ================================================================= */

AMateria::AMateria(void): _type("none") {}

AMateria::AMateria(std::string const& type): _type(type) {}

AMateria::AMateria(AMateria const& that)
{
	*this = that;
}

AMateria::~AMateria(void) {}

/* OPERATORS ================================================================ */

AMateria& AMateria::operator=(AMateria const& that)
{
	if (this != &that) {
		this->_type = that._type;
	}
	return (*this);
}

/* METHODS ================================================================== */

std::string const& AMateria::getType(void) const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* uses materia on " << target.getName() << " *" << std::endl;
}
