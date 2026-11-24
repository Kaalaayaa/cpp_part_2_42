#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class SpanFullException : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return "Span is full cannot add more";
        }
};

class NoSpanException : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return "No span found , needs at least 2 numbers";
        }
};

class Span
{
public:
    Span();
    Span(unsigned int N);
    Span(Span const &other);
    Span& operator=(Span const &other);
    ~Span();
    void addNumber(int value);
    int longestSpan();
    int shortestSpan();
    void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);

private:
    unsigned int N;
    std::vector<int> numbers;

};

#endif

