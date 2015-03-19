#include <iostream>
#include <string>
#include <boost/xpressive/xpressive_dynamic.hpp>

int main()
{
	using namespace boost::xpressive;
	std::string str = ")";
	//std::string *str = &strt;
	sregex split_reg = sregex::compile("\\)");

	sregex_token_iterator pos(str.begin(), str.end(), split_reg, -1);

	while(pos != sregex_token_iterator())
	{
		std::string p(static_cast<std::string>(*pos));
		std::cout << "[" << p << "]";
		++pos;
	}
	std::cout << std::endl;
	return 0;
}