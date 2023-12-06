/**
 * @file Animal.tructor.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Constructors and destructors for the Animal class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "Animal.class.hpp"

Animal::Animal(void): _type("Unknown") {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(Animal const& that) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = that;
}

Animal::~Animal(void) {
	std::cout << "Animal destructor called" << std::endl;
}
