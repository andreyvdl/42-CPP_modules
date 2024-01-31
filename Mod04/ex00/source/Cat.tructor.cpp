/**
 * @file Cat.tructor.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Contructors and destructors for the Cat class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "Cat.class.hpp"

Cat::Cat(void): Animal() {
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
}

Cat::Cat(Cat const& that): Animal(that) {
	std::cout << "Cat copy constructor called" << std::endl;
	*this = that;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
}
