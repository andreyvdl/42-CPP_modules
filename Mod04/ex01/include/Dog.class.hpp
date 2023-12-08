/**
 * @file Dog.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Definition of the Dog class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP
# include "Animal.class.hpp"
# include "Brain.class.hpp"

class Dog: public Animal
{
	private:
		Brain* _brain;

	public:
		Dog(void);
		Dog(Dog const& that);
		~Dog(void);
		Dog& operator=(Dog const& that);

		void makeSound(void) const;
		Brain* getBrain(void) const;
};

#endif
