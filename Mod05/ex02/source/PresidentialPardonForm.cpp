#include "../include/PresidentialPardonForm.hpp"

/* TRUCTORS ================================================================= */

PresidentialPardonForm::PresidentialPardonForm(void):
AForm("PresidentialPardonForm", 25, 5), _target("NoTarget") {};

PresidentialPardonForm::PresidentialPardonForm(std::string const target):
AForm("PresidentialPardonForm", 25, 5), _target(target) {};

PresidentialPardonForm::PresidentialPardonForm(
	PresidentialPardonForm const& that
):
AForm("PresidentialPardonForm", 25, 5), _target("NoTarget")
{
	*this = that;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {};

/* OPERATORS ================================================================ */

PresidentialPardonForm& PresidentialPardonForm::operator=(
	PresidentialPardonForm const& that
)
{
	if (this != &that) {
		AForm::operator=(that);
		const_cast<std::string&>(_target) = that._target;
	}
	return (*this);
}

/* METHODS ================================================================== */

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
throw(GradeTooLowException, NotSignedException, std::ios_base::failure)
{
	if (!getSigned()) {
		throw NotSignedException();
	} else if (executor.getGrade() > getExecGrade()) {
		throw GradeTooLowException();
	}
	std::cout << _target << " has been pardoned by Zafod Beeblebrox." << std::endl;
}
