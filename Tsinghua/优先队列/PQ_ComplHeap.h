#define InHeap(n,i) (((-1)<(i))&&((i)<(n)))
#define Parent(i) ((i-1)>>1)
#define LastInternal(n) Parent(n-1)
#define LChild(i) (1+(i)<<1)
#define RChild(i) (((i)+1)<<1)
#define ParentValid(i) (0<i)
#define LChildValid(n,i) InHeap(n,LChild(i))
#define RChildValid(n,i) InHeap(n,RChild(i))
#define Bigger(PQ,i,j) ((PQ[i]<PQ[j]?j:i))
#define ProperParent(PQ,n,i) \
( RChildValid(n,i) ? Bigger( PQ, Bigger( PQ,i,LChild(i) ),RChild(i) ):\
    ( LChildValid(n,i)? Bigger( PQ, i,LChild(i) ):i\
    )\
    )
#include"PQ.h"
#include"Vector.h"
template<typename T>class PQ_ComplHeap:public PQ<T>,public Vector<T>
{
    protected:
        int percolateDown(int n,int i);
        int percolateUp(int i);
        void heapify(int n);
public:
    PQ_ComplHeap(/* args */){}
    PQ_ComplHeap(T* A,int n){copyFrom(A,0,n);heapify(n);}
    void insert(T);
    T getMax();
    T delMax();
};
template<typename T> T PQ_ComplHeap<T>::getMax(){return _elem[0];}
template<typename T>void PQ_ComplHeap<T>::insert(T e)
{
    Vector<T>::insert(e);
    percolateUp(_size-1);
}
template<typename T>int PQ_ComplHeap<T>::percolateUp(int i)
{
    while(ParentValid(i))
    {
        int j = Parent(i)
        if(_elem[i]<_elem[j]) break;
        else swap(_elem[i],_elem[j]);
    }
    return i;
}
template<typename T> T PQ_ComplHeap<T>::delMax()
{
    T maxElem = _elem[0];
    _elem[0] = _elem[--size];
    percolateDown(_size,0);
    return maxElem;
}
template<typename T>int PQ_ComplHeap<T>::percolateDown(int n,int i)
{
    int j;
    while(i!=(j=ProperParent(_elem,n,i)))
    {
        swap(_elem[i],_elem[j]);
        i = j;
    }
    return i;
}
template<typename T>void PQ_ComplHeap<T>::heapify(int n)
{
    for(int i=LastInternal(n);InHeap(n,i);i--)
    {
        percolateDown(n,i);
    }
}
template<typename T>void Vector<T>::heapSort(int lo,int hi)
{
    PQ_ComplHeap<T> H(_elem+lo,_elem+hi);
    while(!H.empty())
    {
        _elem[hi--] = H.delMax();
    }
}