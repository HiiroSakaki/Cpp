#include <iostream>

int main()
{
	int* somePtr;
	int someValue = 42;
	somePtr = &someValue;
	std::cout << somePtr << std::endl;
	std::cout << *somePtr << std::endl;
}