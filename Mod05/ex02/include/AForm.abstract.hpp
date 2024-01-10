#pragma once
#ifndef AFORM_CLASS_HPP
# define AFORM_CLASS_HPP

# include <iostream>
# include "Grades.exception.hpp"
# include "Bureaucrat.class.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		bool				_signed;

	public:
				AForm(void);
				AForm(std::string const name, int signGrade, int execGrade)
					throw(GradeTooHighException, GradeTooLowException);
				AForm(AForm const& that);
				virtual ~AForm(void);
		AForm&	operator=(AForm const& that);

		const std::string	getName(void) const;
		int					getSignGrade(void) const;
		int					getExecGrade(void) const;
		bool				getSigned(void) const;
		void				beSigned(Bureaucrat const& that)
			throw(GradeTooLowException);
		void				execute(Bureaucrat const& executor) const;
};

std::ostream& operator<<(std::ostream& oStream, const AForm& that);

#endif
