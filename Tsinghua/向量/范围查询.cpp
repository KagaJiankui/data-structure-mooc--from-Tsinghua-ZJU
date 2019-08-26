#include<iostream>
using namespace std;
void merge(int num[],int lo,int mi,int hi)
{
	int la = mi-lo;
	int lb = hi-mi;
	int *temp = num+lo;
	int *a = new int[la];
	for(int i=0;i<la;i++) a[i] = temp[i];
	int *b = num+mi;
	for(int i=0,j=0,k=0;j<la||k<lb;)
	{
		if(j<la&&((k>=lb)||(a[j]<b[k]))) temp[i++] = a[j++];
		if(k<lb&&(j>=la||b[k]<=a[j])) temp[i++] = b[k++];
	}
	delete []a;
}
void mergeSort(int num[],int lo,int hi)
{
	if(hi-lo<2) return;
	int mi = (lo+hi)/2;
	mergeSort(num,lo,mi);
	mergeSort(num,mi,hi);
	merge(num,lo,mi,hi);
}
int binsearch(int a[],int e,int len)
{
	int left = 0,right =len;
	int mid;
	while(left<right)
	{
		mid = (left+right)>>1;
		if(e<a[mid]) right = mid;
		else left = mid+1;
	}
	return --left;
}//小于等于e的第一个元素 
int uppersearch(int a[],int e,int len)
{
	int left = 0,right =len;
	int mid;
	while(left<right)
	{
		mid = (left+right)>>1;
		if(e<a[mid]) right = mid;
		else left = mid+1;
	}
	if(left==0) return 0;
	if(a[left-1]==e) return --left;
	return left;
}//大于等于e的第一个元素 
int main()
{
	int n, m;
	cin >> n >> m;
	int* poi = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> poi[i];
	}
	mergeSort(poi,0,n);
	for (int i = 0; i < m; i++)
	{
		int bg, ed;
		int k, j;
		cin >> bg >> ed;
		int cnt = 0;
		if (poi[0] > ed||poi[n-1]<bg)
		{
			cout << 0 << endl;
		}//最值和区间有交集       
		else {
			j = uppersearch(poi,bg,n);
			k = binsearch(poi,ed,n);
			cnt = k-j+1;
			cout << cnt << endl;
		}
	}
}
