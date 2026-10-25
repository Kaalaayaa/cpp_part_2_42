#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(0), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
}

Form:: Form(Form const& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

Form& Form::operator=(Form const& other)
{
    isSigned = other.isSigned;
    return *this;
}

Form::~Form(){}


std::string Form::getName() const
{
    return name;
}

bool Form::getIsSigned() const
{
    return isSigned;
}

int Form::getGradeToSign() const
{
    return gradeToSign;
}

int Form::getGradeToExecute() const
{
    return gradeToExecute;
}

const char* Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeToSign)
    {
        isSigned = 1;
    }
    else
    {
        throw Form::GradeTooLowException();
    }
}

std::ostream& operator<<(std::ostream& out, Form const& form)
{
    out << form.getName() << ", status: " << (form.getIsSigned() ? "signed" : "not signed") << ", grade needed to be signed " << form.getGradeToSign() << ", grade needed to be executed " << form.getGradeToExecute() << ".";
    return out;
}