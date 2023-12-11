/**
 * @file IMateriaSource.interface.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Definition of the IMateriaSource class.
 * @version 1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef IMATERIASOURCE_INTERFACE_HPP
# define IMATERIASOURCE_INTERFACE_HPP
# include <iostream>
# include "AMateria.abstract.hpp"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
