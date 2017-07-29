#include <bits/stdc++.h>
#define ii pair<int,int>
#define mx 1000001  // 10^6 +1
using namespace std;


int main()
{
        int n,m;
        scanf("%d %d",&n,&m);
        priority_queue<ii> pq;
        vector<ii>::iterator it;
        vector<vector<ii > > t(n+1);
        vector<int> di(n+1,mx);
        int s;
        while(m--)
        {
            int a,b,w;
            scanf("%d%d%d",&a,&b,&w);
            t[a].push_back(make_pair(b,w));
            t[b].push_back(make_pair(a,w));
        }
        scanf("%d",&s);
        di[s]=0;
        pq.push(make_pair(0,s));
        while (!pq.empty())
        {
            ii top = pq.top();
            pq.pop();
            int d = top.first, u = top.second;
                for(it=t[u].begin(); it!=t[u].end(); it++)
                {
                    if (di[u] + (it->second)< di[it->first])
                    {
                        di[it->first] = di[u] + it->second;
                        pq.push(make_pair(di[it->first], it->first));
                    }
                }
        }
        for(int i=0; i<n; i++)
        {
            if(i+1!=s)
            {
                if(di[i+1]==mx)
                {
                    di[i+1]=-1;
                }
                cout<<di[i+1]<<" ";
            }
        }
        cout<<endl;
    return 0;
}

