#include "XList.h"

class Named
{
public:
	Named( std :: string const & name );

protected:
	std :: string m_Name;
};

class Printable : public Named
{
public:
	virtual void PrintName() = 0;
	Printable( std :: string const & name );
};

class Shape : public Printable
{
private:
	static int sm_Count;

public:
	static int GetCount();
	virtual void PrintName();

	Shape( Shape const & newShape ); 
	Shape( std :: string const & name );
	virtual ~Shape();
};

class Point : public Shape
{
public:
	Point( std :: string const & name, double const & x, double const & y );
	Point( Point const & newPoint );
	void PrintName();

private:
	double m_x;
	double m_y;
};

class Circle : public Shape
{
public:
	Circle( std :: string const & name, double const & centerx, double const & centery, double const & radius );
	void PrintName();

private:
	double m_Centerx;
	double m_Centery;
	double m_Radius;
};

class Rect : public Shape
{
public:
	Rect( std :: string const & name, double const & centerx, double const & centery, double const & length, double const & width );
	void PrintName();

private:
	double m_Centerx;
	double m_Centery;
	double m_Length;
	double m_Width;
};

class Square : public Shape
{
public:
	Square( std :: string const & name, double const & centerx, double const & centery, double const & length );
	void PrintName();

private:
	double m_Centerx;
	double m_Centery;
	double m_Length;
};

class Polyline : public Shape
{
public:
	Polyline( std :: string const & name );
	~Polyline();

	void AddPoint( Point const & newPoint );
	void PrintName();
	void Erase();
	
private:
	XList< Point > m_Points;
};