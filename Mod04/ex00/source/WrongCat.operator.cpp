/**
 * @file WrongCat.operator.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Operator overloads for the WrongCat class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "WrongCat.class.hpp"


WrongCat& WrongCat::operator=(WrongCat const& that) {
	if (this != &that) {
		_type = that._type;
	}
	return (*this);
}
