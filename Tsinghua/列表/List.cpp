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
template<typename T>
T &List<T>::operator[](Rank r) const
{
	ListNodePosi(T) p = first();
	while(0<r--) p = p->succ;
	return p->data;
}

