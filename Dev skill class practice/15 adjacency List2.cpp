#include<bits/stdc++.h>
#define LIM 1003
using namespace std;

int n, m, q;
vector<vector<int>> g;
//vector<int> g[LIM];
int visit[LIM], par[LIM];

void dfs(int u, int p){

    visit[u] = 1;
    par[u] = p;
    for(int i=0; i<g[u].size(); i++){
        int v = g[u][i];
        if(!visit[v]){
            //cout<<v<<endl;
            dfs(v, p);
        }
    }

}

int main()
{
    cin>>n>>m>>q;
    g.resize(n+1);

    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    //dfs(1);
    int comp = 0;
    for(int u=0; u<n; u++){
        if(!visit[u]){
            comp++;
            dfs(u, u);
        }
    }

    cout<<"Component = "<<comp<<endl;


    cout<<endl<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<g[i].size(); j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }

}
