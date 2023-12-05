/**
 * @file Animal.class.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Methods for the Animal class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "Animal.class.hpp"

void Animal::makeSound(void) const {
	std::cout << "* " << _type << " makes an animal sound *" << std::endl;
}

std::string Animal::getType(void) const {
	return (_type);
}
