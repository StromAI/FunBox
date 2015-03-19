#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v1;
	std::vector<int> v2;
	for (int i = 0; i < 10; ++i)
	{
		v1.push_back(i);
	}
	// std::vector<int>::iterator begin = v1.begin();
	// std::vector<int>::iterator end = v1.end();
	
	v2.assign(v1.begin(),v1.end());
	std::vector<int>::iterator it1 = v1.begin();
	std::vector<int>::iterator it2 = v2.begin();

	while (it1 != v1.end())
	{
		std::cout << *it1 << std::endl;
		++it1;
	}
	while (it2 != v2.end())
	{	
		std::cout << *it2 << std::endl;
		++it2;
	}
	return 0;
} 
