#include <iostream>
#include "XList.h"

//XList

template <class T>
XList<T> :: XList()
{
	m_Front = m_Back = NULL;
	m_Size = 0;
}

template <class T>
XList<T> :: ~XList()
{
	this->Erase();
}

template <class T>
void XList<T> :: PushBack( T const & NewElement )
{
	XLink<T> * newLink = new XLink<T>( NewElement, m_Back, NULL );
	++MemoryWatcher :: Links;

	if ( m_Size == 0 )
		m_Front = m_Back = newLink;
	else
	{
		m_Back -> SetNext( newLink );
		m_Back = newLink;
	}
	++m_Size;
}

template <class T>
void XList<T> :: PushFront( T const & NewElement )
{
	XLink<T> * newLink = new XLink<T>( NewElement, NULL, m_Front );
	++MemoryWatcher :: Links;

	if( m_Size == 0 )
	{
		m_Front = m_Back = newLink;
	}
	else
	{
		m_Front -> SetPrev( newLink );
		m_Front = newLink;
	}
	++m_Size;
}

template <class T>
void XList<T> :: PopBack()
{
	switch ( m_Size )
	{
		case 0:
			return;
		case 1:
			delete m_Back;
			m_Back = m_Front = NULL;
			--MemoryWatcher :: Links;
			--m_Size;
			return;
		default:
			auto temp = m_Back -> GetPrevPointer();
			delete m_Back;
			m_Back = temp;
			--MemoryWatcher :: Links;
			--m_Size;
			return;
	}
}

template<class T>
void XList<T> :: PopFront()
{
	switch ( m_Size )
	{
	case 0:
		return;
	case 1:
		delete m_Front;
		m_Front = m_Back = NULL;
		--MemoryWatcher :: Links;
		--m_Size;
		return;
	default:
		auto temp = m_Front -> GetNextPointer();
		delete m_Front;
		m_Front = temp;
		--MemoryWatcher :: Links;
		--m_Size;
		return;
	}
}

template <class T>
T & XList<T> :: GetBackData()
{
	return m_Back->GetData();
}

template <class T>
T & XList<T> :: GetFrontData()
{
	return m_Front->GetData();
}

template <class T>
XLink<T> * XList<T> :: GetBackLink()
{
	return m_Back;
}

template <class T>
XLink<T> * XList<T> :: GetFrontLink()
{
	return m_Front;
}

template <class T>
int XList<T> :: GetSize()
{
	return m_Size;
}

template <class T>
bool XList<T> :: IsEmpty()
{
	return ( ( m_Size == 0 ) ? true : false );
}

template <class T>
void XList<T> :: Erase()
{
	while( m_Size > 0 )
		this->PopBack();
}

// XLink

template <class T>
void XLink<T> :: SetNext( XLink<T> * const next )
{
	m_Next = next;
}

template <class T>
void XLink<T> :: SetPrev( XLink<T> * const prev )
{
	m_Prev = prev;
}

template <class T>
XLink<T> :: XLink( T const & NewElement, XLink<T> * prev, XLink<T> * next )
{
	m_Data = new T;
	++MemoryWatcher :: Datas;
	*m_Data = NewElement;
	m_Prev = prev;
	m_Next = next;
}

template <class T>
XLink<T> :: ~XLink()
{
	delete m_Data;
	--MemoryWatcher :: Datas;
}

template <class T>
T & XLink<T> :: GetData()
{
	return *( this -> m_Data );
}

template <class T>
XLink<T> * XLink<T> :: GetNextPointer()
{
	return m_Next;
}

template <class T>
XLink<T> * XLink<T> :: GetPrevPointer()
{
	return m_Prev;
}
