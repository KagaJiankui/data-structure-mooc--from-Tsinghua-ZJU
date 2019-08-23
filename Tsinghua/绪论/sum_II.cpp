int sum(int a[],int left,int right)
{
	if(left==right) return a[left];
	else{
		int mid = (left+right)>>1;
		return sum(a,left,mi)+sum(a,mi+1,right);
	}
}
