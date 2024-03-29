#pragma once
#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

# include <iostream>
# include <stdexcept>
# include "Grades.exception.hpp"
# include "AForm.abstract.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string	_name;
		int	_grade;
	
	public:
		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade)
			throw(GradeTooHighException, GradeTooLowException);
		Bureaucrat(Bureaucrat const& that);
		~Bureaucrat(void);
		Bureaucrat&	operator=(Bureaucrat const& that);

		const std::string	getName(void) const;
		int	getGrade(void) const;
		void	upGrade(void) throw(GradeTooHighException);
		void	downGrade(void) throw(GradeTooLowException);
		void	signForm(AForm& form);
		void	executeForm(AForm const& form) const;
};

std::ostream&	operator<<(std::ostream& oStream, const Bureaucrat& that);

#endif
