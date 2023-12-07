/**
 * @file Brain.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Methods, tructors and operators for the Brain class.
 * @version 1
 * @date 2023-12-07
 * 
 * @copyright Copyright (c) 2023
 */

#include "Brain.class.hpp"
#include <iostream>

/* TRUCTORS ================================================================= */

Brain::Brain(void) {
	std::cout << "Brain default constructor called" << std::endl;
	for (unsigned int i = 0; i < 100; i++) {
		_ideas[i] = "Empty";
	}
}

Brain::Brain(Brain const& that) {
	std::cout << "Brain copy constructor called" << std::endl;
	*this = that;
}

Brain::~Brain(void) {
	std::cout << "Brain destructor called" << std::endl;
}


/* OPERATORS ================================================================ */

Brain& Brain::operator=(Brain const& that) {
	std::cout << "Brain assignation operator called" << std::endl;
	if (this != &that) {
		std::copy(that._ideas->begin(), that._ideas->end(), _ideas);
	}
	return (*this);
}

/* METHODS ================================================================== */

void Brain::setIdea(std::string idea, unsigned int index) {
	if (index < 100) {
		_ideas[index] = idea;
	}
	else {
		std::cout << "Index out of range" << std::endl;
	}
}

std::string Brain::getIdea(unsigned int index) const {
	if (index < 100) {
		return (_ideas[index]);
	}
	else {
		// https://knowyourmeme.com/memes/insult-me-all-you-wish-my-brain-is-too-smooth
		return ("Smooth brain");
	}
}
