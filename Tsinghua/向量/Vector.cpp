typedef int Rank;
# define DEFAULT_CAPCITY 3

template<typename T> class Vector
{
	protected:
		Rank _size;int _capacity;T *_elem;
		void copyFrom(T const *A,Rank lo,Rank hi);
		void expand();
		void shrink();
		bool bubble(Rank lo,Rank hi);
		void bubbleSort(Rank lo,Rank hi);
		Rank max(Rank lo,Rank hi);
		void selectionSort(Rank lo,Rank hi);
		void merge(Rank lo,Rank hi);
		void mergeSort(Rank lo,Rank hi);
		Rand partition(Rank lo,Rank hi);
		void quickSort(Rank lo,Rank hi);
		void heapSort(Rank lo,Rank hi);
	public:
		Vector(int c= DEFAULT_CAPCITY,int s=0,T v=0)
		{
			_elem = new T[_capacity=c];
			for(_size=0;_size<s;_elem[_size++]=0);
		}
		Vector(T const*A,Rank lo,Rank hi)
		{
			copyFrom(A,lo,hi);
		}
		Vector(T const*A,Rank n)
		{
			copyFrom(A,0,n);
		}
		Vector(Vector<T> const &V,Rank lo,Rank hi)
		{
			copyFrom(V._elem,lo,hi);
		}
		Vector(Vector<T> const &V)
		{
			copyFrom(V._elem,0,V._size);
		}
		~Vector()
		{
			delete []_elem;
		}	
		T &operator[](Rank r) const;
		void unsort(Rank lo,Rank hi);
}
template <typename T> void Vector<T>::copyFrom(T const&A,Rank lo,Rank hi)
{
	_elem = new T[_capacity=2*(hi-lo)];_size=0;
	while(lo<hi)
	{
		_elem[size++] = A[lo++];
	}
}
template <typename T> void Vector<T>::expand()
{
	if(_size<_capacity) return;
	if(_capacity<DEFAULT_CAPACITY) _capacity=DEFAULT_CAPACITY;
	T* oldElem = _elem;
	_elem = new T[_capacity<<=1];
	for(int i=0;i<_size;i++)
	{
		_elem[i] = oldElem[i];
	}
	delete []oldElem;
}
template <typename T> void Vector<T>::shrink()
{
	if(_capacity<DEFAULT_CAPACITY<<1) return;
	if(_size<<2>_capacity) return;
	T *oldElem = _elem;
	_elem = new T[_capacity>>=1];
	for(int i=0;i<_size;i++) _elem[i]=oldElem[i];
	delete []oldElem;
}
template <typename T> T&Vector<T>::operator[](Rank r) const
{
	return _elem[r];
}
template<typename T> void Vector<T>::unsort(Rank lo,Rank hi)
{
	T *V = _elem+lo;
	for(Rank i=hi-lo;i>0;i--)
	{
		swap(V[i-1],V[rand()%i]);
	}
}

