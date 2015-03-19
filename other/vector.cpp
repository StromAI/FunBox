#include <iostream>
#include <list>

using namespace std;

int main()
{
	int a;
	list<int> v;
	int i = 10;
	while(i--)
	{
		cin >> a;
		v.push_front(a);
	}
	list<int>::iterator it;
	for(it = v.begin();it != v.end(); it++)
		cout << (int)*it << endl;
	return 0;
}