#pragma once
#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

#include <iostream>
#include <stdexcept>

class Bureaucrat
{
	private:
		const std::string	_name;
		uint8_t				_grade;
	
	public:
							Bureaucrat(void);
							Bureaucrat(std::string const name, uint8_t grade);
							Bureaucrat(Bureaucrat const& that);
							~Bureaucrat(void);
		Bureaucrat&			operator=(Bureaucrat const& that);

		const std::string	getName(void);
		uint8_t				getGrade(void);
		void				upGrade(void);
		void				downGrade(void);

	class GradeTooHighException: public std::exception
	{
		public:
			virtual char* const	what(void) const throw(GradeTooHighException);
	};
	
	class GradeTooLowException: public std::exception
	{
		public:
			virtual char* const	what(void) const throw(GradeTooLowException);
	};
}

std::ostream& operator<<(std::ostream& oStream, Bureaucrat const& that);

#endif
