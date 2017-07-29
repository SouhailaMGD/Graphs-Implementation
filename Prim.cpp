#include <bits/stdc++.h>
#define  inf 1000001
using namespace std;
vector<vector<pair<int,int> > > m;
vector<int> visited;
vector<int> key;
vector<pair<int,int> >::iterator it;
int cm=0;
int min_key(int n)
{
  int min_ky=0;
  key[0]=inf;
  for(int i=1; i<=n; i++)
  {
      if(visited[i]==false && key[i]<key[min_ky])
          min_ky=i;
  }
  cm+=key[min_ky];
  return min_ky;
}
void prim(int h,int n)
{
  key[h]=0;
  for(int i=1; i<=n; i++)
  {
      int u=min_key(n);
      visited[u]=true;
      for(it=m[u].begin(); it!=m[u].end(); it++)
      {
          if(visited[it->first]==false && key[it->first]>it->second)
              key[it->first]=it->second;
      }
  }
}
int main()
{

      cm=0;
      int n,q;
      scanf("%d%d",&n,&q);
      m.clear();
      m.resize(n+1);
      key.clear();
      key.resize(n+1);
      fill(key.begin(),key.end(),inf);
      visited.clear();
      visited.resize(n+1);
      fill(visited.begin(),visited.end(),0);
      while(q--)
      {
          int x,y,c;
          scanf("%d%d%d",&x,&y,&c);
          m[x].push_back(make_pair(y,c));
          m[y].push_back(make_pair(x,c));
      }
  int h;
  cin>>h;
      prim(h,n);
      printf("%d\n",cm);
  return 0;
}

