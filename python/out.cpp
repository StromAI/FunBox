 
#define BOOST_PYTHON_SOURCE
#include <boost/python.hpp>
#include "boostpy.h"

using namespace boost::python;

int test2(int i)
{
    test a;
    a.test1(i);
    return ++i;
}

BOOST_PYTHON_MODULE(boostpy)
{
	def("test",test2,"pytest");
}

