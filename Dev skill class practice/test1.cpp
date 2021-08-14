#include <bits/stdc++.h>
#define LIM 1003

using namespace std;

int n, m;
vector<vector<int>> G;
int vis[LIM], par[LIM], lev[LIM], countAtLevel[LIM], sub[LIM];
int iscycle = 0;
/// vector<int> G[LIM]

void dfs(int u) {
//    cout << "in " << u << endl;
//void dfs(int u, int l) {
    vis[u] = 1;
//    lev[u] = l;
    sub[u] = 1;
    for(int i=0; i<G[u].size(); i++) {
        int v = G[u][i];
        if(!vis[v]) {
            par[v] = u;
            lev[v] = lev[u]+1;
            dfs(v);
            sub[u] += sub[v];
//            dfs(v, l+1);
        }
    }
}

int main() {
    cin >> n >> m;
    G.resize(n+1);

    for(int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    for(int u=1; u<=n; u++) {
        if(!vis[u]) {
            lev[u] = 1;
            dfs(u);
//            dfs(u, 1);
        }
    }

    memset(countAtLevel, 0, sizeof countAtLevel);
    for(int u=1; u<=n; u++) {
        countAtLevel[lev[u]]++;
    }

    cout<<endl<<endl<<countAtLevel[1]<<endl;
    cout<<countAtLevel[2]<<endl;
    cout<<countAtLevel[3]<<endl;

}
