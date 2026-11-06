#include "Array.hpp"
#include <string>

int main(void)
{
    std::cout << "--- int array: construct + operator[] ---" << std::endl;
    Array<int> a(5);
    for (unsigned int i = 0; i < 5; i++)
        a[i] = i;
    for (unsigned int i = 0; i < 5; i++)
        std::cout << a[i] << std::endl;

    std::cout << "\n--- default constructor (empty array) ---" << std::endl;
    Array<int> empty;
    std::cout << "empty.size() = " << empty.size() << std::endl;

    std::cout << "\n--- size() ---" << std::endl;
    std::cout << "a.size() = " << a.size() << std::endl;

    std::cout << "\n--- copy constructor: deep copy check ---" << std::endl;
    Array<int> copy(a);
    std::cout << "copy before modification: ";
    for (unsigned int i = 0; i < copy.size(); i++)
        std::cout << copy[i] << " ";
    std::cout << std::endl;

    copy[0] = 999;
    std::cout << "copy after modifying copy[0]: " << copy[0] << std::endl;
    std::cout << "a[0] (original, should be unchanged): " << a[0] << std::endl;

    std::cout << "\n--- operator=: deep copy check ---" << std::endl;
    Array<int> assigned(5);
    assigned = a;
    assigned[1] = 777;
    std::cout << "assigned[1] after modification: " << assigned[1] << std::endl;
    std::cout << "a[1] (original, should be unchanged): " << a[1] << std::endl;

    std::cout << "\n--- const Array: const operator[] ---" << std::endl;
    const Array<int> constArr(a);
    std::cout << "constArr[2] = " << constArr[2] << std::endl;

    std::cout << "\n--- out of bounds: operator[] should throw ---" << std::endl;
    try
    {
        std::cout << a[10] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "caught exception for index 10" << std::endl;
    }

    try
    {
        std::cout << a[-1] << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << "caught exception for index -1" << std::endl;
    }

        std::cout << "--- std::string array: construct + operator[] ---" << std::endl;
    Array<std::string> names(3);
    names[0] = "kalaya";
    names[1] = "kayra";
    names[2] = "mila";
    for (unsigned int i = 0; i < names.size(); i++)
        std::cout << names[i] << std::endl;

    return 0;
}
