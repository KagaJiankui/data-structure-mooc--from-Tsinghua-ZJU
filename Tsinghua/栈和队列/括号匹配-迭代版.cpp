bool paren(const char exp[],int lo,int hi)
{
	stack<char> s;
	for(int i=lo;i<hi;i++)
	{
		if(exp[i]=='('||exp[i]==')')
		{
			if('('==exp[i]) s.push(exp[i]);
			else if(!s.empty()) s.pop();
			else return false;	
		}	
	}
	return s.empty();
 } 
