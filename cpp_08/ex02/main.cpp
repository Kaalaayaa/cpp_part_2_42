#include "MutantStack.hpp"
#include <list>
#include <string>

int main()
{
    std::cout << "--- subject example ---" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl; // give top value

    mstack.pop(); // removes top value

    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack); // regular copy
    std::cout << "Copied stack top: " << s.top() << std::endl;

    std::cout << "\n--- same test with std::list ---" << std::endl;
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << list.back() << std::endl;
    list.pop_back();
    std::cout << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    for (std::list<int>::iterator listIt = list.begin();
         listIt != list.end(); ++listIt)
        std::cout << *listIt << std::endl;

    std::cout << "\n--- MutantStack with strings ---" << std::endl;
    MutantStack<std::string> words;
    words.push("hello");
    words.push("world");
    std::cout << "Top: " << words.top() << std::endl;

    for (MutantStack<std::string>::iterator wordIt = words.begin();
         wordIt != words.end(); ++wordIt)
        std::cout << *wordIt << std::endl;

    return 0;
}
