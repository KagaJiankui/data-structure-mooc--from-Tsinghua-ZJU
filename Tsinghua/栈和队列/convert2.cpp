void convert(Stack<char>&S,int n,int base)
{
	static char digit[]= { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
 	while(0<n)
 	{
 		int remainder=(int)(n%base);
 		S.push(remainder);
 		n/=base;
 		
	 }
} 
 
