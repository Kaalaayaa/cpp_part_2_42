#include "Array.hpp"

//default constructor
template <typename T>
Array<T>::Array() : _size(0), data(NULL) {} //initialise to 0 = empty array;

//constructor
template <typename T>
Array<T>::Array(unsigned int size) : _size(size)
{
    data = new T[_size](); // the () iniziales by default to 0; 
}

//copy constructor
template <typename T>
Array<T>::Array(Array const &other)
{
    _size = other._size;
    data = new T[other._size];
    for (unsigned int i = 0; i < other._size; i++)
        data[i] = other.data[i];
}

//assigment operator
template <typename T>
Array<T>& Array<T>::operator=(Array const &other)
{
    if (this == &other)
        return *this; //????????
    
    delete[] data;
    data = new T[other._size];
    for (unsigned int i = 0; i < other._size; i++)
        data[i] = other.data[i];
    return *this;
}

//overload operator[]
template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= _size)
        throw std::exception();
    return data[index];
}

//overload operator[] for const arrays
template <typename T>
const T& Array<T>::operator[](unsigned int index) const
{
    if (index >= _size)
        throw std::exception();
    return data[index];
}

//size() function 
template <typename T>
unsigned int Array<T>::size() const
{
    return _size;
}

//delete
template <typename T>
Array<T>::~Array()
{
    delete[] data;
}

