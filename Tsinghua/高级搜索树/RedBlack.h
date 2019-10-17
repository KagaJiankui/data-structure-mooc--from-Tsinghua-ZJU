#include"BST.h"
#define IsBlack(p) (!(p)||(RB_BLACK==(p)->color))
#define IsRed(p) (!IsBlack(p))
#define BlackHeightUpdated(x) (\
    (stature((x).lChild))==stature((x).rChild)&&\
    ((x).height==(IsRed(&x)?stature((x).lChild):stature((x).lChild)+1))\
)

template<typename T>class RedBlack:public BST<T>
{
    protected:
        void solveDoubleRed(BinNodePosi(T) x);
        void solveDoubleBalck(BinNodePosi(T) x);
        int updateHeight(BinNodePosi(T) x);
public:
    BinNodePosi(T) insert(const T& e);
    bool remove(const T&e);
};
template<typename T>int RedBlack<T>::updateHeight(BinNodePosi(T) x)
{
    x->height = max(stature(x->lChild),stature(x->rChild));
    return IsBlack(x)?x->height++:x->height;
}
