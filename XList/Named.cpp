#include <iostream>
#include <string>
#include "Named.h"

Named :: Named( std::string const & name )
	: m_Name( name )
{}

Printable :: Printable( std :: string const & name )
	: Named( name )
{}

int Shape :: GetCount()
{
	return sm_Count;
}

void Shape :: PrintName()
{
	std :: cout << "Type: unknown\n";
	std :: cout << "Name = " << m_Name << std :: endl;
}

Shape :: Shape( Shape const & newShape )
	: Printable( newShape.m_Name )
{
	++sm_Count;
}

Shape :: Shape( std :: string const & name )
	: Printable( name )
{
	++sm_Count;
}

Shape :: ~Shape()
{
	--sm_Count;
}

Point :: Point( std :: string const & name, double const & x, double const & y )
	: Shape( name )
	, m_x( x )
	, m_y( y )
{}

Point :: Point( Point const & newPoint )
	: Shape( newPoint.m_Name )
	, m_x( newPoint.m_x )
	, m_y( newPoint.m_y )
{}

void Point :: PrintName()
{
	std :: cout << "Type: point\n";
	std :: cout << "Name = " << m_Name << "\n";
	std :: cout << "x = " << m_x << " y = " << m_y << std :: endl; 
}

Circle :: Circle( std :: string const & name, double const & centerx, double const & centery, double const & radius )
	: Shape( name )
	, m_Centerx( centerx )
	, m_Centery( centery )
	, m_Radius( radius )
{}

void Circle :: PrintName()
{
	std :: cout << "Type: circle" << "\n";
	std :: cout << "Name = " << m_Name << "\n";
	std :: cout << "Center: x = " << m_Centerx << " y = " << m_Centery << "Radius = " << m_Radius << "\n"; 
	std :: cout << "Area = " << 3.14 * m_Radius * m_Radius << "\n" << std :: endl; 
}

Rect :: Rect( std :: string const & name, double const & centerx, double const & centery, double const & length, double const & width )
	: Shape( name )
	, m_Centerx( centerx )
	, m_Centery( centery )
	, m_Length( length )
	, m_Width( width )
{}

void Rect :: PrintName()
{
	std :: cout << "Type: rect" << "\n";
	std :: cout << "Name = " << m_Name << "\n";
	std :: cout << "Center: x = " << m_Centerx << " y = " << m_Centery << "\n";
	std :: cout << "Length = " << m_Length << "Width = " << m_Width << "\n";
	std :: cout << "Area = " << m_Length*m_Width << "\n" << std :: endl; 
}

Square :: Square( std :: string const & name, double const & centerx, double const & centery, double const & length )
	: Shape( name )
	, m_Centerx( centerx )
	, m_Centery( centery )
	, m_Length( length )
{}

void Square :: PrintName()
{
	std :: cout << "Type: square" << "\n";
	std :: cout << "Name = " << m_Name << "\n";
	std :: cout << "Center: x = " << m_Centerx << " y = " << m_Centery;
	std :: cout << "Length = " << m_Length  << "\n";
	std :: cout << "Area = " << m_Length*m_Length << "\n" << std :: endl; 
}

Polyline :: Polyline( std :: string const & name )
	: Shape( name )
{}

Polyline :: ~Polyline()
{
	Erase();
}

void Polyline :: AddPoint( Point const & newPoint )
{
	m_Points.PushBack(newPoint);
}

void Polyline :: PrintName()
{
	std :: cout << "Type: polyline" << "\n";
	std :: cout << "Name = " << m_Name << "\n";
	std :: cout << "Contains " << m_Points.GetSize() << " points:\n";
	XIterator< Point > it;
	for ( it = m_Points.GetFrontIterator(); it.isnotNull(); ++it)
	{
		(*it).PrintName();
	}
}

void Polyline :: Erase()
{
	m_Points.Erase();
}