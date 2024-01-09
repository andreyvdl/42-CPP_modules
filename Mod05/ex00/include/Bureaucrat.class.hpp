#pragma once
#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat
{
	private:
		const std::string	_name;
		int 				_grade;
	
	public:
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};
		
		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char*	what() const throw();
		};

		Bureaucrat(void);
		Bureaucrat(std::string const name, int grade)
			throw(GradeTooHighException, GradeTooLowException);
		Bureaucrat(Bureaucrat const& that);
		~Bureaucrat(void);
		Bureaucrat&	operator=(Bureaucrat const& that);

		const std::string	getName(void) const;
		int					getGrade(void) const;
		void 				upGrade(void) throw(GradeTooHighException);
		void 				downGrade(void) throw(GradeTooLowException);

};

std::ostream& operator<<(std::ostream& oStream, const Bureaucrat& that);

#endif
