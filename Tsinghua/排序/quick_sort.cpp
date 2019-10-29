#include<ctime>
#include<algorithm>
using namespace std;
int partition(int *a,int lo,int hi)
{
    srand(time(0));
    int k = lo+rand()%(hi-lo+1);
    swap(a[lo],a[k]);
    int pivot = a[lo];
    int mi = lo;
    for(int k=lo+1;k<=hi;k++)
    	if(a[k]<pivot)
    		swap(a[++mi],a[k]);
    swap(a[lo],a[mi]);
    return mi;
}
void quicksort(int *a,int lo,int hi)
{
	if(hi-lo<2) return;
    int m = partition(a,lo,hi-1);
    quicksort(a,lo,m);
    quicksort(a,m+1,hi);
}
