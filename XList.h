template <class T>
class XLink
{
public:
	XLink( T const & NewElement, XLink<T> * prev, XLink<T> * next );
	~XLink();

	void SetNext( XLink<T> * const next );
	void SetPrev( XLink<T> * const prev );

	T & GetData();
	XLink<T> * GetNextPointer();
	XLink<T> * GetPrevPointer();

private:
	XLink<T> * m_Next;
	XLink<T> * m_Prev;
	T * m_Data;
};

template <class T>
class XList
{
public:
	XList();
	~XList();
	  
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

private:
	XLink<T> * m_Front;
	XLink<T> * m_Back;

	int m_Size;

};

