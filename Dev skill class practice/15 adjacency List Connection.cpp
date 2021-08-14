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
    for(int u=1; u<=n; u++)
    {
        for(int j=0; j<g[u].size(); j++)
        {
            int v = g[u][j];
            if(!visit[v])
            {
                comp++;
                dfs(u, u);
            }
        }

    }

    cout<<"Component = "<<comp<<endl;

    while(q--){
        int u, v;
        cin>>u>>v;
        if(par[u] == par[v]){
            cout<<"Connected"<<endl;
        }
        else cout<<"Not connected"<<endl;
    }

    /*cout<<endl<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<g[i].size(); j++)
        {
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }*/

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

20 8
1 2
1 3
2 4
2 5
3 6
3 7
3 15
3 20
*/
