#include <iostream>
#include <string>

int main()
{
	std::string a("a");
	std::string b = "b";
	std::string sum;
	sum = a + b;
	sum = sum + a;
	std::cout << sum << std::endl;
	return 0;
} 
