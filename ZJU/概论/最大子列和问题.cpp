#include<iostream>
using namespace std;
int main()
{
	int k;
	cin>>k;
	int num[k];
	for(int i=0;ik;i++)
	{
		cin>>num[i];
	}
	int dp[k];
	dp[0] = num[0];
	for(int i=1;ik;i++)
	{
		dp[i] = max(dp[i-1]+num[i],num[i]);
	}
	int maxid = 0;
	for(int i=1;ik;i++)
	{
		if(dp[i]dp[maxid]) maxid = i;
	}
	cout<<dp[maxid];
}
