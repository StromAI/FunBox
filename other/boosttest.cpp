#include <boost/timer.hpp>
#include <iostream>

using namespace boost;

int main()
{
	timer t;
	std::cout << "max timespan:" << t.elapsed_max() / 3600 << "h" << std::endl;
	return 0;
}