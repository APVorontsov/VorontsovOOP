#include <iostream>
#include <string>
#include "Named.h"
#include "Shape.h"

int Shape::sm_Count = 0;

int main()
{
	XList <int> listA;
	listA.PushBack( 1 );
	listA.PushBack( 2 );
	listA.PushBack( 3 );
	std::cout << "size of list A equals to " << listA.GetSize() << std::endl;
	std::cout << listA.GetBackData() << std::endl;
	listA.PopBack();
	std::cout << listA.GetBackData() << std::endl;
	listA.PopBack();
	std::cout << (listA.GetBackData() = 5) << std::endl;

	listA.PopBack();
	listA.PopBack();
	listA.PopBack();
	if (listA.IsEmpty())
		std::cout << "list A is empty" << std::endl;
	std::cout << "size of list A equals to " << listA.GetSize() << std::endl;

	XList <char> listB;
	XIterator <char> it;
	listB.PushBack('a');
	listB.PushBack('b');
	listB.PushBack('c');
	it = listB.GetBackIterator();
	std::cout << *(++--it) << std::endl;
	--it;
	std::cout << *it << std::endl;
	--it;
	std::cout << *(--++it) << std::endl;
	listB.Erase();
	if (listB.IsEmpty())
		std::cout << "list B is empty" << std::endl;

	XList <std::string> listC;
	listC.PushBack("lol");
	std::cout << *listC.GetBackIterator() << std::endl;
	*listC.GetBackIterator() = "ololo";
	std::cout << *listC.GetBackIterator() << std::endl;
	listC.GetBackData() = "trololo";
	std::cout << *listC.GetBackIterator() << std::endl;
	listC.Erase();
	if (listC.IsEmpty())
		std::cout << "list C is empty" << std::endl;

	XList <char> listD;
	listD.PushFront('a');
	std::cout << listD.GetFrontData() << std::endl;
	listD.PushFront('b');
	std::cout << listD.GetFrontData() << std::endl;
	listD.PopFront();
	listD.PushFront('c');
	std::cout << listD.GetFrontData() << std::endl;
	listD.GetFrontData() = 'd';
	std::cout << listD.GetFrontData() << std::endl;
	it = listD.GetFrontIterator();
	std::cout << *it << std::endl;
	++it;
	std::cout << *it << std::endl;
	listD.PopFront();
	listD.PopFront();
	if (listD.IsEmpty())
		std::cout << "list D is empty" << std::endl;
	 
	XList< double > listE;
	listE.PushBack(1.0);
	listE.PushBack(2.71);
	listE.PushBack(3.14);
	listE.PopBack();
	listE.PopBack();
	listE.PushBack(5.78);
	listE.PopFront();
	listE.PushFront(6.44);
	listE.PopFront();
	listE.PopFront();
	listE.PushFront(7.46);
	listE.PopBack();
	listE.PushFront(8.99);
	listE.PopBack();
	if (listE.IsEmpty())
		std::cout << "list E is empty" << std::endl;

	XList< Shape > listF;
	{
		Polyline plA( "Polyline A" );
		Point p1( "Point #1", 1.0, 0.0 );
		Point p2( "Point #2", 0.0, 2.0 );
		Point p3( "Point #3", 1.5, 1.5 );
		plA.AddPoint( p1 );
		plA.AddPoint( p2 );
		plA.AddPoint( p3 );
		std::cout << plA.Print() << std::endl;
		Circle c1( "Circel #1", 1.5, -0.5, 3.14 );
		Rect r1( "Rect #1", -58, 96.37589964, 35, 0.2 );
		Square s1( "Square #1", 0, 0, 1.414 );

		listF.PushBack( p1 );
		listF.PushBack( plA );
		listF.PushBack( c1 );
		listF.PushBack( r1 );
		listF.PushBack( p2 );
		listF.PushBack( s1 );
		listF.PushBack( p3 );
		listF.PushBack( s1 );

		std::cout << "\nListF contains " << listF.GetSize() << " elements" << std::endl;
		for( auto it = listF.GetFrontIterator(); it.isnotNull(); ++it )
			std::cout << (*it).Print();
		std::cout << "There are created " << Shape::GetCount() << " shapes" << std::endl; 
		listF.Erase();
	}

	if ( Shape::GetCount() == 0 )
		std::cout << "EVERYHING IS ALRIGHT\n" << std::endl;
	else
		std::cout << "WE'VE GOT " << Shape::GetCount() << " PROBLEMS\n" << std::endl;

	{
		XList< Shape * > listG;

		Point * p1 = new Point( "Point #1", 1.0, 0.0 );
		Point * p2 = new Point( "Point #2", 0.0, 2.0 );
		Point * p3 = new Point( "Point #3", 1.5, 1.5 );
		Polyline * plA = new Polyline( "Polyline A" );
		plA->AddPoint( *p1 );
		plA->AddPoint( *p2 );
		plA->AddPoint( *p3 );
		std::cout << plA->Print() << std::endl;
		Circle * c1 = new Circle( "Circel #1", 1.5, -0.5, 3.14 );
		Rect * r1 = new Rect( "Rect #1", -58, 96.37589964, 35, 0.2 );
		Square * s1 = new Square( "Square #1", 0, 0, 1.414 );
	
		listG.PushBack( c1 );
		listG.PushBack( plA );
		listG.PushBack( r1 );
		listG.PushBack( s1 );
		listG.PushBack( p1 );
		listG.PushBack( p2 );
		listG.PushBack( p3 );

		std::cout << "\nListG contains " << listG.GetSize() << " elements" << std::endl;
		for( auto it = listG.GetFrontIterator(); it.isnotNull(); ++it )
			std::cout << (*it) -> Print();
		std::cout << "There are created " << Shape::GetCount() << " shapes" << std::endl; 

		delete p1;
		delete p2;
		delete p3;
		delete plA;
		delete c1;
		delete r1;
		delete s1;
	}
	if ( Shape::GetCount() == 0 )
		std::cout << "EVERYHING IS ALRIGHT\n" << std::endl;
	else
		std::cout << "WE'VE GOT " << Shape::GetCount() << " PROBLEMS\n" << std::endl;

	return 0;
}