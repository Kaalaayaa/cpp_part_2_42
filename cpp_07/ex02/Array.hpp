#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
private:
    unsigned int _size;
    T *data;

public:
    Array();
    Array(unsigned int size);
    Array(Array const &other);
    Array& operator=(Array const &other);
    ~Array();
    T& operator[](unsigned int index); // 
    const T& operator[](unsigned int index) const;
    unsigned int size() const;
};

#include "Array.tpp"

#endif

