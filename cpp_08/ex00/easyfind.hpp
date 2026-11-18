#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class NotFoundException : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return "value not found in container";
        }
};

template <typename T> // T is a generic for which container type
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator iterator = std::find(container.begin(), container.end(), value);

    if(iterator == container.end())
        throw NotFoundException();
    
    return iterator;
}

#endif

/*
AIM OF THE EXERCISE:
Practice using an STL algorithm (std::find) instead of writing a manual search
loop by hand. easyfind is generic over the CONTAINER type (vector, list, deque...)
but assumes the ELEMENTS inside are always int, since it takes a plain int to
search for. The point is learning to lean on std::find + iterators + container.end()
as the "not found" sentinel, rather than reinventing linear search yourself.

STL alogithm : standard templace library algorithm
container : name for any things that can hold a group of values that we can add from remove or loop through
the STL provides some ready made containers we can use so we dont have to create it ourself( like the class Array)
std::vector = resizable array that manages its own memory (no new , no delete needed), know his size and we can acces elements with []

we cannot use our function on an plain array because she will not have the member functions necessary to use .end() like vector has. We can only use real container type like std::vector, std::list, ..

iterator = generic, reusiable "pointer" that knows how to walk through a containers element, one at the time.
std::vecotr<int>::iterator means the particular iterator type that belongs to a std::vector<int>



*/