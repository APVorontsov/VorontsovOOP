
template <class T>
class XIterator
{
public:
	XIterator<T> & operator++ ();
	XIterator<T> & operator-- ();
	XIterator<T> & operator= (XNode<T> * const newXNode); 
	T & operator* ();
	bool isnotNull();

	XIterator<T>();
	XIterator<T>( XNode<T> * const newXNode );

private:
	XNode<T> *  m_Iterator;
};

template <class T>
XIterator<T> & XIterator<T>::operator++ ()
{
	m_Iterator = m_Iterator -> GetNextPointer();
	return *this;
}

template <class T>
XIterator<T> & XIterator<T>::operator-- ()
{
	m_Iterator = m_Iterator -> GetPrevPointer();
	return *this;
}

template <class T>
XIterator<T> & XIterator<T>::operator= (XNode<T> * const newXNode)
{
	m_Iterator = newXNode;
	return *this;
}

template <class T>
T & XIterator<T>::operator*()
{
	return m_Iterator -> GetData();
}

template <class T>
bool XIterator<T>::isnotNull()
{
	return ( m_Iterator != NULL ? true : false );
}

template <class T>
XIterator<T>::XIterator()
{
	m_Iterator = NULL;
}

template <class T>
XIterator<T>::XIterator( XNode<T> * const newXNode )
{
	m_Iterator = newXNode;
}
