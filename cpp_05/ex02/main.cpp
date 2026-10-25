#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    std::cout << "--- constructor / copy constructor / copy assignment / operator<< ---" << std::endl;

    ShrubberyCreationForm form1("home");
    RobotomyRequestForm form2("Kalaya");
    PresidentialPardonForm form3("Samson");

    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;
    std::cout << form3 << std::endl;

    std::cout << "\n--- signForm() ---" << std::endl;

    Bureaucrat kalaya("Kalaya", 1);
    kalaya.signForm(form1);
    kalaya.signForm(form2);
    kalaya.signForm(form3);

    std::cout << form1 << std::endl;
    std::cout << form2 << std::endl;
    std::cout << form3 << std::endl;

    std::cout << "\n--- signForm() low grade ---" << std::endl;

    ShrubberyCreationForm form4("garden");
    Bureaucrat bob("Bob", 150);
    bob.signForm(form4);

    std::cout << "\n--- executeForm() ---" << std::endl;

    kalaya.executeForm(form1);
    kalaya.executeForm(form2);
    kalaya.executeForm(form3);

    std::cout << "\n--- executeForm() unsigned form ---" << std::endl;

    kalaya.executeForm(form4);

    std::cout << "\n--- executeForm() low grade ---" << std::endl;

    PresidentialPardonForm form5("Max");
    kalaya.signForm(form5);
    bob.executeForm(form5);

    return 0;
}
