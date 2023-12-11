/**
 * @file AAnimal.abstract.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Definition of the Animal abstract class
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef A_ANIMAL_CLASS_HPP
# define A_ANIMAL_CLASS_HPP
# include <iostream>
# include "Brain.class.hpp"

class AAnimal
{
	protected:
		std::string _type;

	public:
		AAnimal(void);
		AAnimal(AAnimal const& that);
		virtual ~AAnimal(void);
		AAnimal& operator=(AAnimal const& that);

		virtual void makeSound(void) const = 0;
		std::string getType(void) const;
		virtual Brain* getBrain(void) const = 0;
};

#endif
