int sum(int a[],int n)
{
	if(1>n) return 0;
	else return sum(a[],n-1)+a[n-1];
 } 
