#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
    std::cout << "--- makeForm() valid names ---" << std::endl;

    Intern intern;
    AForm* form1 = intern.makeForm("RobotomyRequestForm", "Bender");
    AForm* form2 = intern.makeForm("PresidentialPardonForm", "Max");
    AForm* form3 = intern.makeForm("ShrubberyCreationForm", "home");

    std::cout << "\n--- makeForm() invalid name ---" << std::endl;

    AForm* form4 = intern.makeForm("Form 28B", "nobody");

    std::cout << "\n--- sign and execute ---" << std::endl;

    Bureaucrat kalaya("Kalaya", 1);
    kalaya.signForm(*form1);
    kalaya.signForm(*form2);
    kalaya.signForm(*form3);

    kalaya.executeForm(*form1);
    kalaya.executeForm(*form2);
    kalaya.executeForm(*form3);

    std::cout << "\n--- cleanup ---" << std::endl;
    
    delete form1;
    delete form2;
    delete form3;
    delete form4;
    return 0;
}
