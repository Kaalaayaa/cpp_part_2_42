#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other) : AForm(other), target(other.target) {}


ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const & other)
{
    AForm::operator=(other);
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::performAction() const
{
    std::ofstream file;
        std::string filename = target + "_shrubbery";
        file.open(filename.c_str()); // convert std::string to const char*

        if (!file.is_open())
        {
            std::cout << "Error: could not create file " << filename << std::endl;
            return;
        }

        file << "     &&& &&  & &&\n";
        file << "  && &\\/&\\|& ()|/ @, &&\n";
        file << "  &\\/(/&||/&||/ () &||\\/&\n";
        file << "&() &\\/&|())()/&\\/&||()|/&\n";
        file << " &_\\/_\\_\\\\||/_&_|_/_||_/_&\n";
        file << "        |  |  |\n";

        file.close();
}