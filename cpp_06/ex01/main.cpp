#include "Serializer.hpp"

int main()
{
    Data data;
    data.age = 32;
    data.name = "kalaya"; 

    Data* ptr = &data;

    uintptr_t raw = Serializer::serialize(ptr);

    Data* recovered = Serializer::deserialize(raw);

    std::cout << "Address ptr " << ptr << std::endl;
    std::cout << "Address recoverd " << recovered << std::endl;
    std::cout << "Address raw " << raw << std::endl;

    std::cout << "recoverd age: " << recovered->age << std::endl;
    std::cout << "recovered name: " << recovered->name << std::endl;
  
    return 0;
}