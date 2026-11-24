#include "Span.hpp"
#include <cstdlib>
#include <ctime>

int main(void)
{
    std::cout << "--- subject example ---" << std::endl;
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "\n--- test with 15 000 numbers ---" << std::endl;
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::vector<int> randomNumbers;
    for (int i = 0; i < 15000; i++)
        randomNumbers.push_back(std::rand());

    Span bigSpan(15000);
    bigSpan.addRange(randomNumbers.begin(), randomNumbers.end());

    std::cout << "shortestSpan: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << bigSpan.longestSpan() << std::endl;

    std::cout << "\n--- test span full ---" << std::endl;
    try
    {
        Span tiny(2);
        tiny.addNumber(1);
        tiny.addNumber(2);
        tiny.addNumber(3);
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- test empty span ---" << std::endl;
    try
    {
        Span empty(5);
        empty.shortestSpan();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n--- test span only 1 number---" << std::endl;
    try
    {
        Span one(5);
        one.addNumber(42);
        one.longestSpan();
    }
    catch (const std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}
