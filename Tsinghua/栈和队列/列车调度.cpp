#include<cstdio>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int *s = new int[m+1];
	s[0] = -1000;//s表示栈，-1000作为哨兵 
	int sdx = 1;
	int *b = new int[n]; 
	for(int i=0;i<n;i++)
	{
		scanf("%d",&b[i]);//使用cin cout会大量re 
	}
	int k = 0;
	int odx = 0;//order-index 
	int *order=new int[2*n+1];//用来存储插入栈操作，如果用string存储也会大量re 
	s[sdx++] = 1;//往s中加入最早的1 
	order[odx++]=1;
	int a = 2; 
	while(true)
	{
		if(b[k]!=s[sdx-1]) 
		{
			if(a>n) break;
			s[sdx++]=(a++);
			order[odx++]=1;
		}
		if(b[k]==s[sdx-1])
		{
			k++;
			sdx--;
			order[odx++]=0;
		}
		if(sdx==m+1||k==n) break;
	}
	if(s[sdx-1]==-1000)
	{
		for(int i=0;i<odx;i++)
		{
			if(order[i]==1)
			{
				printf("push\n");
			}else{
				printf("pop\n");
			}
		}
	}else{
		cout<<"No"<<endl;
	}
	delete []b; 
}

/*很多坑，改了两个小时才ac，刚开始只有15分，自己手写stack模板类用来存储数据，vector模板类成员为string，
用来存出入栈操作，并且把No打印成了NO，输入输出全使用cincout
第一次更改，把NO改成No，15上升到25分，第二次更改，将stack模板类更改为普通数组，25上升到80分，第三次更改
vector模板类更改为int数组，使用01表示出入，85分，第四次更改，将cincout替换为scanf printf，成功ac*/ 
