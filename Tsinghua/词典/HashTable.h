#include"Dictionary.h"
template<typename K,typename V>
class HashTable:public Dictionary<K,V>
{
    private:
        Entry<K,V>** ht;
        int M;
        int N;
        int *lazyRemoval;
    #define lazilyRemoved(x) (lazyRemoval[x] == 1)
    #define markAsRemoved(x) (lazyRemoval[x] = 1)
    protected:
        int probe4Hit(const K&k);
        int probe4Free(const K&k);
        void rehash();
public:
    HashTable(int c= 5);
    ~HashTable();
    int size() const {return N;}
    bool put(K,V);
    V* get(K k);
    bool remove(K k);
};
template<typename K,typename V>HashTable<K,V>::HashTable(int c=5)
{
    M = nextprime(c);//求不小于c的最大素数
    N = 0;
    ht = new Entry<K,V>*[M];
    memset(ht,0,sizeof(Entry<K,V>*)*M);
    lazyRemoval = new int[M];
}
template<typename K,typename V>HashTable<K,V>::~HashTable()
{
    for(int i=0;i<M;i++)
    {
        if(ht[i]) release(ht[i]);
    }
    release(ht);
    release(lazyRemoval);
}
template<typename K,typename V>V* HashTable<K,V>::get(K k)
{
    int r = probe4Hit(k);
    return ht[r]?&(ht[r]->value):NULL;
}
template<typename K,typename V>int HashTable<K,V>::probe4Hit(const K& k)
{
    int r = hashcode(K)%M;
    while((ht[r]&&(k!=(ht[r]->key))||(!ht[r]&&lazilyRemoved(r))))
        r = (r+1)%M;
    return r;
}
template<typename K,typename V>bool HashTable<K,V>::remove(K k)
{
    int r = probe4Hit(k);
    if(!ht[r]) return false;
    release(ht[r]);
    ht[r] = NULL;
    markAsRemoved(r);
    return true;
}
template<typename K,typename V>bool HashTable<K,V>::put(K k,V v)
{
    if(ht[probe4Hit(k)]) return false;
    int r = probe4Free(k);
    ht[r] = new Entry<K,V>(k,v); ++N;
    if(N*2>M) rehash();
    return true;
}
template<typename K,typename V> int HashTable<K,V>::probe4Free(const K& k)
{
    int r = hashCode(k);
    while(ht[r]) r = (r+1)%M;
    return r;
}
template<typename K,typename V>void HashTable<K,V>::rehash()
{
    int old_capacity = M;
    Entry<K,V>** old_ht = ht;
    M = nextprime(2*M);
    Entry<K,V>** old_ht = ht;
    N = 0;
    ht = new Entry<K,V>*[M];
    memset(ht,0,sizeof(Entry<K,V>*)*M);
    release(lazyRemoval);
    lazyRemoval = new int[M];
    for(int i=0;i<old_capacity;i++)
    {
        if(old_ht[i])
        {
            put(old_ht[i]->key,old_ht[i]->value);
        }
    }
    release(old_ht);
}
