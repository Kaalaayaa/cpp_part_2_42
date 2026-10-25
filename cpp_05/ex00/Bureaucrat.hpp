#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP


#include <iostream>
#include <string>
#include <exception>

class Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &other);
    Bureaucrat &operator=(Bureaucrat const &other);
    ~Bureaucrat();
    void incrementGrade();
    void decrementGrade();
    std::string getName() const;
    int getGrade() const;
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    class GradeTooLowException: public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
};

std::ostream & operator<<(std::ostream & out, Bureaucrat const & bureaucrat);

#endif