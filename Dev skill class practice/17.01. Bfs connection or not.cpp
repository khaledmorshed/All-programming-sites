#include<bits/stdc++.h>
#define LIM 1003

using namespace std;
int n, m, qury;
vector<vector<int>> g;
int vis[LIM], dis[LIM], par[LIM];

void bfs(int s, int p){

    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;
    par[s] = p;

    while(!q.empty()){
        int u = q.front();
        q.pop();

        for(int i=0; i<g[u].size(); i++){
            int v = g[u][i];
            if(!vis[v]){
                vis[v] = 1;
                dis[v] = dis[u] + 1;
                par[v] = p;
                q.push(v);
            }
        }
    }

}

int main(){

    cin>>n>>m>>qury;
    g.resize(n+1);
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    memset(vis, 0, sizeof vis);
    int comp = 0;
    for(int u=1; u<=n; u++){
        if(!vis[u]){
            bfs(u, u);
        }
    }

    while(qury--){
        int u, v;
        cout<<"enter a query : ";
        cin>>u>>v;
        if(par[u] == par[v]){
            cout<<"Connected"<<endl;
        }
        else cout<<"Not connected"<<endl;
    }
}


/**
20 12 3
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

