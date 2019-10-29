#include<iostream>
#include<cstring>
using namespace std;
void buildnext(char *p,int *next)
{
    int len = strlen(p);
    next[0] = -1;
    for (int i = 1; i < len; i++)
    {
        int tmp = next[i-1];
        while (tmp>=0&&p[i]!=p[tmp+1])
        {
            tmp = next[tmp];
        }
        if(p[tmp+1]==p[i]) next[i+1] = next[i]+1;
        else next[i] = -1;
        
    }
}
int kmp(char *s,char *p)
{
    n = strlen(s);
    m = strlen(p);
    int *next = new int[m];
    buildnext(p,next);
    int i=0,j=0;
    while (i<n&&j<m)
    {
        if(s[i]==p[j])
        {
            i++;
            j++;
        }else if(j>=1&&s[i]!=p[j])
        {
            j = next[j-1]+1;
        }else j++;
    }
    return (j==m)?(i-m):-1;
}