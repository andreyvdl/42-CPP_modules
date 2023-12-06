/**
 * @file Cat.operator.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Operator overloads for the Cat class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "Cat.class.hpp"

Cat& Cat::operator=(Cat const& that) {
	std::cout << "Cat assignation operator called" << std::endl;
	if (this != &that) {
		_type = that._type;
	}
	return (*this);
}
