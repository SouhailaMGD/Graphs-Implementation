#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii; 
typedef vector<ii> vii;
void dfs(int u,vector<int> &t,vector<vii> y)
{
    cout<<u<<" ";
    t[u]=1;
    for (vii::iterator it = y[u].begin(); it != y[u].end(); it++)
    {
        if(t[it->first]==0)
            dfs(it->first,t,y);
     }
}
int main() {
    
        int n,m,v1,v2,w;
        cin>>n>>m;
        vector<vii> y(n+1);
        vector<int> visited(n+1);
        for(int j=0;j<m;j++)
        {
            cin>>v1>>v2>>w;
            y[v1].push_back(make_pair(v2,w));
            y[v2].push_back(make_pair(v1,w));
        }
        dfs(1,visited,y);
    return 0;
}

