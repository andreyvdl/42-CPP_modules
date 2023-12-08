/**
 * @file WrongAnimal.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Definition for the WrongAnimal class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#pragma once
#ifndef WRONG_ANIMAL_CLASS_HPP
# define WRONG_ANIMAL_CLASS_HPP
# include <iostream>

class WrongAnimal
{
	protected:
		std::string _type;

	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const& that);
		~WrongAnimal(void);
		WrongAnimal& operator=(WrongAnimal const& that);

		void makeSound(void) const;
		std::string getType(void) const;
};

#endif
