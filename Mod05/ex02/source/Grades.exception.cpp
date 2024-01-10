#include "../include/Grades.exception.hpp"

const char* GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char* GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}
