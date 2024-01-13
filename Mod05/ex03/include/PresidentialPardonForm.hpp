#pragma once
#ifndef PRESIDENTIAL_FORM_CLASS_HPP
# define PRESIDENTIAL_FORM_CLASS_HPP

# include "AForm.abstract.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string	_target;

	public:
		PresidentialPardonForm(void);
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const& that);
		~PresidentialPardonForm(void);
		PresidentialPardonForm&	operator=(PresidentialPardonForm const& that);

		void	execute(Bureaucrat const& executor) const
			throw(GradeTooLowException, NotSignedException,
				std::ios_base::failure
			);
};

#endif
