#include<bits/stdc++.h>
#define LIM 10004
using namespace std;

int n, m;
int k = 0;
vector<vector<int>> g;
//vector<int> g[LIM];
int vis[LIM], color[LIM];
int isBicolor = 0;

void dfs(int u)
{
    vis[u] = 1;
    //cout<<"u = "<<u<<endl;
    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];
        if(!vis[v])
        {

            //color[v] = !color[u];
            //color[v] = 1 - color[u];
            //color[v] = color[u]? 0 : 1;

            if(color[u] == 0) color[v] = 1;
            else color[v] = 0;

            dfs(v);
        }

        else if(color[u] == color[v])
        {
            isBicolor  = 1;
            break;
        }
    }

}

int main()
{

    while(cin>>n, n != 0)
    {

        cin>>m;
        g.clear();
        g.resize(n+2);

        memset(vis, 0, sizeof vis);
        memset(color, 0, sizeof color);

        for(int i=0; i<m; i++)
        {
            int u, v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for(int u=1; u<=n; u++)
        {
            if(!vis[u])
            {
                color[u] = 0;
                dfs(u);
            }
            else if(isBicolor == 1) break;
        }

        if(isBicolor == 0) cout<<"BICOLORABLE."<<endl;
        else cout<<"NOT BICOLORABLE."<<endl;
        isBicolor = 0;
    }

}
