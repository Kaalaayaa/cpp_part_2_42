#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class NotFoundException : public std::exception
{
    public:
        virtual const char *what() const throw()
        {
            return "Value not found: ";
        }
};

template <typename T> // could be vector, link or deque 
typename T::iterator easyfind(T &container, int value)
{
    typename T::iterator iterator = std::find(container.begin(), container.end(), value);

    if(iterator == container.end())
        throw NotFoundException();
    
    return iterator;
}

#endif