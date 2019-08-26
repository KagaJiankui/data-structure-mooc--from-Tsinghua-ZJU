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
		void merge(Rank lo,Rank mi,Rank hi);
		void mergeSort(Rank lo,Rank hi);
		Rand partition(Rank lo,Rank hi);
		void quickSort(Rank lo,Rank hi);
		void heapSort(Rank lo,Rank hi);
		static Rank binSearch(T *_elem,T const&e,Rank lo,Rank hi);
		static Rank fibSearch(T *_elem,T const&e,Rank lo,Rank hi);
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
		Rank find(T const&e,Rank lo,Rank hi);
		Rank insert(Rank r,T const &e);
		int remove(Rank lo,Rank hi);
		int remove(Rank r);
		int deduplicate();
		void traverse(void(*)(T&));
		template<typename VST> void traverse(VST &);
		int disordered()const;
		int uniquify(); 
		Rank search(T const &e,Rank lo,Rank hi);
		//static bool lt(T *a,T *b);
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
template<typename T> Rank Vector<T>::find(T const&e,Rank lo,Rank hi)
{
	while(lo<hi--&&e!=_elem[hi]);
	return hi;
}
template<typename T> Rank Vector<T>::insert(Rank r,T const &e)
{
	expand();
	for(int i=_size;i>r;i--)
	{
		_elem[i] = _elem[i-1];
	}
	_elem[r] = e;
	_size++;
	return r;	
}
template<typename T> int Vector<T>::remove(Rank lo,Rank hi)
{
	if(lo==hi) return 0;
	while(hi<_size) _elem[lo++] = _elem[hi++];
	_size = lo;
	shrink();
	return hi-lo;
}
template<typename T> int Vector<T>::remove(Rank r)
{
	T e = _elem[r];
	remove(r,r+1);
	return e;
}
template<typename T> int Vector<T>::deduplicate()
{
	int oldsize = _size;
	Rank i = 1;
	while(i<_size)
	{
		find(_elem[i],0,i)<0?i++:remove(i);
	}
	return oldsize-_size;
}
template<typename T> void Vector<T>::traverse(void(*visit)T&)
{
	for(int i=0;i<_size;i++) visit(_elem[i]);
}
template<typename T> template<typename VST>
void Vector<T>::traverse(VST& visit)
template<typename T> void Vector<T>::traverse(VST& visit)
{
	for(int i=0;i<_size;i++) visit(_elem[i]);
}
template<typename T>int Vector<T>::disordered()
{
	int n= 0;
	for(int i=1;i<_size;i++)
	{
		if(_elem[i-1]>_elem[i]) n++;
	}
	return n;
}
template<typename T> int Vector<T>::uniquify()
{
	Rank i=0,j=0;
	while(++j<_size)
	{
		if(_elem[i]!=_elem[j]) _elem[++i] = _elem[j];
	}
	_size = j;
	shrink();
	return j-i;
}
template<typename T> Rank Vector<T>::search(T const&e,Rank lo,Rank hi)
{
	return rand()%2?binSearch(_elem,e,lo,hi):fibSearch(_elem,e,lo,hi);
}
template<typename T> static Rank fibSearch(T *_elem,T const &e,Rank lo,Rank hi)
{
	Fib fib(hi-lo);
	while(lo<hi)
	{
		while(hi-lo<fib.get()) fib.prev();
		Rank mi = lo+fib.get()-1;
		if(e<_elem[mi]) hi = mi;
		else if(_elem[mi]<e) lo = mi+1;
		else return mi;
	}
	return -1;
}
template<typename T> static Rank binSearch(T *_elem,T const &e,Rank lo,Rank hi)
{
	while(lo<hi)
	{
		Rank mi = (lo+hi)/2;
		if(e<_elem[mi]) hi = mi;
		else lo= mi+1;
	}
	return --lo;
}
template<typename T> void Vector<T>::bubbleSort(Rank lo,Rank hi)
{
	while(lo<(hi=bubble(lo,hi));
} 
template<typename T> bool Vector<T>::bubble(Rank lo,Rank hi)
{
	Rank last = lo;
	while(++lo<hi)
	{
		if(_elem[lo-1]>_elem[lo]) {
		swap(_elem[lo-1],_elem[lo]);
		last=lo;
		}
	}
	return last;
}
template<typename T> void Vector<T>::mergeSort(Rank lo,Rank hi)
{
	if(hi-lo<2) return;
	int mi = (hi+lo)>>1;
	mergeSort(lo,mi);
	mergeSort(mi,hi);
	merge(lo,mi,hi);
}
template<typename T> void Vector<T>::merge(Rank lo,Rank mi,Rank hi)
{
	T *A  = _elem+lo;
	int lb = mi-lo;
	T *B = new T[lb];
	for(Rank i=0;i<lb;B[i]=A[i++]);
	int lc = hi-mi;
	T *C = _elem+mi;
	for(Rank i=0,j=0,k=0;(j<lb||k<lc);)
	{
		if((j<lb)&&(!(k<lc)||B[j]<=C[k])) A[i++]=B[j++];
		if((k<lc)&&(!(j<lb)||C[k]<B[j])) A[i++]= C[k++];
	}
	delete []B;
}
