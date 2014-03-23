#include <iostream>
#include <string>
#include "XList.h"

class MemoryWatcher
{
public:
	static int Links;
	static int Datas;
};

int MemoryWatcher::Datas = 0;
int MemoryWatcher::Links = 0;

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
	std::cout << listA.GetBackData() << std::endl;

	listA.PopBack();
	listA.PopBack();
	listA.PopBack();
	if (listA.IsEmpty())
		std::cout << "list A is empty" << std::endl;
	std::cout << "size of list A equals to " << listA.GetSize() << std::endl;

	XList <char> listB;
	XIterator <char>  it;
	listB.PushBack('a');
	listB.PushBack('b');
	listB.PushBack('c');
	it = listB.GetBackIterator();
	std::cout << *it << std::endl;
	--it;
	std::cout << *it << std::endl;
	--it;
	std::cout << *it << std::endl;
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

// it's the most awesome way to work with elements of XList
	XList< double > listE;
	listE.PushBack(1.0);
	listE.PushBack(2.71);
	listE.PushBack(3.14);
	XIterator< double > itE;
	itE = listE.GetFrontIterator();
	std::cout << *itE << std::endl;
	++itE;
	std::cout << *itE << std::endl;
	std::cout << *(++itE) << std::endl;
	*(--itE) = 4.44;
	std::cout << *itE << std::endl;
	listE.Erase();
	if (listE.IsEmpty())
		std::cout << "list E is empty" << std::endl;

	if( MemoryWatcher::Datas == 0 && MemoryWatcher::Links == 0 )
		std::cout << "seems like there are no leaks here" << std::endl;
	return 0;
}