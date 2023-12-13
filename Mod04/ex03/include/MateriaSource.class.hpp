/**
 * @file MateriaSource.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Definition of the MateriaSource class.
 * @version 1
 * @date 2023-12-11
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef MATERIASOURCE_CLASS_HPP
# define MATERIASOURCE_CLASS_HPP
# include "IMateriaSource.interface.hpp"
# include "AMateria.abstract.hpp"

class MateriaSource: public IMateriaSource
{
	private:
		AMateria* _materias[4];

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const& that);
		~MateriaSource(void);
		MateriaSource& operator=(MateriaSource const& that);

		void learnMateria(AMateria* materia);
		AMateria* createMateria(std::string const & type);
};

#endif
