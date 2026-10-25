#include "Bureaucrat.hpp"
#include "Form.hpp"

/* TEST:
*construcot / copy constructor/ copy assgment/ function overload form
* getname, get issigned, get grade to sign...
* grade out of bound when creating form test for both grades
* be signed test by itself
* sign form function from bureaucrat test with different bureaucrat grade
*/
int main()
{
    std::cout << "--- constructor / copy constructor / copy assignment/ function overload << ---" << std::endl;

    Form f1("Vacation Request Form", 5, 1);
    Form f2(f1);
    Form f3("Request To Leave Early", 150, 140);
    f2 = f3;

    std::cout << f1 << std::endl;
    std::cout << f2 << std::endl;
    std::cout << f3 << std::endl;

    std::cout << "\n--- getName() / getGrade() ---" << std::endl;

    std::cout << f1.getName() << " is " << (f1.getIsSigned() ? "signed" : "not signed")
        << ", grade to sign: " << f1.getGradeToSign()
        << ", grade to execute: " << f1.getGradeToExecute() << std::endl;

    std::cout << "\n--- GradeTooHighException ---" << std::endl;

    try
    {
        Form f4("tooHigh", 0, 1);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- GradeTooLowException ---" << std::endl;

    try
    {
        Form f5("tooLow", 100, 151);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- beSigned()" << std::endl;

    Bureaucrat a("Kalaya", 1);
    f1.beSigned(a);
    std::cout << f1 << std::endl;

    std::cout << "\n--- beSigned() incorrect grade" << std::endl;

    Bureaucrat b("Bob", 150);
    try
    {
        f1.beSigned(b);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "\n--- signForm() ---" << std::endl;
    b.signForm(f3);
    std::cout << f3 << std::endl;

    std::cout << "\n--- signForm() incorrect grade ---" << std::endl;
    b.signForm(f2);
    std::cout << f2 << std::endl;

    return 0;
}
