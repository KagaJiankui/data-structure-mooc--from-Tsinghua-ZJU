int LCS(string a,string b)
{
	if(a.length()==0||b.length()==0) return 0;
	if(a[a.length()-1]==b[b.length()-1])
	{
		return LCS(a.substr(0,a.length()-1),b.substr(0,b.length()-1))+1;	
	}
	else{
		return max(LCS(a.substr(0,a.length()-1),b),LCS(a,b.substr(0,b.length()-1)));
	}
}
