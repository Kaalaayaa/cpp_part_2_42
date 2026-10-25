#include "Intern.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {}

Intern:: Intern(Intern const& other)
{
   (void)other;
}

Intern& Intern::operator=(Intern const& other)
{
    (void)other;
    return *this;
}

Intern::~Intern(){}

AForm* Intern::makeForm(std::string const &formName, std::string const &formTarget)
{
    AForm* form = NULL;

    if(formName == "RobotomyRequestForm")
        form = new RobotomyRequestForm(formTarget);
    if(formName == "PresidentialPardonForm")
        form = new PresidentialPardonForm(formTarget);
    if(formName == "ShrubberyCreationForm")
        form = new ShrubberyCreationForm(formTarget);
    
    if(form == NULL)
    {
        std::cout << formName << " does not exist " << std::endl;
        return NULL;
    }
    std::cout << "Intern creates " << formName << std::endl;
    return form ;
}
