#include <bits/stdc++.h>

using namespace std;
void bfs(int n,vector<vector<int> > t,vector<int> &p)
{
    queue<int> q;
    q.push(n);
    p[n]=1;
    while(!q.empty())
    {
        int y=q.front();
        cout<<y<<endl;//breadth first traversal
        q.pop();
        for(vector<int>::iterator it=t[y].begin() ; it!=t[y].end(); it++)
        {
            if(p[*it]!=1)
            {
                p[*it]=1;//marking the node as visited
                q.push(*it);
            }
        }
    }
}
int main()
{
        int n,m,starting;
        cin>>n>>m;
        vector< vector<int> > t(n+1);
        vector<int> p(n+1);//visited /unvisited
        for(int j=0; j<m; j++)
        {
            int u,v;
            cin>>u>>v;
            t[u].push_back(v);
            t[v].push_back(u);
        }
        cin>>starting;// starting point
        bfs(starting,t,p);
        p.clear();
        return 0;
}
