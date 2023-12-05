/**
 * @file Cat.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Definition of the Cat class.
 * @version 1
 * @date 2023-12-05
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP
# include "Animal.class.hpp"

class Cat: public Animal{
	public:
		Cat(void);
		Cat(Cat const& that);
		~Cat(void);
		Cat& operator=(Cat const& that);

		void makeSound(void) const;
};

#endif
