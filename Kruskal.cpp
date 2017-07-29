#include <bits/stdc++.h>
#define  inf 1000001
using namespace std;
vector< pair<int,pair<int,int> > > m;
vector<int> visited;
vector<int> parent;
vector<pair<int,pair<int,int> > >::iterator it;
int cm=0;
int finds(int x)
{
    return parent[x]==x?x:parent[x]=finds(parent[x]);
}
int main()
{
        int n,q;
        scanf("%d%d",&n,&q);
        m.clear();
        parent.clear();
        parent.resize(n+1);
        for(int i=0;i<q;i++)
        {
            int x,y,c;
            scanf("%d%d%d",&x,&y,&c);
            m.push_back(make_pair(c,make_pair(x,y)));
        }
        sort(m.begin(),m.end());
        for(int i=1;i<=n;i++)
            parent[i]=i;
        it=m.begin();
        while(it!=m.end())
        {
            int a=finds((*it).second.first);
            int b=finds((*it).second.second);
            if(a!=b)
               {
            parent[a]=b;
            cm+=(*it).first;
            }
            it++;
        }
        printf("%d\n",cm);
    return 0;
}

