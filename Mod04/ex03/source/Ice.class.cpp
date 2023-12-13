/**
 * @file Ice.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Methods for the Ice class.
 * @version 1
 * @date 2023-12-12
 * 
 * @copyright Copyright (c) 2023
 */

#include <iostream>
#include "Ice.class.hpp"
#include "ICharacter.interface.hpp"

/* TRUCTORS ================================================================= */

Ice::Ice(void): AMateria("ice") {}

Ice::Ice(Ice const& that): AMateria("ice")
{
	(void)that;
}

Ice::~Ice(void) {}

/* OPERATORS ================================================================ */

Ice& Ice::operator=(Ice const& that)
{
	(void)that;
	_type = "ice";
	return (*this);
}

/* METHODS ================================================================== */

AMateria* Ice::clone(void) const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *"
		<< std::endl;
}
