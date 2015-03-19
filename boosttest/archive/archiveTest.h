#ifndef _ARCHIVETEST_
#define _ARCHIVETEST_

//#include <boost/serialization/string.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

class Vec2
{
private:
	int x;
	int y;
	friend class boost::serialization::access;

	template<class Archive>
	void serialization(Archive & ar, const unsigned int version)
	{
		ar & x;
		ar & y;
	}
public:
	Vec2();
	Vec2(int x,int y);
	Vec2(const Vec2&);
	~Vec2();

	int GetX();
	int GetY();

	Vec2& operator=(const Vec2 &rhs)
	{
		x = rhs.x;
		y = rhs.y;
		return *this;
	}

	Vec2& operator+=(const Vec2 &rhs)
	{
		x += rhs.x;
		y += rhs.y;
		return *this;
	}

	Vec2 operator+(const Vec2 &rhs)
	{
		Vec2 pos(*this);
		pos += rhs;
		return pos;
	}

	Vec2& operator-=(const Vec2 &rhs)
	{
		x -= rhs.x;
		y -= rhs.y;
		return *this;
	}

	Vec2 operator-(const Vec2 &rhs)
	{
		Vec2 pos(*this);
		pos -= rhs;
		return pos;
	}	

	Vec2& operator*=(const int &rhs)
	{
		x *= rhs;
		y *= rhs;
		return *this;
	}

	Vec2 operator*(const int &rhs)
	{
		Vec2 pos(*this);
		pos *= rhs;
		return pos;
	}

	friend Vec2 operator*(const int &lhs,const Vec2 &rhs)
	{
		Vec2 pos(rhs);
		pos *= lhs;
		return pos;
	}

	Vec2& operator/=(const int &rhs)
	{
		x /= rhs;
		y /= rhs;
		return *this;
	}

	Vec2 operator/(const int &rhs)
	{
		Vec2 pos(*this);
		pos /= rhs;
		return pos;
	}
};

// struct data
// {

// };

#endif