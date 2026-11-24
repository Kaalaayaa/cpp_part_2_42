#include "easyfind.hpp"
#include <vector>
#include <list>
#include <deque>

int main(void)
{
    int nonExistingValue = 76;

    std::cout << "\n--- Vector container tests ---" << std::endl;
    std::vector<int> vector; // empty vector of ints
    vector.push_back(5);// add to the end
    vector.push_back(1);
    vector.push_back(3);

    for(std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
    {
        std::cout << *it << " ";
    }

    std::vector<int>::iterator vectorIterator = ::easyfind(vector, 5);
    std::cout << "\nFound in vector: " << *vectorIterator << std::endl; // dereference iteroator to get value 
    
    try
    {
        std::vector<int>::iterator notFoundVectorIterator = ::easyfind(vector, nonExistingValue);
        std::cout << "Found in vector: " << *notFoundVectorIterator << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what()  << nonExistingValue << std::endl;
    }

    std::cout << "\n--- List container tests ---" << std::endl;
    std::list<int> list;
    list.push_back(25);
    list.push_back(32);
    list.push_back(46);

    for(std::list<int>::iterator it = list.begin(); it != list.end(); it++)
    {
        std::cout << *it << " ";
    }


    std::list<int>::iterator listIterator = ::easyfind(list, 25);
    std::cout << "\nFound in list: " << *listIterator << std::endl;

    try
    {
        std::list<int>::iterator notFoundListIterator = ::easyfind(list, nonExistingValue);
        std::cout << "Found in list: " << *notFoundListIterator << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what()  << nonExistingValue << std::endl;
    }

    std::cout << "\n--- Deque(double-ended queue) container tests ---" << std::endl;
    std::deque<int> deque;
    deque.push_back(57);
    deque.push_back(42);
    deque.push_front(18);
    deque.pop_back();

    for(std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
    {
        std::cout << *it << " ";
    }

    std::deque<int>::iterator dequeIterator = ::easyfind(deque, 57);
    std::cout << "\nFound in deque: " << *dequeIterator<< std::endl;

    try
    {
        std::list<int>::iterator notFoundDequeIterator = ::easyfind(list, nonExistingValue);
        std::cout << "Found in deque: " << *notFoundDequeIterator << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cout << e.what()  << nonExistingValue << std::endl;
    }

    return 0;
}
