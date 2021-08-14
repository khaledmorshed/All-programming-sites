#include<bits/stdc++.h>
#define LIM 1003
using namespace std;

int n, m;
int k = 0;
vector<vector<int>> g;
//vector<int> g[LIM];
int visit[LIM],level[LIM], countAtLevel[LIM];

int dfs(int u){
    visit[u] = 1;
    for(int i=0; i<g[u].size(); i++){
        int v = g[u][i];
        if(!visit[v]){
            level[v] = level[u] + 1;
            dfs(v);
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

    for(int u=1; u<n; u++){
        if(!visit[u]){
            level[u] = 1;
            dfs(u);
        }
    }

    memset(countAtLevel, 0, sizeof countAtLevel);

    for(int u = 1; u<=n; u++){
        //cout<<"U = "<<u<<endl;
        //cout<<"level = "<<level[u]<<endl;
        countAtLevel[level[u]]++;
        //cout<<"Count = "<<countAtLevel[level[u]]<<endl<<endl;
    }
    int q;
    cout<<"enter node number : ";
    cin>>q;
    cout<<endl<<endl<<countAtLevel[level[q]]<<endl;
    /*cout<<countAtLevel[2]<<endl;
    cout<<countAtLevel[3]<<endl;

    // count of cousines at each node here 3 is node number
    cout<<countAtLevel[level[3]]<<endl;*/

    /*cout<<endl<<endl<<level[1]<<endl;
    cout<<level[2]<<endl;
    cout<<level[3]<<endl;*/
}
