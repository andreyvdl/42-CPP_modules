/**
 * @file Dog.tructor.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Constutors and destructors for the Dog class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "Dog.class.hpp"

Dog::Dog(void): Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
}

Dog::Dog(Dog const& that): Animal(that) {
	std::cout << "Dog copy constructor called" << std::endl;
	*this = that;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
}
