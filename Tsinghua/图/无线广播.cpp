#include<iostream>
#include<queue>
using namespace std;
char g[10000][10000];
bool flag=1;
queue<int> que;
int n,m;
bool hashmap[10000];
bool discovered[10000];
void bfs(int key)
{
    que.push(key);
    discovered[key]=1;
    while(!que.empty())
    {
        int j = que.front();
    	hashmap[j]=1;
        que.pop();
        for(int i=0 ;i<n;i++)
        {
            if(g[j][i]==1)
            {
                if(hashmap[i]==0&&discovered[i]==1)
				{
					flag=0;
					return;
				}else if(hashmap[i]==0&&discovered[i]==0)
				{
					que.push(i);
					discovered[i]=1;
				} 
                
            }
        }
    }
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        g[a-1][b-1] = 1;
        g[b-1][a-1]=1;
    }
    bfs(0);
    if(flag==1) printf("1\n");
    else printf("-1\n");
}
