int insert_search(int a[],int e,int length)
{
	int left,right,mid;
	left = 0,right = length-1;
	while(left<right)
	{
		mid= left+(right-left)*(e-a[left])/(a[right]-a[left]);
		if(mid<left) break;
		if(e<a[mid]) right = mid;
		else left = mid+1;
	}
	return --left;
}//查找失败返回不大于e的最大整数下标，要求e不大于a[length-1] 
