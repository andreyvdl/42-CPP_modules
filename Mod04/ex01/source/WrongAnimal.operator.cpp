/**
 * @file WrongAnimal.operator.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Operator overloads for the WrongAnimal class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "WrongAnimal.class.hpp"

WrongAnimal& WrongAnimal::operator=(WrongAnimal const& that) {
	if (this != &that) {
		_type = that._type;
	}
	return (*this);
}
