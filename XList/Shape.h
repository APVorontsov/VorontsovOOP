#include "XList.h"

class Shape : public Printable
{
private:
	static int sm_Count;

public:
	static int GetCount();
	virtual std::string Print();

	Shape( Shape const & newShape ); 
	Shape( std::string const & name );
	virtual ~Shape();
};

class Point : public Shape
{
public:
	Point( std::string const & name, double const & x, double const & y );
	Point( Point const & newPoint );
	virtual std::string Print();

private:
	long double m_x;
	long double m_y;
};

class Circle : public Shape
{
public:
	Circle( std::string const & name, double const & centerx, double const & centery, double const & radius );
	virtual std::string Print();

private:
	long double m_Centerx;
	long double m_Centery;
	long double m_Radius;
};

class Rect : public Shape
{
public:
	Rect( std::string const & name, double const & centerx, double const & centery, double const & length, double const & width );
	virtual std::string Print();

private:
	long double m_Centerx;
	long double m_Centery;
	long double m_Length;
	long double m_Width;
};

class Square : public Shape
{
public:
	Square( std::string const & name, double const & centerx, double const & centery, double const & length );
	virtual std::string Print();

private:
	long double m_Centerx;
	long double m_Centery;
	long double m_Length;
};

class Polyline : public Shape
{
public:
	Polyline( std::string const & name );
	~Polyline();

	void AddPoint( Point const & newPoint );
	virtual std::string Print();
	void Erase();
	
private:
	XList< Point > m_Points;
};