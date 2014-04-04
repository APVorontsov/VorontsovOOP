// XLink

template <class T>
void XLink<T> :: SetNext( XLink<T> * const & next )
{
	m_Next = next;
}

template <class T>
void XLink<T> :: SetPrev( XLink<T> * const & prev )
{
	m_Prev = prev;
}

template <class T>
XLink<T> :: XLink( T const & NewElement, XLink<T> * const & prev, XLink<T> * const & next )
{
	m_Data = new T( NewElement );
	m_Prev = prev;
	m_Next = next;
}

template <class T>
XLink<T> :: XLink( T * NewElement, XLink<T> * const & prev, XLink<T> * const & next )
{
	m_Data = NewElement;
	m_Prev = prev;
	m_Next = next;
}

template <class T>
XLink<T> :: ~XLink()
{
	delete m_Data;
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

// XIterator
template <class T>
XIterator<T> & XIterator<T> :: operator++ ()
{
	m_Iterator = m_Iterator -> GetNextPointer();
	return *this;
}

template <class T>
XIterator<T> & XIterator<T> :: operator-- ()
{
	m_Iterator = m_Iterator -> GetPrevPointer();
	return *this;
}

template <class T>
XIterator<T> & XIterator<T> :: operator= (XLink<T> * const & newXLink)
{
	m_Iterator = newXLink;
	return *this;
}

template <class T>
T & XIterator<T> :: operator*()
{
	return m_Iterator -> GetData();
}

template <class T>
bool XIterator<T> :: isnotNull()
{
	return ( m_Iterator != NULL ? true : false );
}

template <class T>
XIterator<T> :: XIterator()
{
	m_Iterator = NULL;
}

template <class T>
XIterator<T> :: XIterator( XLink<T> * const & newXLink )
{
	m_Iterator = newXLink;
}