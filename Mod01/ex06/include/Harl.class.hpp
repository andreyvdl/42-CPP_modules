/**
 * @file Harl.class.hpp
 * @author adantas- (adantas-@student.42sp.org.br)
 * @brief File for the Harl class.
 * @version 1
 * @date 2023-11-15
 * 
 * @copyright Copyright (c) 2023
 */

#pragma once
#ifndef HARL_CLASS_HPP
# define HARL_CLASS_HPP

# include <iostream>

class Harl {
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);

	public:
		Harl(void);
		~Harl(void);

		void complain(std::string level);
};

#endif
