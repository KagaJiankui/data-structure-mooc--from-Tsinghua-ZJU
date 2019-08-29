void trim(const char exp[],int &lo,int &hi)
{
	while((lo<=hi)&&(exp[lo]!='(')&&exp[lo]!=')') lo++;
	while((lo<=hi)&&(exp[hi]!='(')&&(exp[hi]!=')')) hi--;

}
int divide(const char exp[],int lo,int hi)
{
	int mi=lo;
	int crc=1;
	while((0<crc)&&(++mi<hi))
	{
		if(exp[mi]==')') crc--;
		if(exp[mi]=='(') crc++;
	}
	return mi;
 }
bool paren(const char exp[],int lo,int hi)
{
	trim(exp,lo,hi);
	if(lo>hi) return true;
	if(exp[lo]!='(') return false;
	if(exp[hi]!=')') return false;
	int mid = divide(exp,lo,mi);
	if(mi>hi) return false;
	return paren(exp,lo+1,mi-1)&&paren(exp,mi+1,hi-1);
}
