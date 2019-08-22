void reverse(int *a,int left,int right)
{
	if(left<right)
	{
		swap(a[left],a[right]);
		reverse(a,left+1,right-1);
	}
}
