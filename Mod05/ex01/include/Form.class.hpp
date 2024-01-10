#pragma once
#ifndef FORM_CLASS_HPP
# define FORM_CLASS_HPP

# include <iostream>
# include "Grades.exception.hpp"
# include "Bureaucrat.class.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_signed;

	public:
				Form(void);
				Form(std::string const name, int signGrade, int execGrade)
					throw(GradeTooHighException, GradeTooLowException);
				Form(Form const& that);
				~Form(void);
		Form&	operator=(Form const& that);

		const std::string	getName(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		bool				getSigned(void) const;
		void				beSigned(Bureaucrat const& that)
			throw(GradeTooLowException);
};

std::ostream& operator<<(std::ostream& oStream, const Form& that);

#endif
