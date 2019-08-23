int fib(int n,int& prev)
{
	if(n==0) {
		prev = 1;
		return 0;
	}else{
		int prevPrev=0;
		prev = fib(n-1,prevPrev);
		return prevPrev+prev;
	}
}
