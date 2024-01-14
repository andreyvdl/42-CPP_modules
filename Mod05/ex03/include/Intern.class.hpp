#pragma once
#ifndef INTERN_CLASS_HPP
# define INTERN_CLASS_HPP

# include "AForm.abstract.hpp"

class Intern
{
	public:
		Intern(void);
		Intern(Intern const& that);
		~Intern(void);
		Intern&	operator=(Intern const& that);

		AForm*	makeForm(std::string const& formName,
			std::string const& target
		) const;
};

#endif
