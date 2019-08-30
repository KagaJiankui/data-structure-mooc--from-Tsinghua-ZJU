#include<iostream>
#include<vector>
using namespace std;
struct Queen{
	int x,y;
	Queen(int xx=0,int yy=0):x(xx),y(yy){
	};
	bool operator==(Queen const&q) const{
		return (x==q.x)||y==q.y||(x+y==q.x+q.y)||x-y==q.x-q.y;	
	}
	bool operator!=(Queen const&q) const{return !(*this==q);}
};
void placeQueens(int N)
{
	vector<Queen> solu;
	Queen q(0,0);
	do{
		if(N<=solu.size()||N<=q.y)
		{
			q = solu.top();
			solu.pop();
			q.y++;
		}else{
			while(q.y<N&&(solu.find(q)>=0))
			{
				q.y++;
				nCheck++; 
			}
			if(n>q.y){
				solu.push(q);
				if(n<=solu.size()) nSolution++;
				q.x++;
				q.y=0;
			}
		}
	}while(q.x>0||q.y<n);
} 
