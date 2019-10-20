#include<cstdio>
#include<iostream>
#include<cstring>
const long long INF = (long long)1 << 32;    
using namespace std;
struct mis
{
    long long int index;
    char name[9];
    bool operator<(const mis& a)
    {
        if(index!=a.index) return index>a.index;
        else return (strcmp(name,a.name)>0);
    }
    bool operator>(const mis&a)
    {
        if(index!=a.index) return index<a.index;
        else return (strcmp(name,a.name)<0);
    }
};
class heap
{
    private:
        mis *_elem;
        int _size;
        int cap;
        void precDown(int k,int n);
        void precUp(int n);
    public:
        mis delMax();
        mis getMax(){return _elem[0];}
        bool empty(){return _size==0;}
        void insert(mis e);
        heap(int c)
        {
            cap = c;
            _size = 0;
            _elem = new mis[c];
        }
};
void heap::insert(mis e)
{
    _elem[_size++] = e;
    precUp(_size-1);
}
void heap::precUp(int n)
{
    while((n-1)/2>=0)
    {
        int p = (n-1)/2;
        if(_elem[p]<_elem[n])
        {
            swap(_elem[p],_elem[n]);
            n= p;
        }else break;
    }
}
mis heap::delMax()
{
    mis max =_elem[0];
    _elem[0] = _elem[--_size];
    precDown(0,_size-1);
    return max;
}
void heap::precDown(int k,int n)
{
    while (true)
    {
        if(k*2+1>n) break;
        else if((k+1)*2>n)
        {
            if(_elem[k]<_elem[(k*2)+1])
            {
                swap(_elem[k],_elem[k*2+1]);
                k  = k*2+1;
            }else
            {
                break;
            }
        }else
        {
            int j;
            if(_elem[k*2+1]>_elem[(k+1)*2])
            {
                j = k*2+1;
            }else
            {
                j = (k+1)*2;
            }
            if(_elem[k]<_elem[j])
            {
            	swap(_elem[k],_elem[j]);
            	k = j;
			}else{
				break;
			}
        }
    }
}

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    heap que(n);
    for (size_t i = 0; i < n; i++)
    {
        mis tmp;
        scanf("%lld %s",&tmp.index,&tmp.name);
        que.insert(tmp);
    }
    if(n==0) return 0;
    for (size_t i = 0; i < m; i++)
    {
        mis tmp = que.delMax();
        printf("%s\n",tmp.name);
        tmp.index = tmp.index*2;
        if(tmp.index<INF)
        que.insert(tmp);
        if(que.empty()) break;
    }
}
