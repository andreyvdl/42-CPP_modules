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
# include "AAnimal.abstract.hpp"
# include "Brain.class.hpp"

class Cat: public AAnimal
{
	private:
		Brain* _brain;

	public:
		Cat(void);
		Cat(Cat const& that);
		~Cat(void);
		Cat& operator=(Cat const& that);

		void makeSound(void) const;
		Brain* getBrain(void) const;
};

#endif
