/**
 * @file Animal.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Definition of the Animal class
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP
# include <iostream>
# include "Brain.class.hpp"

class Animal
{
	protected:
		std::string _type;

	public:
		Animal(void);
		Animal(Animal const& that);
		virtual ~Animal(void);
		Animal& operator=(Animal const& that);

		virtual void makeSound(void) const;
		std::string getType(void) const;
		virtual Brain* getBrain(void) const = 0;
};

#endif
