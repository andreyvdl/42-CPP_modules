/**
 * @file Brain.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief Definiton of the Brain class.
 * @version 1
 * @date 2023-12-06
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP
# include <iostream>

class Brain {
	private:
		std::string _ideas[100];

	public:
		Brain(void);
		Brain(Brain const& that);
		~Brain(void);
		Brain& operator=(Brain const& that);

		void setIdea(std::string idea, unsigned int index);
		std::string getIdea(unsigned int index) const;
};

#endif
