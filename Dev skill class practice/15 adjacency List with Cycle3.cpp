
#include<bits/stdc++.h>
#define LIM 1003
using namespace std;

int n, m;
vector<vector<int>> g;
//vector<int> g[LIM];
int visit[LIM], par[LIM];
int cycle=0;

void dfs(int u){
    visit[u] = 1;
    for(int i=0; i<g[u].size(); i++){
        int v = g[u][i];
        if(!visit[v]){
            par[v] = u;
            dfs(v);
        }
        else if(par[u] != v){
            cycle=1;
            break;
            //cout<<endl<<"par = "<<par[u]<<" "<<v<<endl;
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

    int comp = 0;
    for(int u=0; u<n; u++){
        if(!visit[u]){
            dfs(u);
        }
    }

    if(cycle) cout<<"Cycle yes"<<endl;
    else cout<<"Cycle Not"<<endl;

}
