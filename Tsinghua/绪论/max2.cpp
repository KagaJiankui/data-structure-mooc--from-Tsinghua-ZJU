void max2(int a[],int lo,int hi,int &x1,int &x2)
{
	for(x1=lo,int i=lo+1;i<hi;i++)
	{
		if(a[x1]<a[i]) x1 = i;
	}
	for(x2=lo,int i=lo+1;i<x1;i++)
	{
		if(a[x2]<a[i]) x2 = i;
	}
	for(int i=x1+1;i<hi;i++)
	{
		if(a[x2]<a[i]) x2 = i;
	}
}

void max2(int a[],int lo,int hi,int &x1,int &x2)
{
	if(a[x1=lo]<a[x2=lo+1]) swap(x1,x2);
	for(int i=lo+2;i<hi;i++)
	{
		if(a[x2]<a[i]){
			if(a[x1]<a[x2=i])
			{
				swap(x1,x2);
			}
		}
	}
}

void max2(int a[],int lo,int hi,int &x1,int &x2)
{
	if(lo+2==hi) {
		a[lo]>a[hi-1]?(x1=lo,x2=hi-1):(x2=lo,x1=hi-1);
		return;
	}
	if(lo+3==hi)
	{
		if(a[lo]>a[lo+1])
		{
			if(a[lo]>a[hi-1])
			{
				x1 = lo;
				(a[lo+1]>a[hi-1])? x2 = lo+1:x2 = hi-1;
			}else{
				x1 = hi-1;
				x1  = lo;
			}
		}else{
			if(a[lo+1]>a[hi-1])
			{
				x1 = lo+1;
				a[hi-1]>a[lo]?x2=hi-1:x2=lo;
				
			}else {
				x1 = hi-1;
				x2 = lo+1;
			}
		}
		return;
	}
	int mi = (lo+hi)/2;
	int x1L,x2L;
	max2(a,lo,mi,x1L,x2L);
	int x1R,x2R;
	max2(a,mi,hi,x1R,x2R);
	if(a[x1L]>a[x1R])
	{
		x1 = x1L;
		x2 = (a[x2L]>a[x1R])?x2L:x1R;
	}else{
		x1 = x1R;
		x2 = (a[x1L]>a[x2R])?x1L:x2R;
	}
}
