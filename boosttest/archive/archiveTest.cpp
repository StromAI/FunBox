#include <sstream>
//#include <boost/serialization/string.hpp>
//#include <boost/iostream/stream.hpp>
#include "archiveTest.h"


Vec2::Vec2()
	: x(0)
	, y(0)
{
}

Vec2::Vec2(int _x,int _y)
	: x(_x)
	, y(_y)
{	
}

Vec2::Vec2(const Vec2 &pos)
{
	x = pos.x;
	y = pos.y;
}

Vec2::~Vec2()
{
}

int Vec2::GetX()
{
	return x;
}

int Vec2::GetY()
{
	return y;
}

int
main()
{
	Vec2 pos(1,2);
	std::ostringstream os;
	boost::archive::binary_oarchive oa(os);
	oa << pos;

	std::string content = os.str();

	Vec2 pos2;
	std::istringstream is(content);
	boost::archive::binary_iarchive ia(is);


	pos >> pos2;

	std::cout << "Pos:" << pos2.GetX() << "," << pos2.GetY() << endl;
	boost::archive::
	return 0;
} 
