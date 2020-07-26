#include "union_find.h"
using namespace std;



UnionFind::UnionFind(int s)
{
    id.resize(s);
    sz.resize(s);
    for(int i=0;i<id.capacity();i++)
    {
        id[i]=i;
        sz[i]=1;
    }
    nc=s;
}

int UnionFind::find(int x)
{
    int root=x,next;
    while(id[root]!=root)
        root=id[root];
    
    while(x!=root)
    {
        next = id[x];
        id[x]=root;
        x=next;
    }
    return root;
}

bool UnionFind::connected(int x,int y)
{
    return find(x) == find(y);
}

int UnionFind::compSize(int x)
{
    return sz[find(x)];
}

bool UnionFind::unify(int x,int y)
{
    int r1=find(x);
    int r2=find(y);
    if(r1==r2)
        return false;
    if(sz[r1]<sz[r2])
    {
        sz[r2]+=sz[r1];
        id[r1]=r2;
    }
    else
    {
        sz[r1]+=sz[r2];
        id[r2]=r1;
    }
    nc--;
    return true;          
}

int UnionFind::compCount()
{
    return nc;
}

void UnionFind::disp()
{
    for(int i=0;i<id.size();i++)
        cout<<i<<" "<<id[i]<<endl;
}

