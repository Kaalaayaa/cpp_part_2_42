#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm
{
private:
    const std::string name;
    bool isSigned;
    const int gradeToSign;
    const int gradeToExecute;
public:
    AForm(std::string name, int gradeToSign, int gradeToExecute);
    AForm(AForm const &other);
    AForm &operator=(AForm const &other);
    virtual ~AForm();
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
    class NotSignedException : public std::exception
    {
        public:
            virtual const char* what() const throw();
    };
    void beSigned(Bureaucrat const & bureaucrat);
    virtual void execute(Bureaucrat const & executor) const;
    virtual void performAction() const = 0;

};

std::ostream & operator<<(std::ostream & out, AForm const & aForm);

#endif