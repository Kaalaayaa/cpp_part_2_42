#include "Base.hpp"
#include <cstdlib> // for std::rand()
#include <ctime> // for std::time() 

Base::~Base(){}

Base* generator(void)
{
    int randomValue = std::rand() % 3;
    if(randomValue == 0)
    {
        std::cout << "A was instanciated." <<std::endl;
        return new A();
    }
    else if(randomValue == 1)
    {
        std::cout << "B was instanciated." <<std::endl;
        return new B();
    }
    else
    {
        std::cout << "C was instanciated." <<std::endl;
        return new C();
    }
}

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

void identify(Base& p)
{
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "actual type is : A" << std::endl;
    }
    catch(const std::bad_cast&)
    {
        try
        {
            B& b = dynamic_cast<B&>(p);
            (void)b;
            std::cout << "actual type is : B" << std::endl;
        }
        catch(const std::bad_cast&)
        {
            try
            {
                C& c = dynamic_cast<C&>(p);
                (void)c;
                std::cout << "actual type is : C" << std::endl;
            }
            catch(const std::bad_cast&)
            {
                std::cout << "actual type is : Unknown" << std::endl;
            }
        }
        
    }
    
    if(dynamic_cast<A*>(&p))
        std::cout << "actual type is : A" << std::endl;
    else if(dynamic_cast<B*>(&p))
        std::cout << "actual type is : B" << std::endl;
    else if(dynamic_cast<C*>(&p))
        std::cout << "actual type is : C" << std::endl;
    else
        std::cout << "actual type is : Unknown" << std::endl;
}


 // NOTES
 /*

 */