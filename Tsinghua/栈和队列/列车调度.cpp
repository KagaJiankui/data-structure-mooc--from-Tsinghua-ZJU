#include<cstdio>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	int *s = new int[m+1];
	s[0] = -1000;//s��ʾջ��-1000��Ϊ�ڱ� 
	int sdx = 1;
	int *b = new int[n]; 
	for(int i=0;i<n;i++)
	{
		scanf("%d",&b[i]);//ʹ��cin cout�����re 
	}
	int k = 0;
	int odx = 0;//order-index 
	int *order=new int[2*n+1];//�����洢����ջ�����������string�洢Ҳ�����re 
	s[sdx++] = 1;//��s�м��������1 
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

/*�ܶ�ӣ���������Сʱ��ac���տ�ʼֻ��15�֣��Լ���дstackģ���������洢���ݣ�vectorģ�����ԱΪstring��
���������ջ���������Ұ�No��ӡ����NO���������ȫʹ��cincout
��һ�θ��ģ���NO�ĳ�No��15������25�֣��ڶ��θ��ģ���stackģ�������Ϊ��ͨ���飬25������80�֣������θ���
vectorģ�������Ϊint���飬ʹ��01��ʾ���룬85�֣����Ĵθ��ģ���cincout�滻Ϊscanf printf���ɹ�ac*/ 
