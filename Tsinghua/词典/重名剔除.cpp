#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int nextprime(int n)
{
    bool flag = 0;
    for(int i=n;;i++)
    {
        flag=  0;
        for(int k=2;k<sqrt(i);k++)
        {
            if(i%k==0)
            {
                flag= 1;
                break;
            }
        }
        if(flag==0) return i;
    }
}
struct Entry
{
    char name[51];
    int cnt;
    Entry(){cnt=1;}    
};
class HashTable
{
    private:
        Entry* *ht;
        int M;
        long long int hashcode(char s[]);
        int get_free(int key);
        int search_ht(Entry* e,int key);
    public:
        HashTable(int c)
        {
            M = nextprime(c);
            ht = new Entry*[M];
            for(int i=0;i<M;i++) ht[i] = NULL;
        }
        void insert(Entry* e)
        {
            int key = hashcode(e->name)%M;
            int r = get_free(key);
            ht[r] = e;
        }
        Entry* search(Entry* e)
        {
            int key =hashcode(e->name)%M;
            int r = search_ht(e,key);
            if(r!=-1&&ht[r]) return ht[r];
            else return NULL;
        }
};
long long int HashTable::hashcode(char s[])
{
    long long int h  = 0;
    for(int n = strlen(s),i=0;i<n;i++)
    {
        h=(h<<5|(h>>27))%M;
        h+=(int)s[i];
    }
    return h;
}
int HashTable::get_free(int key)
{
    while(ht[key]) key=(key+1)%M;
    return key;
}
int HashTable::search_ht(Entry* e,int key)
{
    int q = key;
    while (ht[key]!=NULL&&strcmp(ht[key]->name,e->name)!=0)
    {
        key = (key+1)%M;
        if(key==q) return -1;
    }
    return key;
    
}

int main()
{
    int n;
    scanf("%d",&n);
    HashTable map(n);
    for(int i=0;i<n;i++)
    {
        Entry* tmp = new Entry;
        scanf("%s",tmp->name);
        if(Entry* q=map.search(tmp))
        {
            if(q->cnt==1) cout<<q->name<<endl;
            q->cnt++;
        }else
        {
            map.insert(tmp);
        }       
    }
}
