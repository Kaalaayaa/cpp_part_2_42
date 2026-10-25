#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other) : AForm(other), target(other.target) {}


PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const & other)
{
    AForm::operator=(other);
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::performAction() const
{
    std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
