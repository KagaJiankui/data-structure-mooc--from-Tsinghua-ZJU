#include<cstdio>
using namespace std;
struct node{
	int data;
	node* left;
	node* right;
	node():left(NULL),right(NULL){
	}
};
int* pre;
int* post;
void build(node*& t,int pre_begin,int pre_end,int post_begin,int post_end)
{
	t = new node;
	t->data = pre[pre_begin];
	if(pre_begin==pre_end-1) return;
	int index;
	for(int i=post_begin;i<post_end;i++)
	{
		if(pre[pre_begin+1]==post[i])
		{
			index=i;
			break;
		}
	}
	build(t->left,pre_begin+1,index+1-post_begin+pre_begin+1,post_begin,index+1);
	build(t->right,index-post_begin+1+1+pre_begin,pre_end,index+1,post_end-1);
}
void dfs(node* t)
{
	if (t == NULL) return;
	dfs(t->left);
	printf("%d ", t->data);
	dfs(t->right);
}
int main()
{
	int n;
	scanf("%d", &n);
	pre = new int[n];
	post = new int[n];
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &pre[i]);
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &post[i]);
	}
	node* root = NULL;
	build(root, 0, n, 0, n);
	dfs(root);
}
 
