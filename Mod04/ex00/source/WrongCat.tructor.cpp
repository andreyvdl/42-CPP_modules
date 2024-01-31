/**
 * @file WrongCat.tructor.cpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Contructor and destructor for the WrongCat class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#include "WrongCat.class.hpp"

WrongCat::WrongCat(void) : WrongAnimal() {
	std::cout << "WrongCat default constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const& that): WrongAnimal(that) {
	std::cout << "WrongCat copy constructor called" << std::endl;
	*this = that;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << std::endl;
}
