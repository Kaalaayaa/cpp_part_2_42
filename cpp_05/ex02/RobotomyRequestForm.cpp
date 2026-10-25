#include "RobotomyRequestForm.hpp"
#include <cstdlib> // forn std::rand()
#include <ctime> // for std::time() 

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other) : AForm(other), target(other.target) {}


RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & other)
{
    AForm::operator=(other);
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::performAction() const
{
    std::cout << "*drilling noises *" << std::endl;
    std::srand(static_cast<unsigned int>(std::time(NULL)));
    if(std::rand() % 2 == 0)
        std::cout << target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "Robotomy failed." << std::endl;
}