
#include<bits/stdc++.h>
#define LIM 10004

using namespace std;
vector<vector<int>> g;
int vis[LIM], dis1[LIM], dis2[LIM];
int t = 1;

void bfs(int s, int d)
{
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dis1[s] = 0;
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
                dis1[v] = dis1[u] + 1;
                q.push(v);
            }
        }
    }
}

void bfs2(int s, int d)
{
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dis2[s] = 0;
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
                dis2[v] = dis2[u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){

    int T, N, R;
    cin>>T;
    while(T--){
        g.clear();
        cin>>N;
        g.resize(N+1);
        cin>>R;
        for(int i=0; i<R; i++){
            int u, v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        memset(vis, 0, sizeof vis);
        memset(dis1, 0, sizeof dis1);
        int s, d;
        cin>>s>>d;
        bfs(s, d);
        memset(vis, 0, sizeof vis);
        memset(dis2, 0, sizeof dis2);
        bfs2(d, s);
        int value, max_value, temp = 0;
        for(int i=0; i<N; i++){
             value = dis1[i]+dis2[i];
             max_value = max(value, temp);
             temp = max_value;
        }
        cout<<"Case "<<t++<<": "<<max_value<<endl;
    }
}
