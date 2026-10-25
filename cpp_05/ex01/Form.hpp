#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
public:
    Form(std::string name, int gradeToSign, int gradeToExecute);
    Form(Form const &other);
    Form &operator=(Form const &other);
    ~Form();
    std::string getName() const;
    bool getIsSigned() const;
    int getGradeToSign() const;
    int getGradeToExecute() const;
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
   void beSigned(Bureaucrat& bureaucrat);

};

std::ostream & operator<<(std::ostream & out, Form const & form);

#endif