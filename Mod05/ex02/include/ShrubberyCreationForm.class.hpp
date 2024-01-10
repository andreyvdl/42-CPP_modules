#pragma once
#ifndef SHRUBBERY_CREATION_FORM_CLASS_HPP
# define SHRUBBERY_CREATION_FORM_CLASS_HPP

# include "AForm.abstract.hpp"
# include <iostream>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string	_target;

	public:
								ShrubberyCreationForm(void);
								ShrubberyCreationForm(
									ShrubberyCreationForm const& that
								);
								~ShrubberyCreationForm(void);
		ShrubberyCreationForm&	operator=(ShrubberyCreationForm const& that);

		
};

#endif
