#include "ListNode.h"

template<typename T>class List
{
	private:
		int _size;
		ListNodePosi(T) header;
		ListNodePosi(T) trailer;
	protected:
		void init();
		int clear();
		void copyNodes(ListNodePosi(T),int);
		void merge(ListNodePosi(T)&,List<T>&,ListNodePosi(T),int);
		void mergeSort(ListNodePosi(T)&,int);
		void selectionSort(ListNodePosi(T),int);
		void insertionSort(ListNodePosi(T),int);
	public:
		List(){init();}
		List(List<T>const&L);
		List(List<T> const&L,Rank r,int n);
		List(ListNodePosi(T) p,int n);
		~List();
		T& operator[](Rank r) const;
		ListNodePosi(T) first() const{return header->succ;}
		ListNodePosi(T) last() const{return trailer->pred;}
		ListNodePosi(T) find(T const&e,int n,ListNodePosi(T)p) const;
		ListNodePosi(T) find(T const &e){return find(e,_size,trailer);}
		ListNodePosi(T) insertAsFirst(T const&e);
		ListNodePosi(T) insertAsLast(T const&e);
		ListNodePosi(T)	insertBefore(ListNodePosi(T) p,T const &e);
		ListNodePosi(T) insertAfter(ListNodePosi(T) p,T const&e);
		
		
} 
template<typename T>void List<T>::init()
{
	header = new ListNode<T>
	trailer = new ListNode<T>
	header->succ = trailer;
	header->pred = NULL;
	trailer->pred = header;
	trailer->succ = NULL;
	_size= 0;
}
template<typename T> T &List<T>::operator[](Rank r) const
{
	ListNodePosi(T) p = first();
	while(0<r--) p = p->succ;
	return p->data;
}
template<typename T> ListNodePosit(T) List<T>::find(T const &e,int n,ListNodePosi(T) p) const
{
	while(0<n--)
	{
		if(e==(p=p->pred)->data) return p;
	}
	return NULL;
}
template<typename T> ListNodePosi(T) List<T>::insertAsFirst(T const&e)
{
	_size++;
	return header->insertAsSucc(e);
}
template<typename T> ListNodePosi(T) List<T>::insertAsLast(T const&e)
{
	_size++;
	return trailer->insertAsPred(e);
}
template<typename T> ListNodePosi(T) List<T>::insertBefore(ListNodePosi(T) p,T const &e)
{
	_size++;
	return p->insertAsPred;
}
template<typename T> ListNodePosi(T) List<T>::insertAfter(ListNodePosi(T) p,T const&e)
{
	_size++;
	return p->insertAsSucc(e);
}

