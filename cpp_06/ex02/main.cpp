#include "Base.hpp"
#include <cstdlib> // for std::rand()
#include <ctime> // for std::time() 

int main()
{
    std::srand(static_cast<unsigned int>(std::time(NULL))); // initialize ran generator
    Base* p = generator();
    Base*& pRef= p;
    identify(p);
    identify(pRef);
    delete(p);
  
    return 0;
}