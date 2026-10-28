#include "Base.hpp"
#include <cstdlib> // for std::rand()
#include <ctime> // for std::time() 

Base::~Base(){}

Base* generator(void)
{
    int randomValue = std::rand() % 3;
    if(randomValue == 0)
        return new A();
    else if(randomValue == 1)
        return new B();
    else
        return new C();
}// randomy instantiates A, B or C and returns them as Base pointer

void identify(Base* p)
{
    if(dynamic_cast<A*>(p))
        std::cout << "actual type is : A" << std::endl;
    else if(dynamic_cast<B*>(p))
        std::cout << "actual type is : B" << std::endl;
    else if(dynamic_cast<C*>(p))
        std::cout << "actual type is : C" << std::endl;
    else
        std::cout << "actual type is : Unknown" << std::endl;
}
// prints type of the object pointed to by p : A, B or C

void identify(Base& p)
{
    if(dynamic_cast<A*>(&p))
        std::cout << "actual type is : A" << std::endl;
    else if(dynamic_cast<B*>(&p))
        std::cout << "actual type is : B" << std::endl;
    else if(dynamic_cast<C*>(&p))
        std::cout << "actual type is : C" << std::endl;
    else
        std::cout << "actual type is : Unknown" << std::endl;
}// prints the type of the object referenced by p: A B or C


 // NOTES
 /*

 */