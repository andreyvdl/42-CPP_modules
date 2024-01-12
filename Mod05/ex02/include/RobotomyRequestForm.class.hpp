#pragma once
#ifndef ROBOTOMY_REQUEST_FORM_CLASS_HPP
# define ROBOTOMY_REQUEST_FORM_CLASS_HPP

# include "AForm.abstract.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string	_target;

	public:
		RobotomyRequestForm(void);
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const& that);
		~RobotomyRequestForm(void);
		RobotomyRequestForm&	operator=(RobotomyRequestForm const& that);

		void	execute(Bureaucrat const& executor) const
			throw(GradeTooLowException, NotSignedException,
				std::ios_base::failure
			);
};

#endif
