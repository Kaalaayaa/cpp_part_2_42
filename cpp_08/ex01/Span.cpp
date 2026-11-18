#include "Span.hpp"

Span::Span(unsigned int N) : N(N){}

Span::Span(Span const &other) : N(other.N), numbers(other.numbers){}

Span &Span::operator=(Span const &other)
{
    if (this == &other)
        return *this;
    N = other.N;
    numbers = other.numbers;
    return *this;
}

Span::~Span(){}

void Span::addNumber(int value)
{
    if (numbers.size() >= N)
        throw SpanFullException();
    numbers.push_back(value);
}

int Span::longestSpan()
{
    if (numbers.size() < 2)
        throw NoSpanException();

    int smallest = *std::min_element(numbers.begin(), numbers.end());
    int biggest = *std::max_element(numbers.begin(), numbers.end());

    return biggest - smallest;
}

int Span::shortestSpan()
{
    if (numbers.size() < 2)
        throw NoSpanException();

    std::vector<int> sorted(numbers);
    std::sort(sorted.begin(), sorted.end());

    int smallestGap = sorted[1] - sorted[0];
    for (size_t i = 2; i < sorted.size(); i++)
    {
        int gap = sorted[i] - sorted[i - 1];
        if (gap < smallestGap)
            smallestGap = gap;
    }

    return smallestGap;
}
