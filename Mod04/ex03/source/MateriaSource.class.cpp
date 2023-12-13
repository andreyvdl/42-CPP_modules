/**
 * @file MateriaSource.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Methods for the Materiasource class.
 * @version 1
 * @date 2023-12-13
 * 
 * @copyright Copyright (c) 2023
 */

#include "MateriaSource.class.hpp"
#include "AMateria.abstract.hpp"

void deleteMaterias(AMateria** materias);
void initMaterias(AMateria** materias);

/* TRUCTORS ================================================================= */

MateriaSource::MateriaSource(void)
{
	initMaterias(_materias);
}

MateriaSource::MateriaSource(MateriaSource const& that)
{
	initMaterias(_materias);
	*this = that;
}

MateriaSource::~MateriaSource(void)
{
	deleteMaterias(_materias);
}

/* OPERATORS ================================================================ */

MateriaSource& MateriaSource::operator=(MateriaSource const& that)
{
	if (this != &that)
	{
		deleteMaterias(_materias);
		for (int i = 0; i < 4; i++)
		{
			if (that._materias[i] != NULL)
				_materias[i] = that._materias[i]->clone();
		}
	}
	return (*this);
}

/* METHODS ================================================================== */

void MateriaSource::learnMateria(AMateria* materia)
{
	for (int i = 0; i < 4; i++) {
		if (_materias[i] == NULL) {
			_materias[i] = materia;
			return;
		}
	}
	std::cout << "MateriaSource if full of blueprints." << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < 4; i++) {
		if (_materias[i] != NULL && _materias[i]->getType() == type) {
			return (_materias[i]->clone());
		}
	}
	return (0); // PDF mandou retornar 0.
}

void initMaterias(AMateria** materias)
{
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
}

void deleteMaterias(AMateria** materias)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] != NULL)
			delete materias[i];
	}
}
