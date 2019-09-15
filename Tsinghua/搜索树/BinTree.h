#include"BinNode.h"
template<typename T> class BinTree{
	protected:
		int _size;
		BinNodePosi(T) _root;
		virtual int updateHeight(BinNodePosi(T) x);
		void updateHeightAbove(BinNodePosi(T) x);
	public:
		BinTree():_size(0),_root(NULL){}
		~BinTree(){if(0<_size) remove(_root);}
		int size() const{return _size;}
		bool empty() const{return !_root;}
		BinNodePosi(T) root() const{return root;}
		BinNodePosi(T) insertAsRoot(T const&e);
		BinNodePosi(T) insertAsLC(BinNodePosi(T) x,T const&e);
		BinNodePosi(T) insertAsRC(BinNodePosi(T) x,T const&e);
		BinNodePosi(T) attachAsLC(BinNodePosi(T) x,BinTree<T>* &T);
		BinNodePosi(T) attachAsRC(BinNodePosi(T) x,BinTree<T>* &T);
		int remove(BinNodePosi(T) x);
		BinTree<T> secede(BinNodePosi(T) x);
}
template <typename T> int BinTree<T>::updateHeight(BinNodePosi(T) x)
{
	return x->height = 1+max(stature(x->lChild),stature(x->rChild));
}
template <typename T> void BinTree<T>::updateHeightAbove(BinNodePosi(T) x)
{
	while(x)
	{
		updateHeight(x);
		x = x->parent;
	}
}
template <typename T> BinNodePosi(T) BinTree<T>::insertAsRoot(T const& e)
{
	_size = 1;
	return _root = new BinNode<T>(e);
}
template <typename T> BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, T const& e)
{
	_size++;
	x->insertAsLC(e);
	updateHeightAbove(x);
	return x->lChild;
}
template <typename T> BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, T const& e)
{
	_size++;
	x->insertAsRC(e);
	updateHeightAbove(x);
	return x->rChild;
}
template <typename T>BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>* &s)
{
	if(x->lChild=s->_root) x->lChild->parent = x;
	_size +=s->_size;
	updateHeightAbove(x);
	s->_root = NULL;
	s->_size = 0;
	release(s);
	s = NULL;
	return x;
}
template<typename T> BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>* &s)
{
	if(x->rChild = s->_root) x->rChild->parent = x;
	_size+=s->_size;
	updateHeightAbove(x);
	s->_root = NULL;
	s->_size = 0;
	release(s);
	s = NULL;
	return x; 
}
template <typename T> int BinTree<T>::remove(BinNodePosi(T) x)
{
	FromParentTo(*x) = NULL;
	updateHeightAbove(x->parent);
	int n = removeAt(x);
	_size-=n;
	return n;
}

template <typename T> static int removeAt(BinNodePosi(T) x)
{
	if(!x) return 0;
	int n = 1+removeAt(x->lChild)+removeAt(x->rChild);
	release(x->data);
	release(x);
	return n;
}
template <typename T> BinTree<T>* BinTree<T>::secede(BinNodePosi(T) x)
{
	FromParentTo(*x) = NULL;
	updateHeightAbove(x->parent);
	BinTree<T>*s = new BinTree<T>;
	s->_root = x;
	x->parent = NULL;
	s->_size = x->size();
	_size -= s->_size;
	return s;
}
template<typename T,typename VST> void travPre_R(BinNodePosi(T) x,VST&visit)
{
	if(!x) return;
	visit(x->data);
	travPre_R(x->lChild,visit);
	travPre_R(x->rChild,visit);
}
template<typename T,typename VST> void travPost_R(BinNodePosi(T) x,VST &visit)
{
	if(!x) return;
	travPost_R(x->lChild,visit);
	travPost_R(x->rChild,visit);
	visit(x->data);
}
template<typename T,typename VST> void travIn_R(BinNodePosi(T),VST&visit)
{
	if(!x) return;
	travIn_R(x->lChild,visit);
	visit(x->data);
	travIn_R(x->rChild,visit);
}
template<typename T,typename VST>
static void visitAlongLeftBranch(BinNodePosi(T) x,VST& visit,stack<BinNodePosi(T)>& s)
{
	while(x)
	{
		visit(x->data);
		s.push(x->rChild);
		x = x->lChild;
	}
}
template<typename T,typename VST>
void travPre_I2(BinNodePosi(T) x,VST &visit)
{
	stack<BinNodePosi(T)> s;
	while(true)
	{
		visitAlongLeftBranch(x,visit,s);
		if(s.empty()) break;
		x = s.pop();
	}
}
template<typename T> static void goAlongLeftBranch(BinNodePosi(T) x,Stack<BinNodePosi(T)& s)
{
	while(x)
	{
		s.push(x);
		x = x->lChild;
	}
}
template<typename T,typename VST>
void travIn_I1(BinNodePosi(T) x,VST &visit)
{
	stack<BinNodePosi(T)> s;
	while(true)
	{
		goAlongLeftBranch(x,s);
		if(s.empty()) break;
		x = s.pop();
		visit(x->data);
		x = x->rChild;
	}
}
template<typename T> BinNodePosi(T) BinNode<T>::succ()
{
	BinNodePosi(T) s= this;
	if(rChild)
	{
		s = rChild;
		while(HasLChild(*s)) s = s = s->lChild;
	}else{
		while(IsRChild(*s)) s = s->parent;
		s = s->parent;
	}
	return s;
}
template<typename T,typename VST> void travIn_I2(BinNodePosi(T),VST& visit)
{
	stack<BinNodePosi(T)> s;
	while(true)
	{
		if(x)
		{
			s.push(x);
			x=x->lChild;
		}else if(!s.empty())
		{
			x = s.pop();
			visit(x->data);
			x = x->rChild;
		}else{
			break;
		}
	}
}
template<typename T,typename VST>
void travIn_I3(BinNodePosi(T) x,VST&visit)
{
	bool backtrack = false;
	while(true)
	{
		if(!backtrack&&HasLChild(*x)) x = x->lChild;
		else{
			visit(x->data);
			if(HasRchild(*x))
			{
				x = x->rChild;
				backtrack = false;
			}else{
				if(!(x=x->succ())) break;
				backtrack = true;
			}
		}
	}
}
template<typename T> static void gotoHLVFL(stack<BinNodePosi(T)> &s)
{
	while(BinNodePosi(T) x = s.top())
	{
		if(HasLChild(*x))
		{
			if(HasRChild(*x)) s.push(x->rChild);
			s.push(x->lChild);
		}else{
			s.push(x->rChild);
		}
	}
	s.pop();
}
template<typename T,typename VST>
void travPost_I(BinNodePosi(T) x,VST &visit)
{
	stack<BinNodePosi(T)> s;
	if(x) s.push(x);
	while(!s.empty())
	{
		if(s.top()!=x->parent) gotoHLVFL(s);
		x = s.pop();
		visit(x->data);
	}
}
template<typename T> template<typename VST>
void BinNode<T>::travLevel(VST &visit)
{
	queue<BinNodePosi(T)> Q;
	Q.enqueue(this);
	while(!Q.empty())
	{
		BinNodePosi(T) x = Q.dequeue();
		visit(x->data);
		if(HasLChild(*x)) Q.enqueue(x->lChild);
		if(HasRChild(*x)) Q.enqueue(x->rChild);
	}
}
