#include "XNode.h"
#include "XIterator.h"

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
	XIterator<T> GetFrontIterator();
	XIterator<T> GetBackIterator();

	int GetSize();
	bool IsEmpty();
	void Erase();

	XList();
	~XList();
	  
private:
	XNode<T> * m_Front;
	XNode<T> * m_Back;

	int m_Size;
};

template <class T>
XList<T>::XList()
{
	m_Front = m_Back = NULL;
	m_Size = 0;
}

template <class T>
XList<T>::~XList()
{
	this->Erase();
}

template <class T>
void XList<T>::PushBack( T const & NewElement )
{
	XNode<T> * newLink = new XNode<T>( NewElement, m_Back, NULL );

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
void XList<T>::PushFront( T const & NewElement )
{
	XNode<T> * newLink = new XNode<T>( NewElement, NULL, m_Front );

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
void XList<T>::PopBack()
{
	switch ( m_Size )
	{
		case 0:
			return;
		case 1:
			delete m_Back;
			m_Back = m_Front = NULL;
			--m_Size;
			return;
		default:
			XNode<T> * temp = m_Back -> GetPrevPointer();
			delete m_Back;
			m_Back = temp;
			temp -> SetNext(NULL);
			--m_Size;
			return;
	}
}

template<class T>
void XList<T>::PopFront()
{
	switch ( m_Size )
	{
	case 0:
		return;
	case 1:
		delete m_Front;
		m_Front = m_Back = NULL;
		--m_Size;
		return;
	default:
		XNode<T> * temp = m_Front -> GetNextPointer();
		delete m_Front;
		m_Front = temp;
		temp -> SetPrev(NULL);
		--m_Size;
		return;
	}
}

template <class T>
T & XList<T>::GetBackData()
{
	return m_Back->GetData();
}

template <class T>
T & XList<T>::GetFrontData()
{
	return m_Front->GetData();
}

template <class T>
XIterator<T> XList<T>::GetBackIterator()
{
	XIterator<T> it( m_Back );
	return it;
}

template <class T>
XIterator<T> XList<T>::GetFrontIterator()
{
	XIterator<T> it( m_Front );
	return it;
}

template <class T>
int XList<T>::GetSize()
{
	return m_Size;
}

template <class T>
bool XList<T>::IsEmpty()
{
	return ( ( m_Size == 0 ) ? true : false );
}

template <class T>
void XList<T>::Erase()
{
	while( m_Size > 0 )
		this->PopBack();
}
