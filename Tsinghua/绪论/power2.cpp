inline int sqr(int a) {return a*a};
int pow2(int n)
{
	if(n==0) return 1;
	return (n&1)?sqr(pow2(n>>1))<<1:sqr(pow2(n>>1));
}
