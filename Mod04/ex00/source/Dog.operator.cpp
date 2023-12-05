/**
 * @file Dog.operator.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Operator overloads for the Dog class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "Dog.class.hpp"

Dog& Dog::operator=(Dog const& that) {
	std::cout << "Dog assignation operator called" << std::endl;
	if (this != &that) {
		_type = that._type;
	}
	return (*this);
}
