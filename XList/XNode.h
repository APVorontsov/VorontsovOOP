template <class T>
class XNode
{
public:
	void SetNext( XNode<T> * const next );
	void SetPrev( XNode<T> * const prev );

	T & GetData();
	XNode<T> * GetNextPointer();
	XNode<T> * GetPrevPointer();

	XNode( T const & NewElement, XNode<T> * const prev, XNode<T> * const next );
	XNode( T * NewElement, XNode<T> * const prev, XNode<T> * const next );
	~XNode();

private:
	XNode<T> * m_Next;
	XNode<T> * m_Prev;
	T * m_Data;
};

template <class T>
void XNode<T>::SetNext( XNode<T> * const next )
{
	m_Next = next;
}

template <class T>
void XNode<T>::SetPrev( XNode<T> * const prev )
{
	m_Prev = prev;
}

template <class T>
XNode<T>::XNode( T const & NewElement, XNode<T> * const prev, XNode<T> * const next )
{
	m_Data = new T( NewElement );
	m_Prev = prev;
	m_Next = next;
}

template <class T>
XNode<T>::XNode( T * NewElement, XNode<T> * const prev, XNode<T> * const next )
{
	m_Data = NewElement;
	m_Prev = prev;
	m_Next = next;
}

template <class T>
XNode<T>::~XNode()
{
	delete m_Data;
}

template <class T>
T & XNode<T>::GetData()
{
	return *( this -> m_Data );
}

template <class T>
XNode<T> * XNode<T>::GetNextPointer()
{
	return m_Next;
}

template <class T>
XNode<T> * XNode<T>::GetPrevPointer()
{
	return m_Prev;
}