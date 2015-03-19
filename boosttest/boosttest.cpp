#include <boost/timer.hpp>
#include <iostream>

using namespace std;
using namespace boost;

int main(int argc, char const *argv[])
 {
 	timer t;

 	cout << t.elapsed_max()/3600 << endl;
 	return 0;
 } 
