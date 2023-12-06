/**
 * @file WrongAnimal.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Methods for the WrongAnimal class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "WrongAnimal.class.hpp"

void WrongAnimal::makeSound(void) const {
	std::cout << "* " << _type << " makes a non animal sound *" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return (_type);
}
