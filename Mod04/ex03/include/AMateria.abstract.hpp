/**
 * @file AMateria.abstract.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Definition of the AMateria class.
 * @version 1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef AMATERIA_ABSTRACT_HPP
# define AMATERIA_ABSTRACT_HPP
# include <iostream>

class ICharacter; // para evitar dependencia circular

class AMateria
{
	protected:
		std::string _type;

	public:
		AMateria(void);
		AMateria(AMateria const& that);
		virtual ~AMateria(void);
		AMateria& operator=(AMateria const& that);

		AMateria(std::string const& type);

		std::string const& getType(void) const; //Returns the materia type

		virtual AMateria* clone(void) const = 0;
		virtual void use(ICharacter& target);
};

#endif
