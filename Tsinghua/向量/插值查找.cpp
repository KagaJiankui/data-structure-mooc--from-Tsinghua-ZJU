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
}//����ʧ�ܷ��ز�����e����������±꣬Ҫ��e������a[length-1] 
