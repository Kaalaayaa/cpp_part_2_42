#include "ScalarConverter.hpp"
#include <cctype>

/*  ⠀⠀⠄⠀⢀⣴⡇⠀⠀⠀⠈⠀⠀⣦⡀⠀⡀⠀                ⢀⠀⢀⣴⠀⠀⠁⠀⠀⠀⢸⣦⡀⠀⠠⠀⠀
 *  ⢠⡀⠀⠀⣼⣿⣇⠀⠈⣴⠀⠀⣠⣿⡗⠀⣰⡇               ⢸⣆⠀⢺⣿⣄⠀⠀⣦⠁⠀⣸⣿⣧⠀⠀⢀⡄
 *  ⢸⣷⡀⠀⢻⣿⣿⡄⢸⣿⡀⢰⣿⣿⠇⠀⣿⣷               ⣾⣿⠀⠸⣿⣿⡆⢀⣿⡇⢠⣿⣿⡟⠀⢀⣾⡇
 *  ⣿⣿⣧⣠⣾⣿⣿⣧⣸⣿⣧⣼⣿⣿⣧⣰⣿⣿ CONSTRUCTORS ⣿⣿⣆⣼⣿⣿⣧⣼⣿⣇⣼⣿⣿⣷⣄⣼⣿⣿ */

ScalarConverter::ScalarConverter(){}

ScalarConverter:: ScalarConverter(ScalarConverter const& other)
{
    (void)other;
}

ScalarConverter& ScalarConverter::operator=(ScalarConverter const& other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter(){}

/*  ⠀⠀⠄⠀⢀⣴⡇⠀⠀⠀⠈⠀⠀⣦⡀⠀⡀⠀                   ⠀    ⢀⠀⢀⣴⠀⠀⠁⠀⠀⠀⢸⣦⡀⠀⠠⠀⠀
 *  ⢠⡀⠀⠀⣼⣿⣇⠀⠈⣴⠀⠀⣠⣿⡗⠀⣰⡇                       ⢸⣆⠀⢺⣿⣄⠀⠀⣦⠁⠀⣸⣿⣧⠀⠀⢀⡄
 *  ⢸⣷⡀⠀⢻⣿⣿⡄⢸⣿⡀⢰⣿⣿⠇⠀⣿⣷                       ⣾⣿⠀⠸⣿⣿⡆⢀⣿⡇⢠⣿⣿⡟⠀⢀⣾⡇
 *  ⣿⣿⣧⣠⣾⣿⣿⣧⣸⣿⣧⣼⣿⣿⣧⣰⣿⣿ WHICH TYPE FUNCTIONS ⣿⣿⣆⣼⣿⣿⣧⣼⣿⣇⣼⣿⣿⣷⣄⣼⣿⣿ */


bool ScalarConverter::isChar(std::string const& literal)
{
    return literal.length() == 1 && !std::isdigit(literal[0]);
}

bool ScalarConverter::isInt(std::string const& literal)
{
    size_t i = 0;

    if(literal[i] == '+' || literal[i] == '-' )
        i++;
    if (i == literal.length())
        return 0;
    while(i < literal.length() && std::isdigit(literal[i]))
        i++;
    if(i == literal.length())
        return 1;
    return 0;
}

bool ScalarConverter::isFloat(std::string const& literal)
{
    size_t i = 0;
    bool hasDigit = 0;

    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return 1;
    if (literal[i] == '+' || literal[i] == '-' )
        i++;
    while (i < literal.length() && std::isdigit(literal[i]))
    {
        i++;
        hasDigit = 1;
    }
    if (i < literal.length() && literal[i] == '.')
    {
        i++;
        while (i < literal.length() && std::isdigit(literal[i]))
        {
            i++;
            hasDigit = 1;
        }
    }
    if (!hasDigit)
        return 0;
    if (i < literal.length() && literal[i] == 'f' && i == literal.length() - 1)
        return 1;
    return 0;
}

bool ScalarConverter::isDouble(std::string const& literal)
{
    size_t i = 0;
    bool hasDigit = 0;

    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return 1;
    if (literal[i] == '+' || literal[i] == '-' )
        i++;
    while (i < literal.length() && std::isdigit(literal[i]))
    {
        i++;
        hasDigit = 1;
    }
    if (i < literal.length() && literal[i] == '.')
    {
        i++;
        while(i < literal.length() && std::isdigit(literal[i]))
        {
            i++;
            hasDigit = true;
        }
    }
    if (!hasDigit)
        return 0;
    if (i == literal.length())
        return 1;

    return 0;
}

std::string ScalarConverter::getLiteralType(std::string const &literal)
{
    if(isChar(literal))
        return "char";
    if(isInt(literal))
        return "int";
    if(isFloat(literal))
        return "float";
    if(isDouble(literal))
        return "double";
    return "invalid type";
}

/*  ⠀⠀⠄⠀⢀⣴⡇⠀⠀⠀⠈⠀⠀⣦⡀⠀⡀⠀                   ⠀ ⢀⠀⢀⣴⠀⠀⠁⠀⠀⠀⢸⣦⡀⠀⠠⠀⠀
 *  ⢠⡀⠀⠀⣼⣿⣇⠀⠈⣴⠀⠀⣠⣿⡗⠀⣰⡇                    ⢸⣆⠀⢺⣿⣄⠀⠀⣦⠁⠀⣸⣿⣧⠀⠀⢀⡄
 *  ⢸⣷⡀⠀⢻⣿⣿⡄⢸⣿⡀⢰⣿⣿⠇⠀⣿⣷                    ⣾⣿⠀⠸⣿⣿⡆⢀⣿⡇⢠⣿⣿⡟⠀⢀⣾⡇
 *  ⣿⣿⣧⣠⣾⣿⣿⣧⣸⣿⣧⣼⣿⣿⣧⣰⣿⣿ CONVERT FUNCTIONS ⣿⣿⣆⣼⣿⣿⣧⣼⣿⣇⣼⣿⣿⣷⣄⣼⣿⣿ */


void ScalarConverter::convertFromChar(std::string const &literal)
{
    char c = literal[0];

    if (std::isprint(static_cast<unsigned char>(c))) //is print check that its printable char
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;

    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<int>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<int>(c) << ".0" << std::endl;
}

void ScalarConverter::convertFromInt(std::string const &literal)
{
    long value = std::strtol(literal.c_str(), NULL, 10); //to check the range (base 10 / 0- 9 decimal);

    if (value < INT_MIN || value > INT_MAX) // does it fit in int range
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }
    int n = static_cast<int>(value);

    if (n < 0 || n > 127 || !std::isprint(n))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
    std::cout << "int: " << n << std::endl;
    std::cout << "float: " << n << ".0f" << std::endl;
    std::cout << "double: " << n << ".0" << std::endl;
}

void ScalarConverter::convertFromFloat(std::string const &literal)
{
    if (literal == "nanf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (literal == "+inff" || literal == "-inff")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << (literal[0] == '-' ? "-inf" : "+inf") << std::endl;
        return;
    }

    float f = static_cast<float>(std::strtod(literal.c_str(), NULL));

    if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        int n = static_cast<int>(f);
        if (n < 0 || n > 127 || !std::isprint(n))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
        std::cout << "int: " << n << std::endl;
    }

    std::cout << "float: " << f;
    if (f == std::floor(f)) // is it a whole number ? if yes print .0 cause std::cout removes it 
        std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << static_cast<double>(f);
    if (f == std::floor(f))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convertFromDouble(std::string const &literal)
{
    if (literal == "nan")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
        return;
    }
    if (literal == "+inf" || literal == "-inf")
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << (literal[0] == '-' ? "-inff" : "+inff") << std::endl;
        std::cout << "double: " << literal << std::endl;
        return;
    }

    double d = std::strtod(literal.c_str(), NULL);

    if (d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX))
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
    }
    else
    {
        int n = static_cast<int>(d);
        if (n < 0 || n > 127 || !std::isprint(n))
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
        std::cout << "int: " << n << std::endl;
    }

    std::cout << "float: " << static_cast<float>(d);
    if (d == std::floor(d))
        std::cout << ".0";
    std::cout << "f" << std::endl;

    std::cout << "double: " << d;
    if (d == std::floor(d))
        std::cout << ".0";
    std::cout << std::endl;
}

void ScalarConverter::convert(std::string const& literal)
{
    std::string type = getLiteralType(literal);
    if (type == "char")
        convertFromChar(literal);
    else if (type == "int")
        convertFromInt(literal);
    else if (type == "float")
        convertFromFloat(literal);
    else if (type == "double")
        convertFromDouble(literal);
    else
        std::cout << "Invalid input" << std::endl;
}
