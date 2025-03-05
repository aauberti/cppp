#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string const name, int gradeToSign, int gradeToExecute)
    : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

Form::Form(const Form& other)
    : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {}

Form::~Form() {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        _signed = other._signed;
    }
    return *this;
}

std::string Form::getName() const {
    return _name;
}

bool Form::isSigned() const {
    return _signed;
}

int Form::getGradeToSign() const {
    return _gradeToSign;
}

int Form::getGradeToExecute() const {
    return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.getGrade() > _gradeToSign)
        throw GradeTooLowException();
    _signed = true;
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << form.getName() << ", form grade to sign: " << form.getGradeToSign()
        << ", form grade to execute: " << form.getGradeToExecute()
        << ", is signed: " << (form.isSigned() ? "Yes" : "No");
    return out;
}
