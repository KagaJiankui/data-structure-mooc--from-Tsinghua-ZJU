#include"PQ.h"
#include"BinTree.h"
template<typename T> class PQ_LeftHeap:public PQ<T>,public BinTree<T>
{
public:
    PQ_LeftHeap(/* args */){}
    PQ_LeftHeap(T* E,int n)
    {
        for (int i = 0; i < n; i++)
        {
            insert(E[i];)
        }  
    }
    void insert(T);
    T getMax(){return _root->data;}
    T delMax();
};
template<typename T>
static BinNodePosi(T) merge(BinNodePosi(T) a,BinNodePosi(T) b)
{
    if(!a) return b;
    if(!b) return a;
    a->rChild = merge(a->rChild,b);
    a->rChild->parent = a;
    if(!a->lChild||a->lChild->npl<a->rChild->npl)
        swap(a->lChild,a->rChild);
    a->npl = a->rChild?a->rChild->npl+1:1;
    return a;
}
template<typename T> T PQ_LeftHeap<T>::delMax()
{
    BinNodePosi(T) lHeap = _root->lChild;
    BinNodePosi(T) rHeap = _root->rChild;
    T e = _root->data;
    delete _root;
    _size--;
    _root = merge(lHeap,rHeap);
    if(_root) _root->parent = NULL;
    return e;
}
template<typename T> void PQ_LeftHeap<T>::insert(T e)
{
    BinNodePosi(T) v = new BinNode<T>(e);
    _root = merge(_root,v);
    _root->parent = NULL;
    _size++;
}
