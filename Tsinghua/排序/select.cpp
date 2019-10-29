#include<iostream>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int ar;
    int maj;
    for (size_t i = 0,c=0; i < n; i++)
    {
        scanf("%d",&ar);
        if(c==0)
        {
            maj=ar;
            c++;
        }else if(maj!=ar) c--;
        else c++;
    }
    cout<<maj<<endl;    
}