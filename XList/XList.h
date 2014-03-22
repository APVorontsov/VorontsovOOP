template <class T>
class XLink
{
public:
	void SetNext( XLink<T> * const next );
	void SetPrev( XLink<T> * const prev );

	T & GetData();
	XLink<T> * GetNextPointer();
	XLink<T> * GetPrevPointer();

	XLink( T const & NewElement, XLink<T> * prev, XLink<T> * next );
	~XLink();

private:
	XLink<T> * m_Next;
	XLink<T> * m_Prev;
	T * m_Data;
};

template <class T>
class XList
{
public:
	void PushFront( T const & NewElement );
	void PushBack( T const & NewElement );	
	void PopFront();
	void PopBack();

	T & GetFrontData();
	T & GetBackData();
	XLink<T> * GetFrontLink();
	XLink<T> * GetBackLink();

	int GetSize();
	bool IsEmpty();
	void Erase();

	XList();
	~XList();
	  
private:
	XLink<T> * m_Front;
	XLink<T> * m_Back;

	int m_Size;

};

template <class T>
class XIterator
{
public:
	XIterator<T> & operator++ ();
	XIterator<T> & operator-- ();
	XIterator<T> & operator= (XLink<T> * newXLink); 
	T & operator* ();

	XIterator<T>();
	XIterator<T>( XLink<T> * newXLink );

private:
	XLink<T> *  m_Iterator;
};

#include "XList.cpp"
#include "XLink.cpp"