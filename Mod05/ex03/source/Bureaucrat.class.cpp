#include "../include/Bureaucrat.class.hpp"
#include <cstdlib>
#include <ctime>

// TRUCTOR =====================================================================

Bureaucrat::Bureaucrat(void):
_name("NoName")
{
	std::srand(std::time(NULL));
	_grade = (rand() % 151) + 1;
}

Bureaucrat::Bureaucrat(std::string name, int grade)
throw(GradeTooHighException, GradeTooLowException):
_name(name), _grade(grade)
{
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat(Bureaucrat const& that)
{
	*this = that;
}

Bureaucrat::~Bureaucrat(void) {};

// OPERATOR ====================================================================

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& that)
{
	if (this != &that) {
		const_cast<std::string&>(_name) = that._name;
		_grade = that._grade;
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& oStream, Bureaucrat const& that)
{
	oStream << that.getName()<< ", bureaucrat grade " << that.getGrade();
	return (oStream);
}

// METHODS =====================================================================

const std::string Bureaucrat::getName(void) const
{
	return (_name);
}

int Bureaucrat::getGrade(void) const
{
	return (_grade);
}

void Bureaucrat::upGrade(void)
throw(GradeTooHighException)
{
	if (_grade == 1) {
		throw GradeTooHighException();
	} else {
		_grade--;
	}
}

void Bureaucrat::downGrade(void)
throw(GradeTooLowException)
{
	if (_grade == 150) {
		throw GradeTooLowException();
	} else {
		_grade++;
	}
}

void Bureaucrat::signForm(AForm& form)
{
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << _name << " cannot sign " << form.getName() << " because "
			<< e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const& form) const
{
	try {
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	} catch (std::exception& e) {
		std::cout << _name << " cannot execute " << form.getName()
			<< " because " << e.what() << std::endl;
	}
}
