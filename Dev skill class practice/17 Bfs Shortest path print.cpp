#include<bits/stdc++.h>
#define LIM 1003

using namespace std;
int n, m;
vector<vector<int>> g;
int vis[LIM], dis[LIM], par[LIM];

void bfs(int s, int t)
{
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    par[s] = -1;

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
                par[v] = u;
                q.push(v);
            }
        }
    }

    if(vis[t])
    {
        cout<<"Shortest path of "<<s<<" to "<<t<<" = "<<dis[t]<<endl;
        vector<int> path;
        while(t != -1)
        {
            path.push_back(t);
            t = par[t];
        }
        reverse(path.begin(), path.end());

        /*for(auto it = path.begin(); it!=path.end(); it++){
            cout<<*it<<endl;
        }*/

        int space = 0;
        for(int u : path)
        {
            if(space) cout<<" ";
            cout<<u;
            space = 1;
        }
        cout<<endl;
    }
    else
    {
        cout<<"there is no connection between "<<s<<" and "<<t<<endl;
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



    while(1)
    {
        int s, t;
        cout<<"enter source and destination(0 0 exit) : ";
        cin>>s>>t;
        if(s == 0 && t == 0) break;
        memset(vis, 0, sizeof vis);
        memset(dis, 0, sizeof dis);
        bfs(s, t);
    }


}


/**
14 16
1 2
1 3
1 4
1 10
2 11
2 3
2 5
2 6
3 7
4 8
4 9
4 10
5 12
5 13
5 14
6 7
*/
