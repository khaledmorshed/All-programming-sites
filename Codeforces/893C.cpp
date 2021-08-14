#include<bits/stdc++.h>
#define LIM 100005
using namespace std;

int n, m;
vector<vector<int>> g;
//vector<int> g[LIM];
long long int val[LIM], vis[LIM];

int dfs(int u){
    vis[u] = 1;
    int ans = val[u];
    for(int i=0; i<g[u].size(); i++){
        int v = g[u][i];
        if(!vis[v]){
            ans = min(ans , dfs(v));
        }
    }
    return ans;
}

int main()
{
    cin>>n>>m;
    g.resize(n+1);
    for(int i=1; i<=n; i++) cin>>val[i];

    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    long long int ans = 0;
    for(int u=1; u<=n; u++){
        if(!vis[u]){
            ans+=dfs(u);
            cout<<"ans = "<<ans<<" u = "<<u<<endl;
        }
    }

    //cout<<ans<<endl;
    printf("%d\n", ans);
}

