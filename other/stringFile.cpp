#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	ifstream input("stringFile");
	string s;
	while(getline(input,s))
	{
		cout << s <<endl;
	}
	return 0;
}