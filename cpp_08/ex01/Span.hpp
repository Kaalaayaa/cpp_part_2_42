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
    Span(unsigned int N);
    Span(Span const &other);
    Span& operator=(Span const &other);
    ~Span();
    void addNumber(int value);
    int longestSpan();
    int shortestSpan();

    template <typename InputIterator>
    void addRange(InputIterator begin, InputIterator end)
    {
        for (InputIterator it = begin; it != end; ++it)
        {
            if (numbers.size() >= N)
                throw SpanFullException();
            numbers.push_back(*it);
        }
    }

private:
    unsigned int N;
    std::vector<int> numbers;

};

#endif

/*
AIM OF THE EXERCISE:
Practice using std::vector as real internal storage (instead of hand-rolling
new[]/delete[] like Array did in cpp_07), and practice reaching for STL
algorithms (std::min_element, std::max_element, std::sort) instead of writing
manual search/comparison loops.

KEY CONCEPTS LEARNED:

1) std::vector as storage = deep copy for free.
   Since "numbers" is a std::vector, the copy constructor and operator= just
   copy it directly (numbers(other.numbers) / numbers = other.numbers) and
   vector's OWN copy logic handles allocating new memory + copying values
   correctly. No manual new[]/loop needed, unlike Array<T>.

2) longestSpan() — no sorting needed.
   *std::max_element(...) - *std::min_element(...) directly gives the answer.
   Both return an ITERATOR pointing at the biggest/smallest value, hence the
   "*" to dereference and get the actual int.

3) shortestSpan() — sort first, then only check ADJACENT pairs.
   Once sorted, the two numbers with the smallest gap are ALWAYS neighbors
   in sorted order. So instead of comparing every pair against every other
   pair, you only need to walk through the sorted copy once, checking each
   consecutive pair — much simpler than brute-forcing all combinations.
   Sort a COPY (std::vector<int> sorted(numbers)) so the original "numbers"
   order isn't disturbed.

4) addRange — a template MEMBER FUNCTION inside an otherwise NON-template
   class. Span itself isn't a template, but addRange needs to work with any
   iterator type (vector's, list's, etc.), so IT specifically is templated.
   Because of the usual template rule (full body must be visible wherever
   used), this one function has to live directly in the header, even though
   every other Span method lives in Span.cpp as normal.

5) Two different exceptions for two different problems:
   - SpanFullException: addNumber() or addRange() tried to add past capacity N.
   - NoSpanException: shortestSpan()/longestSpan() called with fewer than 2
     numbers stored — there's no "span" to compute at all.
*/

