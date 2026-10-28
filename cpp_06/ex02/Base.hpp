#ifndef BASE_HPP
# define BASE_HPP

#include <iostream>
#include <string>

class Base
{
public:
    virtual ~Base();
};

class A : public Base{};

class B : public Base {};

class C : public Base {};

Base* generator(void); // randomy instantiates A, B or C and returns them as Base pointer
void identify(Base* p); // prints type of the object pointed to by p : A, B or C
void identify(Base& p);// prints the type of the object referenced by p: A B or C

#endif