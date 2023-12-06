/**
 * @file Animal.operator.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Operator overloads for the Animal class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "Animal.class.hpp"

Animal& Animal::operator=(Animal const& that) {
	std::cout << "Animal assignation operator called" << std::endl;
	if (this != &that) {
		_type = that._type;
	}
	return (*this);
}
