void quick_select(int *a,int hi,int k)
{
	for(lo=0;lo<hi;)
	{
		int i=lo;
		int j = hi-1;
		int pivot = a[lo];
		while(i<j)
		{
			while(i<j&&pivot<=a[j]) j--;
			a[i] = a[j];
			while(i<j&&pivot>=a[i]) i++;
			a[j] = a[i];
 		}
 		a[i] = pivot;
 		if(i<=k) lo=i+1;
 		if(i>=k) hi = i-1;
	}
}
