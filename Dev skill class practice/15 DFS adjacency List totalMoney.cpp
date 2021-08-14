

#include<bits/stdc++.h>
#define LIM 1003
using namespace std;

int n, m;
int k = 0;
vector<vector<int>> g;
//vector<int> g[LIM];
int value[LIM], visit[LIM];

int dfs(int u){
    visit[u] = 1;
    k++;
    int ans = value[u];
    for(int i=0; i<g[u].size(); i++){
        int v = g[u][i];
        if(!visit[v]){
            ans = ans + dfs(v);
        }
    }
    return ans;
}

int main()
{
    cin>>n>>m;
    g.resize(n+1);
    for(int i=1; i<=n; i++) cin>>value[i];

    for(int i=0; i<m; i++)
    {
        int u, v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for(int u=1; u<n; u++){
        if(!visit[u]){
            //cout<<"each component's money = "<<dfs(u)<<endl;
            int total = dfs(u);
            cout<<"each component's total money = "<<total<<endl;
            cout<<"each component's average money = "<<total / k<<endl;
            k = 0;
        }
    }

}
