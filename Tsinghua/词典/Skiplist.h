#include"List.h"
#include"Entry.h"
#include"Quadlist.h"
#include"Dictionary.h"

template<typename K,typename V>
class Skiplist:public Dictionary<K,V>,public List<Quadlist<Entry<K,V>>*>
{
    protected:
        bool skipSearch(ListNodePosi<Quadlist<Entry<K,V>>*>* &qlist,Quadlist<Entry<K,V>>* &p,K&k);
    public:
        int size() const{return empty()?0:last()->data->size();}
        int level(){return List::size();}
        bool put(K,V);
        V* get(K k);
        bool remove(K k);
};
template<typename K,typename V>V* Skiplist<K,V>::get(K k)
{
    if(empty()) return NULL;
    ListNode<Quadlist<Entry<K,V>>*>* qlist = first();
    QuadlistNode<Entry<K,V>>*p = qlist->data->first();
    return skipSearch(qlist,p,k)?&(p->entry.value):NULL;
}
template<typename K,typename V>bool Skiplist<K,V>::skipSearch(ListNodePosi<Quadlist<Entry<K,V>>*>* &qlist,Quadlist<Entry<K,V>>* &p,K&k)
{
    while (true)
    {
        while (p->succ&&(p->entry.key<=k))
        {
            p = p->succ;
        }
        p = p->pred;
        if(p->pred&&(k==p->entry.key)) return true;
        qlist = qlist->succ;
        if(!qlist->succ) return false;
        p = (p->pred)?p->below:qlist->data->first();
    }
    
}
template<typename K,typename V>bool Skiplist<K,V>::put(K k,V v)
{
    Entry<K,V> e = Entry<K,V>(k,v);
    if(empty()) inserAsFirst(new Quadlist<Entry<K,V>>);
    ListNode<Quadlist<Entry<K,V>>*>* qlist= first();
    QuadlistNode<Entry<K,V>>* p  = qlist->data->first();
    if(skipSearch(qlist,p,k))
        while(p->below) p = p->below;
    qlist = last();
    QuadlistNode<Entry<K,V>>* b = qlist->data->insertAfterAbove(e,p);
    while(rand()&1)
    {
        while (qlist->data->valid(p)&&!p->above) p = p->pred;
        if(!qlist->data->valie(p))
        {
            if(qlist==first())
                insertAsFirst(new Quadlist<Entry<K,V>>);
            P = qlist->pred->data->first()->pred;
        }else
        {
            p = p->above;
        }
        qlist = qlist->pred;
        b = qlist->data->insertAfterAbove(e,p,b);
    }
    return true;
}
template<typename T>QlistNodePosi(T) Quadlist<T>::insertAfterAbove(T const& e,QlistNodePosi(T) p,QlistNodePosi(T) b=NULL)
{
    _size++;
    return p->insertAsSuccAbove(e,b);
}
template<typename T>QlistNodePosi(T) QuadlistNode<T>::insertAsSuccAbove(T const& e,QlistNodePosi(T) b=NULL)
{
    QlistNodePosi(T) x = new QuadlistNode<T>(e,this,succ,NULL,b);
    succ->pred = x;
    succ = x;
    if(b) b->above = x;
    return x;
}
template<typename K,typename V>bool Skiplist<K,V>::remove(K k)
{
    if(empty()) return false;
    ListNode<Quadlist<Entry<K,V>>*>* qlist = first();
    QuadlistNode<Entry<K,V>>* p = qlist->data->first();
    if(!skipSearch(qlist,p,k)) return false;
    do
    {
        QuadlistNode<Entry<K,V>>* lower = p->below;
        qlist->data->remove(p);
        p = lower;
        qlist= qlist->succ;
    } while (qlist->succ);
    while(!empty()&&first()->data->empty())
        List::remove(first());
}
template<typename T> T Quadlist<T>::remove(QlistNodePosi(T) p)
{
    p->pred->succ = p->succ;
    p->succ->pred = p->pred;
    _size--;
    T e = p->entry;
    delete p ;
    return e;
}
template<typename T>int Quadlist<T>::clear()
{
    int oldsize = _size;
    while (0<_size)
    {
        remove(header->succ);
    }
    return oldsize;
}