#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T_array, typename T_function >
void iter(T_array *array, const size_t length, T_function function)
{
    for (size_t i = 0; i < length; i++)
    {
        function(array[i]);
    }
}

#endif


/* NOTES
Goal: write one function template, iter, that takes an array, walks through every element, and calls a function you pass in on each one. Think of it like a generic "do this to every item in the list" tool.
The big new concept: passing a function AS a value
Everything you've done so far, a function either was called or wasn't — you never handed a function itself to another function as an argument. That's exactly what this exercise introduces.

The idea, in plain terms: a function, in memory, is just a block of code sitting at some address — same as a variable has an address. If you can store/pass the address of a function, you can later tell some other piece of code "go run whatever is at this address." That's what lets iter be generic: you don't hardcode what happens to each element — you hand iter a separate function, and iter calls that function on every element, without needing to know in advance what it actually does.

The syntax for "a variable that holds a function's address" (called a function pointer):


Any parameter whose type could genuinely vary (not fixed/known in advance) needs its own placeholder, so the compiler can figure out the real type from whatever gets passed in at the call site.

Reusing the same placeholder name across multiple parameters forces those parameters to all be the same type — whatever that type turns out to be — and the compiler will reject the call if you try to mix types where the same placeholder is expected to match.


Writing const size_t length explicitly in the signature is just a style choice — a way of saying out loud, "I promise not to even modify my own local copy inside this function," purely for the reader's clarity. It changes nothing about safety or behavior;


so we create a function template that has 2 placeholder 
"whenever we don't know in advance what type a particular parameter will be, we give it its own placeholder and let the compiler figure it out from whatever's actually passed in.


s: "I (iter) don't know in advance what exact type my third parameter will be — whether it's a plain function like addOne, a pointer to one, or an already-instantiated template function like print<int> — so I'll let the compiler figure out T_function's real type fresh, every time someone calls me.

Yes — that's exactly right, and it's a genuine compile-time safety net, not just a runtime check.

## Confirming the mechanism

If you pass a `const` array together with a function that tries to **modify** elements (takes a non-const `T&`), the compiler can't find any valid way to make that call work:

- The array is `const` → can't bind to a non-const pointer parameter.
- The modifying function needs `T&` → doesn't match what a read-only path expects (`T const&`).

**Neither path lines up, so it fails to compile** — this is exactly what you saw with your own `readOnlyArray` + `addToElement` combination (still commented out in your `main.cpp`, with your own correct note explaining why).

## Why this is actually a good thing, not just an inconvenience

This is the compiler **protecting you** — it's catching, before your program even runs, an attempt to modify data you explicitly said should never change. Without this, you'd risk a much worse situation: silently trying to write to memory that was never supposed to be writable, which in real (non-array) scenarios can cause actual crashes or undefined behavior at runtime, discovered only when something breaks unpredictably later. Here, the mistake gets caught immediately, with a clear compile error pointing at exactly the problem — far better than a mysterious bug showing up during actual execution.

## The core idea, stated plainly

**`const`-ness isn't just documentation or a suggestion — it's a real constraint the type system actively enforces.** By threading `const` through the array's type, through the template's placeholder, and through the function's parameter type, you get a guarantee verified automatically at compile time: "a read-only array can never accidentally end up in the hands of a function that tries to change it." That's the actual payoff of doing all this const-correctness work — not style, but a genuine, enforced safety guarantee.


Once you pass a const array to iter, every element becomes const — and only functions that can accept a const value (like ones taking T const &) are allowed to be called on it. 
*/