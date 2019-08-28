#include<iostream>
#include<cstdlib>
using namespace std;
long long int inv;
typedef struct poi{
	long long int x;
	long long int y;
}poi;
int cmp(const void *a,const void *b)
{
	poi *c = (poi*)a;
	poi *d = (poi*)b; 
	if(c->x!=d->x) return (c->x-d->x);
	else return (c->y-d->y);
}
void merge(int *_elem,int lo,int mi,int hi);
void mergeSort(int num[],int lo,int  hi)
{
	if(hi-lo<2) return;
	int mi = (hi+lo)>>1;
	mergeSort(num,lo,mi);
	mergeSort(num,mi,hi);
	merge(num,lo,mi,hi);
}
void merge(int *_elem,int lo,int mi,int hi)
{
	int *A  = _elem+lo;
	int lb = mi-lo;
	int *B = new int[lb];
	for(int i=0;i<lb;B[i]=A[i++]);
	int lc = hi-mi;
	int *C = _elem+mi;
	for(int i=0,j=0,k=0;(j<lb||k<lc);)
	{
		if((j<lb)&&(!(k<lc)||B[j]<=C[k])) A[i++]=B[j++];
		if((k<lc)&&(!(j<lb)||C[k]<B[j]))
		{
			if(C[k]<B[j])
			{
				inv+=(lb-j);
			}
			A[i++] = C[k++];
		}
	}
	delete []B;
}
int main()
{
	int n;
	cin>>n;
	long long int cnt=  0;
	poi *ds=new poi[n];
	int *ty=new int [n];
	for(int i=0;i<n;i++)
	{
		scanf("%lld %lld",&ds[i].x,&ds[i].y);
	}
	qsort(ds,n,sizeof(poi),cmp);
	for(int i=0;i<n;i++)
	{
		ty[i] = ds[i].y;
	}
	mergeSort(ty,0,n);
	long long int k = n;
	cout<<k*(k-1)/2-inv<<endl;
	delete []ds;
	delete []ty;
} 
