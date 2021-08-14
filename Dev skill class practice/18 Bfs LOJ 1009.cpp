#include<bits/stdc++.h>
#define LIM 20004

using namespace std;
int n, m;
vector<vector<int>> g;
int vis[LIM], dis[LIM], color[LIM];
int t = 1;

int bfs(int s)
{
    if(!g[s].size()) return 0;
    queue<int> q;
    int vampire = 0, lykan = 0;
    q.push(s);
    vis[s] = 1;
    color[s] = 0;
    lykan = 1;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i];
            if(vis[v]==-1)
            {
                vis[v] = 1;
                if(color[u] == 0){
                    color[v] = 1;
                    ++vampire;
                }
                else{
                    color[v] = 0;
                    ++lykan;
                }
                q.push(v);
            }
        }
    }
    if(vampire >= lykan){
        return vampire;
    }
    else return lykan;
}

int main()
{
    int T, cnt , sum = 0, n;
    cin>>T;
    while(T--){
        sum = 0;
        cin>>n;
        int num = n;
        g.clear();
        g.resize(1000006);
        memset(vis, -1, sizeof vis);
        memset(dis, -1, sizeof dis);
        memset(color, -1, sizeof color);
        while(n--){
            int u, v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
         for(int node=1; node<=20000; node++){
            if(vis[node]==-1)
            {
                 cnt = bfs(node);
                 sum = sum + cnt;
            }
        }
        cout<<"Case "<<t++<<": "<<sum<<endl;
    }
}
