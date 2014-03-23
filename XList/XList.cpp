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
XIterator<T> XList<T> :: GetBackIterator()
{
	XIterator<T> it( m_Back );
	return it;
}

template <class T>
XIterator<T> XList<T> :: GetFrontIterator()
{
	XIterator<T> it( m_Front );
	return it;
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