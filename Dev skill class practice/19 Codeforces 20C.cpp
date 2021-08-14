#include<bits/stdc++.h>
#define LIM 10004
#define INF 1000000000012LL
#define pii pair<int, int>
#define ll long long int

using namespace std;

//vector<vector<pii>> g;
vector<vector<int>>G,W;
ll dis[LIM], par[LIM];
bool vis[LIM];
int m, n;

struct info{
    int x;
    ll y;
    info(){}
    info(int xx, ll yy){
        x = xx;
        y = yy;
    }
};
//operator overloading
bool operator < (const info &a, const info &b){
    return a.y > b.y;
}

void dij(int s, int t){
    priority_queue<info> pq;
    pq.push({s, 0});
    for(int u=0; u<=n; u++) dis[u] = INF;
    dis[s] = 0;
    vis[s] = true;
    par[s] = -1;
    while(!pq.empty()){
        info U = pq.top();
        pq.pop();
        int u = U.x;
        ll c = U.y;
        vis[u] = true;
        if(c > dis[u]) continue;
        for(int i=0; i<G[u].size(); i++){
            int v = G[u][i];
            int w = W[u][i];
            if(!vis[v] && c+w < dis[v]){
                dis[v] = c+w;
                par[v] = u;
                pq.push({v, dis[v]});
            }
        }
    }
     if(vis[t])
    {
        vector<int> path;
        while(t != -1)
        {
            path.push_back(t);
            t = par[t];
        }
        reverse(path.begin(), path.end());
        int space = 0;
        for(int u : path)
        {
            if(space) cout<<" ";
            cout<<u;
            space = 1;
        }
        cout<<endl;
    }
    else
    {
        cout<<-1<<endl;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    G.clear();
    G.resize(n+1);
    W.clear();
    W.resize(n+1);
    for(int i=1; i<=m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        //g[u].push_back({v,w});
        //g[v].push_back({u.w});
        G[u].push_back(v); W[u].push_back(w);
        G[v].push_back(u); W[v].push_back(w);
    }
   dij(1,n);
}
/*
6 5
0 1 100
0 2 5
0 3 50
1 5 8
2 5 10
0 5
*/

/*
14 15
0 1 10
0 2 100
1 7 1000
2 3 2
3 4 2
4 5 2
5 6 2
6 7 2
7 8 2
7 9 4
8 11 5
8 10 6
9 12 50
10 13 3
12 13 7
0 13

*/
