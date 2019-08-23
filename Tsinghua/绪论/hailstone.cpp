int hailstone(int n)
{
	if(n<=1) return 1;
	else if(n%2==0) return (1+hailstone(n/2));
	else return (1+hailstone(3*n+1));
}
int hailstone(int n)
{
	int length = 1;
	while(n>1)
	{
		n%2?n=3*n+1:n/=2;
		length++;
	}
	return length;
}

