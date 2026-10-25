#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"


class PresidentialPardonForm : public AForm
{
private:
    const std::string target;
public:
    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(PresidentialPardonForm const &other);
    PresidentialPardonForm &operator=(PresidentialPardonForm const &other);
    virtual ~PresidentialPardonForm();
    virtual void performAction() const;
};

#endif