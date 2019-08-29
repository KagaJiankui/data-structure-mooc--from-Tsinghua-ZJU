void convert(Stack<char>&S,int n,int base)
{
	static char digit[] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	if(0<n)
	{
		convert(S,n/base,base);
		S.push(digit[n%base]);
	}
}
