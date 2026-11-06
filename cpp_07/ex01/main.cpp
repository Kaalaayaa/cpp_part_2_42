#include "iter.hpp"

template <typename T>
void printElement(T const &e)
{
    std::cout << e << " ";
}

void addToElement(int &e)
{
    e++;
    std::cout << e << " ";
}

int main(void)
{
    std::cout << "--- int array ---" << std::endl;
    int array[] = {1, 2, 3, 4, 5};
    ::iter(array, 5, printElement<int>);
    std::cout << "\nafter addToElement:" << std::endl;
    ::iter(array, 5, addToElement);

    std::cout << "\n--- char array ---" << std::endl;
    char arrayOfChar[] = {'a', 'b', 'c'};
    ::iter(arrayOfChar, 3, printElement<char>);

    std::cout << "\n--- std::string array ---" << std::endl;
    std::string arrayOfString[] = {"kalaya", "kayra", "mila"};
    ::iter(arrayOfString, 3, printElement<std::string>);

    std::cout << "\n--- const int array (read only) ---" << std::endl;
    const int readOnlyArray[] = {10, 11, 12};
    ::iter(readOnlyArray, 3, printElement<int>);
    //::iter(readOnlyArray, 3, addToElement); Not working because addToElement cannot take const
    
    return 0;
}
