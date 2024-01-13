#pragma once
#ifndef GRADES_EXCEPTION_HPP
# define GRADES_EXCEPTION_HPP

# include <stdexcept>

class GradeTooLowException: public std::exception
{
	public:
		virtual const char*	what() const throw();
};

class GradeTooHighException: public std::exception
{
	public:
		virtual const char*	what() const throw();
};

class NotSignedException: public std::exception
{
	public:
		virtual const char*	what() const throw();
};

#endif
