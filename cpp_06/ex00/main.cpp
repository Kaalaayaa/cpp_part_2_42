#include "ScalarConverter.hpp"

// int main(void)
// {

    // ./convert $'\t'      # passes an actual TAB character (ASCII 9) as the argument
    // ./convert $'\n'      # passes an actual NEWLINE character (ASCII 10)
    // ./convert $'\x07'    # passes BEL, the "bell" character (ASCII 7)
    // ./convert $'\x1b'    # passes ESC, the escape character (ASCII 27)

    // ScalarConverter::convert("\n"); 
    // ScalarConverter::convert("42"); 

    // // CHAR TEST
    // std::cout << "\nInput: \"0\" is a ";
    // ScalarConverter::convert("0");
    // std::cout << "\nInput: \"+\" is a ";
    // ScalarConverter::convert("+");
    // std::cout << "\nInput: \"99999999999999\" is a ";
    // ScalarConverter::convert("99999999999999");
    // std::cout << "\nInput: \"\" is a ";
    // ScalarConverter::convert("");

    // std::cout << "\nInput: \"s\" is a ";
    // ScalarConverter::convert("s");
    // std::cout << "\nInput: \".\" is a ";
    // ScalarConverter::convert(".");
    // std::cout << "\nInput: \" \" is a ";
    // ScalarConverter::convert(" ");

    // // INT TEST
    // std::cout << "\nInput: \"42\" is a ";
    // ScalarConverter::convert("42");
    // std::cout << "\nInput: \"a2\" is a ";
    // ScalarConverter::convert("a2");
    // std::cout << "\nInput: \"2b\" is a ";
    // ScalarConverter::convert("2b");
    // std::cout << "\nInput: \"+42\" is a ";
    // ScalarConverter::convert("+42");
    // std::cout << "\nInput: \"-42\" is a ";
    // ScalarConverter::convert("-42");
    // std::cout << "\nInput: \"++42\" is a ";
    // ScalarConverter::convert("++42");
    // std::cout << "\nInput: \"2445343\" is a ";
    // ScalarConverter::convert("2445343");
    // std::cout << "\nInput: \"2445343+\" is a ";
    // ScalarConverter::convert("2445343+");


    // //DOUBLE TESTS
    // std::cout << "\nInput: \"a.2\" is a ";
    // ScalarConverter::convert("a.2");
    // std::cout << "\nInput: \".2\" is a ";
    // ScalarConverter::convert(".2");
    // std::cout << "\nInput: \"2\" is a ";
    // ScalarConverter::convert("2");
    // std::cout << "\nInput: \"2.\" is a ";
    // ScalarConverter::convert("2.");
    // std::cout << "\nInput: \"..2\" is a ";
    // ScalarConverter::convert("..2");
    // std::cout << "\nInput: \"2..\" is a ";
    // ScalarConverter::convert("2..");
    // std::cout << "\nInput: \"2a.3\" is a ";
    // ScalarConverter::convert("2a.3");
    // std::cout << "\nInput: \"2.4\" is a ";
    // ScalarConverter::convert("2.4");
    // std::cout << "\nInput: \"+2.4\" is a ";
    // ScalarConverter::convert("+2.4");
    // std::cout << "\nInput: \"-2.10\" is a ";
    // ScalarConverter::convert("-2.10");
    // std::cout << "\nInput: \"----2.5\" is a ";
    // ScalarConverter::convert("----2.5");
    // std::cout << "\nInput: \"2.5----\" is a ";
    // ScalarConverter::convert("2.5----");
    // std::cout << "\nInput: \"nan\" is a ";
    // ScalarConverter::convert("nan");
    // std::cout << "\nInput: \"+inf\" is a ";
    // ScalarConverter::convert("+inf");
    // std::cout << "\nInput: \"-inf\" is a ";
    // ScalarConverter::convert("-inf");

    // //FLOAT TESTS
    // std::cout << "\nInput: \"a.2.f\" is a ";
    // ScalarConverter::convert("a.2.f");
    // std::cout << "\nInput: \".2.f\" is a ";
    // ScalarConverter::convert(".2.f");
    // std::cout << "\nInput: \"2f\" is a ";
    // ScalarConverter::convert("2f");
    // std::cout << "\nInput: \"2.f\" is a ";
    // ScalarConverter::convert("2.f");
    // std::cout << "\nInput: \"..2.f\" is a ";
    // ScalarConverter::convert("..2.f");
    // std::cout << "\nInput: \"2...f\" is a ";
    // ScalarConverter::convert("2...f");
    // std::cout << "\nInput: \"2a.3f\" is a ";
    // ScalarConverter::convert("2a.3f");
    // std::cout << "\nInput: \"2.4f\" is a ";
    // ScalarConverter::convert("2.4f");
    // std::cout << "\nInput: \"+2.4f\" is a ";
    // ScalarConverter::convert("+2.4f");
    // std::cout << "\nInput: \"-2.10f\" is a ";
    // ScalarConverter::convert("-2.10f");
    // std::cout << "\nInput: \"----2.5f\" is a ";
    // ScalarConverter::convert("----2.5f");
    // std::cout << "\nInput: \"2.5----f\" is a ";
    // ScalarConverter::convert("2.5----f");
    // std::cout << "\nInput: \"nanf\" is a ";
    // ScalarConverter::convert("nanf");
    // std::cout << "\nInput: \"+inff\" is a ";
    // ScalarConverter::convert("+inff");
    // std::cout << "\nInput: \"-inff\" is a ";
    // ScalarConverter::convert("-inff");
    // std::cout << "\nInput: \".ff\" is a ";
    // ScalarConverter::convert(".ff");

//     return 0;
// }

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        std::cout << "Usage ./convert <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}