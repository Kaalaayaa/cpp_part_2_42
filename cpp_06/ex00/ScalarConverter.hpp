#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cctype>
#include <climits>
#include <cstdlib>
#include <limits>
#include <cmath>

class ScalarConverter
{
private:
    ScalarConverter();
    ScalarConverter(ScalarConverter const &other);
    ScalarConverter &operator=(ScalarConverter const &other);
    ~ScalarConverter();
    static bool isChar(std::string const &literal);
    static bool isInt(std::string const &literal);
    static bool isFloat(std::string const &literal);
    static bool isDouble(std::string const &literal);
    static std::string getLiteralType(std::string const &literal);
    static void convertFromChar(std::string const &literal);
    static void convertFromInt(std::string const &literal);
    static void convertFromFloat(std::string const &literal);
    static void convertFromDouble(std::string const &literal);

public:
    static void convert(std::string const& literal);
};
#endif