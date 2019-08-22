void bubble_sort(int a[],int length)
{
	int flag=0;
	while(flag==0)
	{
		flag = 1;
		for(int i=0;i<length-1;i++)
		{
			if(a[i+1]<a[i])
			{
				swap(a[i+1],a[i]);
				flag = 0;
			}
		}
		length--;
	}
} 
