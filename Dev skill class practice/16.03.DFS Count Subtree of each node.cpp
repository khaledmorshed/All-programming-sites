
#include<bits/stdc++.h>
#define LIM 1003
using namespace std;

int n, m;
int k = 0;
vector<vector<int>> g;
//vector<int> g[LIM];
int visit[LIM], sub[LIM];

int dfs(int u){
    visit[u] = 1;
    sub[u] = 1;
    //cout<<"u = "<<u<<endl;
    for(int i=0; i<g[u].size(); i++){
        int v = g[u][i];
        if(!visit[v]){
            //cout<<"V = "<<v<<endl;
            dfs(v);
            //getchar();
            sub[u] = sub[u] + sub[v];
            // cout<<"U = "<<u<<" V = "<<v<<" sub = "<<sub[u]<<endl;

        }
    }
    /*20 12
1 2 1 3 2 4 2 5 3 6 3 7 3 15 3 20 20 11 20 12 13 14 13 16
    */
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

    for(int u=1; u<n; u++){
        if(!visit[u]){
            dfs(u);
        }
    }

    cout<<"Subtree = "<<sub[13]<<endl;

}
