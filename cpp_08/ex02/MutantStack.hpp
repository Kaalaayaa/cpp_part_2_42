#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> // contains push, pop, top , size
{
public:
    typedef typename std::stack<T>::container_type::iterator iterator;
    MutantStack();
    MutantStack(MutantStack const &other);
    MutantStack &operator=(MutantStack const &other);
    ~MutantStack();
    iterator begin();
    iterator end();
};

#include "MutantStack.tpp"

#endif

/*
AIM OF THE EXERCISE:
std::stack is deliberately NOT iterable — it only exposes push/pop/top/size/empty.
This exercise is about recognizing that std::stack is actually just a WRAPPER
around another container (std::deque by default) and getting access to that
underlying container to add the missing iteration feature.

KEY CONCEPTS LEARNED:

1) Inheriting from an STL container directly.
   `class MutantStack : public std::stack<T>` gives you every single one of
   std::stack's existing member functions (push, pop, top, size, empty) for
   free — you don't rewrite any of them, you just ADD to what's already there.

2) std::stack's protected member "c" — the actual storage.
   std::stack never stores elements itself. It's just a thin interface on top
   of a real container, held in a PROTECTED member literally named "c" (of
   type std::stack<T>::container_type, which is std::deque<T> by default).
   Because MutantStack PUBLICLY inherits from std::stack<T>, it has access
   to that protected "c" from inside its own member functions — something
   code outside the class (even outside MutantStack) could never reach.

3) begin()/end() just delegate to c's own iterators.
   No custom iterator class needed — c (a std::deque) already has its own
   begin()/end(). MutantStack::begin() is just "return this->c.begin();".

4) this->c, not just c — a template/base-class lookup rule.
   Inside a template class that inherits from another template (std::stack<T>
   depends on T), the compiler does NOT automatically search the base class
   for plain names like "c" — you have to write this->c (or
   std::stack<T>::c) to explicitly say "look in my base class for this."
   Forgetting "this->" here is a very common, confusing compile error.

5) typename std::stack<T>::container_type::iterator — reusing an existing
   iterator type instead of writing your own.
   container_type is a typedef std::stack itself provides, naming whatever
   container it's built on. ::iterator is THAT container's own iterator type.
   "typename" is required because, inside a template, the compiler can't
   otherwise be sure "container_type::iterator" names a type rather than
   something else, until T is actually known.

6) A MutantStack<int> can be implicitly treated as a plain std::stack<int>.
   Because inheritance is public, `std::stack<int> s(mstack);` just works —
   it's the same upcast idea from cpp_05 (a derived object IS-A base object).
*/
