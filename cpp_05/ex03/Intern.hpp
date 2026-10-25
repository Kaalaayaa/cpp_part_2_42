#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include <string>
#include <exception>

class AForm;

class Intern
{
public:
    Intern();
    Intern (Intern const &other);
    Intern &operator=(Intern const &other);
    ~Intern();
    AForm* makeForm(std::string const &formName, std::string const &formTarget);
};

#endif