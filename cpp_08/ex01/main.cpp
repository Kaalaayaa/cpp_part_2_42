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

    std::cout << "\n--- Span with 10,000 numbers via addRange ---" << std::endl;
    std::srand(static_cast<unsigned int>(std::time(NULL)));

    std::vector<int> randomNumbers;
    for (int i = 0; i < 10000; i++)
        randomNumbers.push_back(std::rand());

    Span bigSpan(10000);
    bigSpan.addRange(randomNumbers.begin(), randomNumbers.end());

    std::cout << "shortestSpan: " << bigSpan.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << bigSpan.longestSpan() << std::endl;

    std::cout << "\n--- SpanFullException: adding past capacity ---" << std::endl;
    try
    {
        Span tiny(2);
        tiny.addNumber(1);
        tiny.addNumber(2);
        tiny.addNumber(3);
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- SpanFullException: addRange past capacity ---" << std::endl;
    try
    {
        Span tinyRange(2);
        std::vector<int> three;
        three.push_back(1);
        three.push_back(2);
        three.push_back(3);
        tinyRange.addRange(three.begin(), three.end());
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- NoSpanException: empty Span ---" << std::endl;
    try
    {
        Span empty(5);
        std::cout << empty.shortestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    std::cout << "\n--- NoSpanException: Span with only one number ---" << std::endl;
    try
    {
        Span one(5);
        one.addNumber(42);
        std::cout << one.longestSpan() << std::endl;
    }
    catch (const std::exception &e)
    {
        std::cout << "Caught: " << e.what() << std::endl;
    }

    return 0;
}
