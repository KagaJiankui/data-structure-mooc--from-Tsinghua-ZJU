#include"BinTree.h"
typedef BinTree<char> PFCTree;
#include<vector>
typedef vector<PFCTree*> PFCForest;
#include"Skiplist.h"
#include "Bitmap.h"
typedef SkipList<char,char*> PFCTable;
#define N_CHAR(0x80-0x20)
PFCForest* initForest()
{
	PFCForest* forest = new PFCForest;
	for(int i=0;i<N_CHAR;i++)
	{
		forest->insert(i,new PFCTree());
		(*forest)[i]->insertAsRoot(0x20+i);
	}
	return forest;
}
PFCTree* generateTree(PFCForest* forest)
{
	srand((unsigned int)time(NULL));
	while(1<forest->size())
	{
		PFCTree* s = new PFCTree;
		s->insertAsRoot('^');
		Rank r1 = rand()%forest->size();
		s->attachAsLC(s->root,(*forest)[r1]);
		forest->remove(r1);
		Rank r2 = rand()%forest->size();
		s->attachAsRC(s->root(),(*forest)[r2]);
		forest->remove(r2);
		forest->insert(forest->size(),s);
	}
	return (*forest)[0];
}
void generateCT
(Bitmap* code,int length,PFCTable* table,BinNodePosi(char)v)
{
	if(IsLeaf(*v))
	{
		table->put(v->data,code->bits2string(length));
		return;
	}
	if(HasLChild(*v))
	{
		code->clear(length);
		generateCT(code,length+1,table,v->lChild);
	}
	if(HasRChild(*v))
	{
		code->set(length);
		generateCT(code,length+1,table,v->rChild);
	}
}
PTCTable* generateTable(PTCTree* tree)
{
	PFCTable* table= new PFCTable;
	Bitmap* code = new Bitmap;
	generateCT(code,0,table,tree->root());
	release(code);
	return table;
}
int encode(PFCTable* table,Bitmap& codeString,char*s);
int main(int argc,char* argv[])
{
	PFCForest* forest = initForest();
	PFCTree *tree = generateTree(forest);
	release(forest);
	PFCTable* table = generateTable(tree);
	for(int i=1;i<argc;i++)
	{
		BitMap = codeString;
		int n = encode(table,codeString,argv[i]);
		decode(tree,codeString,n);
	}
} 
