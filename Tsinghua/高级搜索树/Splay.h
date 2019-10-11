#include"BST.h"
template<typename T>class Splay:public BST<T>
{
protected:
    BinNodePosi(T) splay(BinNodePosi(T) v);
public:
    BinNodePosi(T)& search(const T&e);
    BinNodePosi(T) insert(const T& e);
    bool remove(const T& e);
};
template<typename NodePosi>inline
void attachAsLChild(NodePosi p,NodePosi lc){p->lChild=lc;if(lc) lc->parent=p;}
template<typename NodePosi>inline
void attachAsRChild(NodePosi p,NodePosi rc){p->rChild=rc;if(rc) rc->parent=p;}
template<typename T>BinNodePosi(T) Splay<T>::splay(BinNodePosi(T) v)
{
    if(!v) return NULL;
    BinNodePosi(T) p;
    BinNodePosi(T) g;
    while((p=v->parent)&&(g=p->parent))
    {
        BinNodePosi(T) gg=g->parent;
        if(IsLChild(*V))
        {
            if (IsLChild(*p))
            {
                attachAsLChild(g,p->rChild);
                attachAsLChild(p,v->rChild);
                attachAsRChild(p,g);
                attachAsRChild(v,p);
            }else
            {
                attachAsLChild(p,v->rChild);
                attachAsRChild(g,v->lChild);
                attachAsLChild(v,g);
                attachAsRChild(v,p);
            }          
        }else if(IsRchild(*p))
        {
            attachAsRChild(g,p->lChild);
            attachAsRChild(p,v->lChild);
            attachAsLChild(p,g);
            attachAsLChild(v,p);
        }else
        {
            attachAsRChild(p,v->lChild);
            attachAsLChild(g,v->rChild);
            attachAsRChild(v,g);
            attachAsLChild(v,p);
        }
        if(!gg) v->parent = NULL;
        else
        {
            (g=gg->lChild)?attachAsLChild(gg,v):attachAsRChild(gg,v);
        }
        updateHeight(g);
        updateHeight(p);
        updateHeight(v);               
    }
    if(p=v->parent)
    {
        if(IsLChild(*v)){attachAsLChild(p,v->rChild);attachAsRChild(v,p);}
        else {attachAsRChild(p,v->lChild);attachAsLChild(v,p);}
        updateHeight(p);
        updateHeight(v);
    }
    v->parent = NULL;
    return v;
}
template<typename T>BinNodePosi(T)& Splay<T>::search(const T& e)
{
    BinNodePosi(T) p = searchIn(_root,e,_hot=NULL);
    _root = splay((p?p:_hot));
    return _root;
}
template<typename T>BinNodePosi(T) Splay<T>::insert(const T& e)
{
    if(!_root){_size++;return _root=new BinNode<T>(e);}
    if(e==search(e)->data) return _root;
    _size++;
    BinNodePosi(T) t=_root;
    if(_root->data<e)
    {
        t->parent = _root = new BinNode<T>(e,NULL,t,t->rChild);
        if(HasRchild(*t)){t->rChild->parent=_root;t->rChild=NULL;}
    }else
    {
        t->parent = _root = new BinNode<T>(e,NULL,t->lChild,t);
        if(HasLchild(*t)){t->lChild->parent=_root;t->lChild=NULL;}
    }
    updateHeightAbove(t);
    return _root;    
}
template<typename T>bool Splay<T>::remove(const T& e)
{
    if(!_root||(e!=search(e)->data)) return false;
    BinNodePosi(T) w = _root;
    if(!HasLchild(*_root)
    {
        _root = _root->rChild;
        if(_root) _root->parent = NULL;
    }else if(!HasRchild(*_root))
    {
        _root = _root->lChild;
        if(_root) _root->parent =NULL;
    }else
    {
        BinNodePosi(T) lTree = _root->lChild;
        lTree->parent = NULL;
        _root->lChild = NULL;
        _root = _root->rChild;
        _root->parent  = NULL;
        search(w->data);
        _root->lChild = lTree;
        lTree->parent = _root;
    }
    release(w->data);
    realease(w);
    _size--;
    if(_root) updateHeight(_root);
    return true;
    
}