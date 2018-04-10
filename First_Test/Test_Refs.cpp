#include <iostream>


int main()
{
	int someValue = 42;
	int& someRef = someValue;
	std::cout << someRef << std::endl;
	std::cout << &someRef << std::endl;

}