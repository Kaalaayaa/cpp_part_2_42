#include "Bureaucrat.hpp"

int main()
{
    std::cout << "--- constructor / copy constructor / copy assignment/ function overload << ---" << std::endl;

    Bureaucrat a("Kalaya", 1);
    Bureaucrat b(a);
    Bureaucrat c("Bim", 150);
    b = c;

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;

    std::cout << "\n--- getName() / getGrade() ---" << std::endl;

    std::cout << a.getName() << " is grade " << a.getGrade() << std::endl;

    std::cout << "\n--- GradeTooHighException ---" << std::endl;

    try
    {
        Bureaucrat d("tooHigh", 0);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- GradeTooLowException ---" << std::endl;

    try
    {
        Bureaucrat f("tooLow", 151);
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- incrementGrade() / decrementGrade()" << std::endl;

    std::cout << c << std::endl;
    c.incrementGrade();
    std::cout << "after increment: " << c << std::endl;
    c.decrementGrade();
    std::cout << "after decrement: " << c << std::endl;

    std::cout << "\n--- incrementGrade() out of range ---" << std::endl;

    try
    {
        std::cout << a << std::endl;
        a.incrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- decrementGrade() out of range ---" << std::endl;

    try
    {
        std::cout << b << std::endl;
        b.decrementGrade();
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
