#include "MutantStack.hpp"

int main()
{
    std::cout << "--- subject example ---" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << mstack.top() << std::endl;

    mstack.pop();

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

    std::cout << "\n--- MutantStack IS-A std::stack (public inheritance) ---" << std::endl;
    std::stack<int> s(mstack);
    std::cout << "copied into plain std::stack, top = " << s.top() << std::endl;

    std::cout << "\n--- all the original std::stack member functions still work ---" << std::endl;
    std::cout << "empty: " << mstack.empty() << std::endl;
    std::cout << "size: " << mstack.size() << std::endl;

    return 0;
}
