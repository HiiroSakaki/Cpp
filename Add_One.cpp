#include <iostream>

void AddOne(int aValue)
{
    ++aValue;
}

int main()
{
    int myValue = 0;

    AddOne(myValue);

    std::cout << myValue << std::endl;

    std::cin.get();
}