
#include<bits/stdc++.h>
#define LIM 1003

using namespace std;
int n, m;
vector<vector<int>> g;
int vis[LIM], dis[LIM], color[LIM];
int isBicolor = 0;

void bfs(int s)
{

    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    color[s] = 0;

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
                color[v] = !color[u];
                q.push(v);
            }

            else if(color[v] == color[u])
            {
                isBicolor = 1;
                break;
            }
        }
    }

}

int main()
{

    cin>>n>>m;
    g.resize(n+1);
    for(int i=0; i<n; i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(vis, 0, sizeof vis);
    for(int u=1; u<=n; u++)
    {
        if(!vis[u])
        {
            bfs(u);

        }
         else if(isBicolor == 1) break;
    }
    if(isBicolor == 0) cout<<"BICOLORABLE."<<endl;
    else cout<<"NOT BICOLORABLE."<<endl;

}


/**
20 12
1 2
1 3
2 4
2 5
3 6
3 7
3 15
3 20
20 11
20 12
13 14
13 16
*/
