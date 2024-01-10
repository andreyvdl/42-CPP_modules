#include "../include/Form.class.hpp"
#include <cstdlib>
#include <ctime>

/* TRUCTORS ================================================================= */

Form::Form(void):
_name("JustAForm"), _signGrade(150), _execGrade(150), _signed(false)
{
	srand(time(NULL));
	const_cast<int&>(_signGrade) = rand() % 151 + 1;
	const_cast<int&>(_execGrade) = rand() % 151 + 1;
}

Form::Form(std::string const name, int signGrade, int execGrade)
throw(GradeTooHighException, GradeTooLowException):
_name(name), _signGrade(signGrade), _execGrade(execGrade), _signed(false)
{
	if (signGrade < 1 || execGrade < 1) {
		throw GradeTooHighException();
	} else if (signGrade > 150 || execGrade > 150) {
		throw GradeTooLowException();
	}
}

Form::Form(Form const& that):
_name("JustAForm"), _signGrade(150), _execGrade(150), _signed(false)
{
	*this = that;
}

Form::~Form(void) {};

/* OPERATORS ================================================================ */

Form& Form::operator=(Form const& that)
{
	if (this != &that) {
		const_cast<std::string&>(_name) = that.getName();
		const_cast<int&>(_signGrade) = that.getSignGrade();
		const_cast<int&>(_execGrade) = that.getExecGrade();
		_signed = that.getSigned();
	}
	return (*this);
}

std::ostream& operator<<(std::ostream& oStream, const Form& that)
{
	oStream << "Form_name: " << that.getName() << ", sign_grade: "
		<< that.getSignGrade() << ", exec_grade: " << that.getExecGrade()
		<< ", signed: ";
	if (that.getSigned()) {
		oStream << "Yes";
	} else {
		oStream << "No";
	}

	return (oStream);
}

/* METHODS ================================================================== */

const std::string Form::getName(void) const
{
	return (_name);
}

int Form::getSignGrade(void) const
{
	return (_signGrade);
}

int Form::getExecGrade(void) const
{
	return (_execGrade);
}

bool Form::getSigned(void) const
{
	return (_signed);
}

void Form::beSigned(Bureaucrat const& bureau) throw(GradeTooLowException)
{
	if (bureau.getGrade() > _signGrade) {
		throw GradeTooLowException();
	}
	_signed = true;
}
