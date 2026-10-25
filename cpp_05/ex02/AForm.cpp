#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(std::string name, int gradeToSign, int gradeToExecute) : name(name), isSigned(0), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
    if(gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
}

AForm:: AForm(AForm const& other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute) {}

AForm& AForm::operator=(AForm const& other)
{
    isSigned = other.isSigned;
    return *this;
}

AForm::~AForm(){}


std::string AForm::getName() const
{
    return name;
}

bool AForm::getIsSigned() const
{
    return isSigned;
}

int AForm::getGradeToSign() const
{
    return gradeToSign;
}

int AForm::getGradeToExecute() const
{
    return gradeToExecute;
}

const char* AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

const char* AForm::NotSignedException::what() const throw()
{
    return "Form is not signed";
}

void AForm::beSigned(Bureaucrat const & bureaucrat)
{
    if (bureaucrat.getGrade() <= gradeToSign)
    {
        isSigned = 1;
    }
    else
    {
        throw AForm::GradeTooLowException();
    }
}

void AForm::execute(Bureaucrat const & executor) const
{
    if(!isSigned)
        throw AForm::NotSignedException();
    if(executor.getGrade() > gradeToExecute)
        throw AForm::GradeTooLowException();
    performAction();
}

std::ostream& operator<<(std::ostream& out, AForm const& aForm)
{
    out << aForm.getName() << ", status: " << (aForm.getIsSigned() ? "signed" : "not signed") << ", grade needed to be signed " << aForm.getGradeToSign() << ", grade needed to be executed " << aForm.getGradeToExecute() << ".";
    return out;
}