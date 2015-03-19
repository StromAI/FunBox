 
#define BOOST_PYTHON_SOURCE
#include <boost/python.hpp>
#include <vector>

using namespace boost::python;

class classtest
{
private:
	std::string a;
public:
	classtest(){}
	std::string fun()
	{
		a.push_back('1');
		a.push_back('2');
		return a;
	}
};



BOOST_PYTHON_MODULE(boostVec)
{
	class_<classtest>("classtest","doc string")
		.def("fun", &classtest::fun);
}

