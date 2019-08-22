int countones(int n)
{
	int ones = 0;
	while(n!=0)
	{
		ones+=(1&n);
		n=n>>1;
	}
	return ones;
} 
