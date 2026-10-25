#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

Bureaucrat:: Bureaucrat(Bureaucrat const& other) : name(other.name), grade(other.grade) {}

Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other)
{
    grade = other.grade;
    return *this;
}

Bureaucrat::~Bureaucrat(){}

void Bureaucrat::incrementGrade()
{
    grade--;
    if(grade < 1)
        throw Bureaucrat::GradeTooHighException();
}

void Bureaucrat::decrementGrade()
{
    grade++;
    if(grade > 150)
        throw Bureaucrat::GradeTooLowException();
}

std::string Bureaucrat::getName() const
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low";
}

void Bureaucrat::signForm(Form& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << name << " signed " << form.getName() << std::endl;

    }
    catch (std::exception & e)
    {
         std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << " (" << grade << ") " << std::endl;
    }
    
}

std::ostream& operator<<(std::ostream& out, Bureaucrat const& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}