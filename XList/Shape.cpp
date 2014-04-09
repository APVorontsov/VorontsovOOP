#include <iostream>
#include <string>
#include "Named.h"
#include "Shape.h"

int Shape::GetCount()
{
	return sm_Count;
}

std::string Shape::Print()
{
	std::string info;
	info = "Type: unknown\n";
	info += "Name = " + m_Name + "\n";
	return info;
}

Shape::Shape( Shape const & newShape )
	: Printable( newShape.m_Name )
{
	++sm_Count;
}

Shape::Shape( std::string const & name )
	: Printable( name )
{
	++sm_Count;
}

Shape::~Shape()
{
	--sm_Count;
}

Point::Point( std::string const & name, double const & x, double const & y )
	: Shape( name )
	, m_x( x )
	, m_y( y )
{}

Point::Point( Point const & newPoint )
	: Shape( newPoint.m_Name )
	, m_x( newPoint.m_x )
	, m_y( newPoint.m_y )
{}

std::string Point::Print()
{
	std::string info;
	info = "Type: point\n";
	info += "Name = " + m_Name + "\n";
	info += "x = " + std::to_string( m_x ) + " y = " + std::to_string( m_y ) + "\n";
	return info;
}

Circle::Circle( std::string const & name, double const & centerx, double const & centery, double const & radius )
	: Shape( name )
	, m_Centerx( centerx )
	, m_Centery( centery )
	, m_Radius( radius )
{}

std::string Circle::Print()
{
	std::string info;
	info = "Type: circle\n";
	info += "Name = " + m_Name + "\n";
	info += "Center: x = " + std::to_string( m_Centerx ) + " y = " + std::to_string( m_Centery ) 
		+ "Radius = " + std::to_string( m_Radius ) + "\n"; 
	info += "Area = " + std::to_string( 3.14 * m_Radius * m_Radius ) + "\n";
	return info;
}

Rect::Rect( std::string const & name, double const & centerx, double const & centery, double const & length, double const & width )
	: Shape( name )
	, m_Centerx( centerx )
	, m_Centery( centery )
	, m_Length( length )
	, m_Width( width )
{}

std::string Rect::Print()
{
	std::string info;
	info = "Type: rect\n";
	info += "Name = " + m_Name + "\n";
	info += "Center: x = " + std::to_string( m_Centerx ) + " y = " + std::to_string( m_Centery ) + "\n";
	info += "Length = " + std::to_string( m_Length ) + " Width = " + std::to_string( m_Width ) + "\n";
	info += "Area = " + std::to_string( m_Length * m_Width ) + "\n";
	return info;
}

Square::Square( std::string const & name, double const & centerx, double const & centery, double const & length )
	: Shape( name )
	, m_Centerx( centerx )
	, m_Centery( centery )
	, m_Length( length )
{}

std::string Square::Print()
{
	std::string info;
	info = "Type: square\n";
	info += "Name = " + m_Name + "\n";
	info += "Center: x = " + std::to_string( m_Centerx ) + " y = " + std::to_string( m_Centery );
	info += "Length = " + std::to_string( m_Length ) + "\n";
	info += "Area = " + std::to_string( m_Length * m_Length ) + "\n";
	return info;
}

Polyline::Polyline( std::string const & name )
	: Shape( name )
{}

Polyline::~Polyline()
{
	Erase();
}

void Polyline::AddPoint( Point const & newPoint )
{
	m_Points.PushBack(newPoint);
}

std::string Polyline::Print()
{
	std::string info;
	info = "Type: polyline\n";
	info += "Name = " +  m_Name + "\n";
	info += "Contains " + std::to_string( (long long) m_Points.GetSize() ) + " points:\n";
	XIterator< Point > it;
	for ( it = m_Points.GetFrontIterator(); it.isnotNull(); ++it)
	{
		info += (*it).Print();
	}
	return info;
}

void Polyline::Erase()
{
	m_Points.Erase();
}