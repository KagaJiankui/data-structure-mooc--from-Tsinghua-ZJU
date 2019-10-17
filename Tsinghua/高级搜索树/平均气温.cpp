#include<iostream>
#include<cstdlib>
#include "temperature.h"
struct point
{
	int x, y, tem;
	point() :x(0), y(0)
	{

	}
};
struct range
{
    int x1,x2,y1,y2;
};

point* s;
long long int mysum;
int cnt;
int cmp_x(const void *a, const void *b)
{
	if (((*(point*)a).x<(*(point*)b).x)) return -1;
	else if(((*(point*)a).x==(*(point*)b).x)) return 0;
	else return 1;
}
int cmp_y(const void *a, const void *b)
{
	if (((*(point*)a).y<(*(point*)b).y)) return -1;
	else if(((*(point*)a).y==(*(point*)b).y)) return 0;
	else return 1;
}
struct treeNode
{
	int loc;
	treeNode* left;
	treeNode* right;
    range ran; 
    int sum;
    int num;
	treeNode()
	{
		left = NULL;
		right = NULL;
		loc = 0;
        sum = 0;
        num = 0;
	}
};
class kdtree
{
private:
	treeNode* root;
	treeNode* mktree(treeNode*& v, int lo, int hi, int depth, point* s)
	{
		if (!(lo < hi)) return NULL;
		v = new treeNode;
		if (depth % 2 == 0)
		{
			qsort(s + lo, hi-lo,sizeof(point), cmp_x);
            v->ran.x1 = s[lo].x;
            v->ran.x2 = s[hi-1].x;
            v->ran.y1 = s[lo].y;
            v->ran.y2 = s[lo].y;
            for(int i=lo;i<hi;i++)
            {
                if(s[i].y<v->ran.y1) v->ran.y1 = s[i].y;
                if(s[i].y>v->ran.y2) v->ran.y2 = s[i].y;
                v->sum+=s[i].tem;
                v->num++;
            }
		}
		else {
			qsort(s + lo, hi-lo, sizeof(point),cmp_y);
            v->ran.y1 = s[lo].y;
            v->ran.y2 = s[hi-1].y;
            v->ran.x1 = s[lo].x;
            v->ran.x2 = s[lo].x;
            for (int i = lo; i < hi; i++)
            {
                if(s[i].x<v->ran.x1) v->ran.x1 = s[i].x;
                if(s[i].x>v->ran.x2) v->ran.x2 = s[i].x;
                v->sum+=s[i].tem;
                v->num++;
            }
		}
		int mid = (lo + hi) / 2;
		v->loc = mid;
		v->left = mktree(v->left, lo, mid, depth + 1, s);
        if(v->left) v->right = mktree(v->right, mid, hi, depth + 1, s);
        else v->right = NULL;
		return v;
	}
	void search(treeNode* v, int sx, int tx, int sy, int ty, int depth)
	{
        if(v->left==NULL&&v->right==NULL)
        {
            if (sx <= v->ran.x1 && sy <= v->ran.y1 && v->ran.y2 <= ty && v->ran.x2 <= tx)
            {
                mysum += v->sum;
                cnt+=v->num;
            }
            return;
        }
        if(v->left->ran.x1>=sx&&v->left->ran.x2<=tx&&v->left->ran.y1>=sy&&v->left->ran.y2<=ty)
        {
            mysum+=v->left->sum;
            cnt+=v->left->num;
        }else if(v->left->ran.x2>=sx&&v->left->ran.y2>=sy&&v->left->ran.x1<=tx&&v->left->ran.y1<=ty)
        {
            search(v->left,sx,tx,sy,ty,depth+1);
        }
        if(v->right->ran.x1>=sx&&v->right->ran.x2<=tx&&v->right->ran.y1>=sy&&v->right->ran.y2<=ty)
        {
            mysum+=v->right->sum;
            cnt+=v->right->num;
        }else if(v->right->ran.x2>=sx&&v->right->ran.y2>=sy&&v->right->ran.x1<=tx&&v->right->ran.y1<=ty)
        {
            search(v->right,sx,tx,sy,ty,depth+1);
        }
	}
public:
	kdtree()
	{
		root = NULL;
	}
	int query(int sx, int tx, int sy, int ty)
	{
		mysum = 0;
		cnt = 0;
		search(root, sx, tx, sy, ty, 0);
        if(cnt==0) return 0;
		return mysum / cnt;
	}
	void init(point* s, int size)
	{
		mktree(root, 0, size, 0, s);
	}
};
signed main()
{
	int n, m;
	int sx, tx, sy, ty;
    n = GetNumOfStation();
	if(n==0)
	{
		while (GetQuery(&sx,&sy,&tx,&ty))
		{
			Response(0);
		}
		return 0;
	}
	//scanf("%d %d", &n, &m);
	s = new point[n];
	kdtree T;
	for (int i = 0; i < n; i++)
	{
        GetStationInfo(i,&s[i].x,&s[i].y,&s[i].tem);
	}
	T.init(s, n);
	while (GetQuery(&sx,&sy,&tx,&ty))
	{
		int ave = T.query(sx, tx, sy, ty);
		Response(ave);
	}

}