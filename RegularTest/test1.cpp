#include <regex>
#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
	string pattern("^[c]ei");
	pattern = "[[:digit:]]";// + pattern +"[[:digit:]]*";

	regex r(pattern, regex_constants::extended);
	
	smatch results;

	string teststr = "a";

	if (regex_search(teststr, results, r))
		cout << results.str() << endl;
	return 0;
}