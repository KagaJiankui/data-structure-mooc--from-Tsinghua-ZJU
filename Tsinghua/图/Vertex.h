#include"Graph.h"
#include<vector>
#include<queue>
template<typename Tv>struct Vertex
{
	Tv data;
	int inDegree;
	int outDegree;
	int dTime,fTime;
	int parent;
	int priority;
	Vertex(Tv const&d = (Tv)0):
		data(d),inDegree(0),outDegree(0),status(UNDESCOVERED),dTime(-1),fTime(-1),parent(-1),priority(INT_MAX)
		{}
	
};
template<typename Te> struct Edge{
	Te data;
	int weight;
	EStatus status;
	Edge(Te const& d,int w):data(d),weight(w),status(UNDESCOVERED)
	{}	
};
template<typename Tv,typename Te> class GraphMatrix:public Graph<Tv,Te>
{
	private:
		vector<Vertex<Tv>> V;
		vector<vector<Edge<Te>*>> E;
	public:
		GraphMatrix(){n=e=0;}
		~GraphMatrix()
		{
			for(int j=0;j<n;j++)
			{
				for(int k=0;k<n;k++)
				{
					delete E[j][K];
				}
			}
		}
		virtual Tv& vertex(int i){return V[i].data()};
		virtual int inDegree(int i){return V[i].inDegree;}
		virtual int outDegree(int i){return V[i].outDegree;}
		virtual int firstNbr(int i) {return nextNbr(i,n);}
		virtual int nextNbr(int i,int j)
		{while(-1<j&&(!exists(i,--j)));return j;}
		virtual VStatus& status(int i){return V[i].status;}
		virtual int& dTime(int i){return V[i].dTime;}
		virtual int& fTime(int i){return V[i].fTime;}
		virtual int& parent(int i){return V[i].parent;}
		virtual int& priority(int i){return V[i].priority;}
		virtual int insert(Tv const& vertex)
		{
			for(int j=0;j<n;j++) E[j].insert(NULL);n++;
			E.insert(vector<Edge<Te>*>(n,n,(Edge<Te>*)NULL));
			return V.insert(Vertex<Tv>(vertex));
		}
		virtual Tv remove(int i)
		{
			for(int j=0;j<n;j++)
			{
				if(exists(i,j)){
					delete E[i][j];
					V[j].inDegree--;
	
				}
			}
			E.remove(i);
			n--;
			for(int j=0;j<n;j++)
			{
				if(exists(j,i))
				{
					delete E[j].remove(i);
					V[j].outDegree--;
				}
			}
			Tv vBak = vertex(i);
			V.remove(i);
			return vBak;
		}
		virtual bool exists(int i,int j)
		{
			return (0<=i&&i<n&&0<=j&&j<n&&E[i][j]!=NULL);
		}
		virtual EStatus& status(int i,int j){return E[i][j].status;}
		virtual Te& edge(int i,int j){return E[i][j].data};
		virtual int& weight(int i,int j){return E[i][j].weight;}
		virtual void insert(T const& edge,int w,int i,int j)
		{
			if(exists(i,j)) return;
			E[i][j] = new Edge<Te>(edge,w);
			e++;
			V[i].outDegree++;
			V[j].inDegree++;
		}
		virtual Te remove(int i,int j)
		{
			Te eBak = edge(i,j);
			delete E[i][j];
			E[i][j] = NULL;
			e--;
			V[i].outDegree--;
			V[j].inDegree--;
			return eBak;
		}
 }
template<typename T,typename Te>
void Graph<Tv,Te>::bfs(int s)
{
	reset();
	int clock = 0;
	int v = s;
	do{
		if(UNDISCOVERED==status(v))
			BFS(v,clock);
	}while(s!=(v=(++v%n)));
}
template<typename Tv,typename Te>
void Graph(Tv,Te)::BFS(int v,int &clock)
{
	queue<int> Q;
	status(v) = DISCOVERED;
	Q.enqueue(v);
	while(!Q.empty())
	{
		int v= Q.dequeue();
		dTime(v) = ++clock;
		for(int  u = firstNbr(v);-1<u;u=nextNbr(v,u))
		{
			if(UNDISCOVERED==status(u))
			{
				status(u) = DISCOVERED;
				Q.enqueue(u);
				status(v,u) = TREE;
				parent(u) = v;
			}else{
				status(v,u) = CROSS;
			}
		}
		status(V) = VISITED;
	}
}
template<typename Tv,typename Te> void Graph<Tv,Te>::dfs(int s)
{
	reset();
	int clock =0;
	int v = s;
	do{
		if(UNDISCOVERED==status(v))
		{
			DFS(v,clock);
		}
	}while(s!=(v=(++v%n)));
}
template<typename Tv,typename Te>
void Graph<Tv,Te>::DFS(int v,int &clock)
{
	dTime(v) = ++clock;
	status(v) = DISCOVERED;
	for(int u=firstNbr(v);-1<u;u=nextNbr(v,u))
	{
		switch(status(u))
		{
			case UNDISCOVERED:
				status(v,u) = TREE;
				parent(u) = v;
				DFS(u,clock);
				break;
			case DISCOVERED:
				status(v,u) = BACKWARD;
				break;
			default:
				status(v,u) = (dTime(v)<dTime(u))?FORWARD:CROSS;
				break;
		}
	}
	status(v) = VISITED;
	fTime(v) = ++clock;
}
