
#include<bits/stdc++.h>
#define LIM 1003

using namespace std;
int n, m;
vector<vector<int>> g;
int vis[LIM], dis[LIM], par[LIM], countAtLevel[LIM];

void bfs(int s)
{

    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i];
            if(!vis[v])
            {
                vis[v] = 1;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }

}

int main()
{

    cin>>n>>m;
    g.resize(n+1);
    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(vis, 0, sizeof vis);
    int comp = 0;
    for(int u=1; u<=n; u++)
    {
        if(!vis[u])
        {
            comp++;
            bfs(u);
        }
    }

    for(int u=1; u<=n; u++)
    {
        countAtLevel[dis[u]]++;
    }
    while(1)
    {
        int q;
        cout<<"enter node number : ";
        cin>>q;
        cout<<endl<<"number of node or cousin of "<<q<<" node is = "<<countAtLevel[dis[q]]<<endl;

        int level;
        cout<<"enter level number : ";
        cin>>level;
        cout<<"number of node of "<<level<<" level is = "<<countAtLevel[level]<<endl;
        cout<<"Component = "<<comp<<endl;
    }

}

/**
20 8
1 2
1 3
2 4
2 5
3 6
3 7
3 15
3 20
*/
