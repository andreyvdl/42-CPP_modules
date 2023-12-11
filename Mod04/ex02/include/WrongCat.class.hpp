/**
 * @file WrongCat.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Definition of the WrongCat class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef WRONG_CAT_CLASS_HPP
# define WRONG_CAT_CLASS_HPP
# include "WrongAnimal.class.hpp"
# include <iostream>

class WrongCat: public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat const& that);
		~WrongCat(void);
		WrongCat& operator=(WrongCat const& that);

		void makeSound(void) const;
};

#endif
