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
/*	std::cout << "size equals to " << listA.GetSize() << std::endl;
	std::cout << listA.GetBackData() << std::endl;
	listA.PopBack();
	std::cout << listA.GetBackData() << std::endl;
	listA.PopBack();
	std::cout << listA.GetBackData() << std::endl;

	listA.PopBack();
	listA.PopBack();
	listA.PopBack();
	if (listA.IsEmpty())
		std::cout << "list is empty" << std::endl;

	XList <char> listB;
	XLink <char> * it;
	listB.PushBack('a');
	listB.PushBack('b');
	listB.PushBack('c');
	it = listB.GetBackLink();
	std::cout << it->GetData() << std::endl;
	it = it->GetPrevPointer();
	std::cout << it->GetData() << std::endl;
	it = it->GetPrevPointer();
	std::cout << it->GetData() << std::endl;
	listB.Erase();
	if (listB.IsEmpty())
		std::cout << "list is empty" << std::endl;

	XList <std::string> listC;
	listC.PushBack("abc");
	std::cout << listC.GetBackData() << std::endl;
	listC.GetBackLink()->GetData() = "ololo";
	std::cout << listC.GetBackData() << std::endl;
	listC.GetBackData() = "peka";
	std::cout << listC.GetBackData() << std::endl;
	listC.Erase();
	if (listC.IsEmpty())
		std::cout << "list is empty" << std::endl;

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
	it = listD.GetFrontLink();
	std::cout << it->GetData() << std::endl;
	it = it->GetNextPointer();
	std::cout << it->GetData() << std::endl;
	listD.PopFront();
	listD.PopFront();
	*/
	if(MemoryWatcher::Datas == 0 && MemoryWatcher::Links == 0)
		std::cout << "seems like there are no leaks here" << std::endl;
	return 0;
}