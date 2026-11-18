#include "easyfind.hpp"
#include <vector>
#include <list>
int main(void)
{
    std::cout << "\n--- Vector container tests ---" << std::endl;
    std::vector<int> vector; // empty vector of ints
    vector.push_back(5);// add to the end
    vector.push_back(1);
    vector.push_back(3);

    std::vector<int>::iterator vectorIterator = ::easyfind(vector, 5);
    std::cout << "Found in vector: " << *vectorIterator << std::endl; // dereference iteroator to get value 
    
    try
    {
        std::vector<int>::iterator notFoundVectorIterator = ::easyfind(vector, 10);
        std::cout << "Found in vector: " << *notFoundVectorIterator << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Not found: " << e.what() << std::endl;
    }

    std::cout << "\n--- List container tests ---" << std::endl;
    std::list<int> list;
    list.push_back(25);
    list.push_back(32);
    list.push_back(46);

    std::list<int>::iterator listIterator = ::easyfind(list, 25);
    std::cout << "Found in list: " << *listIterator << std::endl;

    try
    {
        std::list<int>::iterator notFoundListIterator = ::easyfind(list, 76);
        std::cout << "Found in list: " << *notFoundListIterator << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << "Not found: " << e.what() << std::endl;
    }

    return 0;
}
