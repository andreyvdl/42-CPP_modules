#include "../include/RobotomyRequestForm.class.hpp"
#include <cstdlib>
#include <ctime>

/* TRUCTORS ================================================================= */

RobotomyRequestForm::RobotomyRequestForm(void):
AForm("RobotomyRequestForm", 72, 45) {};

RobotomyRequestForm::RobotomyRequestForm(std::string const target):
AForm("RobotomyRequestForm", 72, 45), _target(target) {};

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& that)
{
	*this = that;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {};

/* OPERATORS ================================================================ */

RobotomyRequestForm& RobotomyRequestForm::operator=(
	RobotomyRequestForm const& that
)
{
	if (this != &that) {
		AForm::operator=(that);
		const_cast<std::string&>(_target) = that._target;
	}
	return (*this);
}

/* METHODS ================================================================== */

void RobotomyRequestForm::execute(Bureaucrat const& executor) const
throw(GradeTooLowException, NotSignedException, std::ios_base::failure)
{
	if (!getSigned()) {
		throw NotSignedException();
	} else if (executor.getGrade() > getExecGrade()) {
		throw GradeTooLowException();
	}

	srand(time(NULL));
	std::cout << "* Vrrrrrrrrrrrrrr *" << std::endl;
	if (rand() % 2) {
		std::cout << _target << " has been robotomized successfully!"
			<< std::endl;
	} else {
		std::cout << _target << " hasn't been robotomized!"
			<< std::endl;
	}
}
