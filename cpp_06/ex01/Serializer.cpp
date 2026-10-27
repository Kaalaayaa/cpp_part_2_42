#include "Serializer.hpp"

/*  ⠀⠀⠄⠀⢀⣴⡇⠀⠀⠀⠈⠀⠀⣦⡀⠀⡀⠀                ⢀⠀⢀⣴⠀⠀⠁⠀⠀⠀⢸⣦⡀⠀⠠⠀⠀
 *  ⢠⡀⠀⠀⣼⣿⣇⠀⠈⣴⠀⠀⣠⣿⡗⠀⣰⡇               ⢸⣆⠀⢺⣿⣄⠀⠀⣦⠁⠀⣸⣿⣧⠀⠀⢀⡄
 *  ⢸⣷⡀⠀⢻⣿⣿⡄⢸⣿⡀⢰⣿⣿⠇⠀⣿⣷               ⣾⣿⠀⠸⣿⣿⡆⢀⣿⡇⢠⣿⣿⡟⠀⢀⣾⡇
 *  ⣿⣿⣧⣠⣾⣿⣿⣧⣸⣿⣧⣼⣿⣿⣧⣰⣿⣿ CONSTRUCTORS ⣿⣿⣆⣼⣿⣿⣧⣼⣿⣇⣼⣿⣿⣷⣄⣼⣿⣿ */

Serializer::Serializer(){}

Serializer:: Serializer(Serializer const& other)
{
    (void)other;
}

Serializer& Serializer::operator=(Serializer const& other)
{
    (void)other;
    return *this;
}

Serializer::~Serializer(){}

/*  ⠀⠀⠄⠀⢀⣴⡇⠀⠀⠀⠈⠀⠀⣦⡀⠀⡀⠀                   ⠀    ⢀⠀⢀⣴⠀⠀⠁⠀⠀⠀⢸⣦⡀⠀⠠⠀⠀
 *  ⢠⡀⠀⠀⣼⣿⣇⠀⠈⣴⠀⠀⣠⣿⡗⠀⣰⡇                       ⢸⣆⠀⢺⣿⣄⠀⠀⣦⠁⠀⣸⣿⣧⠀⠀⢀⡄
 *  ⢸⣷⡀⠀⢻⣿⣿⡄⢸⣿⡀⢰⣿⣿⠇⠀⣿⣷                       ⣾⣿⠀⠸⣿⣿⡆⢀⣿⡇⢠⣿⣿⡟⠀⢀⣾⡇
 *  ⣿⣿⣧⣠⣾⣿⣿⣧⣸⣿⣧⣼⣿⣿⣧⣰⣿⣿ WHICH TYPE FUNCTIONS ⣿⣿⣆⣼⣿⣿⣧⣼⣿⣇⣼⣿⣿⣷⣄⣼⣿⣿ */

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr); // unsigned pointer type  
    return raw;
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data* ptr;
    ptr = reinterpret_cast<Data*>(raw);
    return ptr;
}

/*  ⠀⠀⠄⠀⢀⣴⡇⠀⠀⠀⠈⠀⠀⣦⡀⠀⡀⠀                   ⠀ ⢀⠀⢀⣴⠀⠀⠁⠀⠀⠀⢸⣦⡀⠀⠠⠀⠀
 *  ⢠⡀⠀⠀⣼⣿⣇⠀⠈⣴⠀⠀⣠⣿⡗⠀⣰⡇                    ⢸⣆⠀⢺⣿⣄⠀⠀⣦⠁⠀⣸⣿⣧⠀⠀⢀⡄
 *  ⢸⣷⡀⠀⢻⣿⣿⡄⢸⣿⡀⢰⣿⣿⠇⠀⣿⣷                    ⣾⣿⠀⠸⣿⣿⡆⢀⣿⡇⢠⣿⣿⡟⠀⢀⣾⡇
 *  ⣿⣿⣧⣠⣾⣿⣿⣧⣸⣿⣧⣼⣿⣿⣧⣰⣿⣿ CONVERT FUNCTIONS ⣿⣿⣆⣼⣿⣿⣧⣼⣿⣇⣼⣿⣿⣷⣄⣼⣿⣿ */

 // NOTES
 /*
 unsigned int = integer that can only be 0 or positiv

 uintptr_t = unsigned pointer type, its an unsigned interger that can hold a pointer's value;
 we dont use the unsigned int type because its too small to hold a pointer address.
 use to be able to do math and treat the address of the pointer as a number which will not be possible if we were just using a pointer address.
 reinterpret_cast is the only cast that can go between pointers and integers (or between unrelated pointer types). 
 what kind ofmath do 
 */