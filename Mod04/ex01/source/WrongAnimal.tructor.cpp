/**
 * @file WrongAnimal.tructor.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Contructor and destructor for the WrongAnimal class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "WrongAnimal.class.hpp"

WrongAnimal::WrongAnimal(void): _type("Unknown") {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& that) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
	*this = that;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}
