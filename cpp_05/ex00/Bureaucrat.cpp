#include "Bureaucrat.hpp"

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

std::ostream& operator<<(std::ostream& out, Bureaucrat const& bureaucrat)
{
    out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
    return out;
}