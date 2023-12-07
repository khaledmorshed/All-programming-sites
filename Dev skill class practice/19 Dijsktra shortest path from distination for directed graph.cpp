#include<bits/stdc++.h>
#define INF 100000000012LL
#define N 2*10004
#define ll long long int
#define LIM 10004
using namespace std;
struct info{
    int x;
    ll y;
    info(){}
    info(int xx, ll yy){
        x = xx; y = yy;
    }
};

bool operator < (const info &a, const info &b){
    return a.y > b.y;
}
vector<vector<int>> G, W;
ll dis[LIM], par[LIM];
bool vis[LIM];
int t = 1;
void dij(int s, int n){
    priority_queue<info> pq;
    pq.push({s, 0});
    for(int u=0; u<=N; u++) dis[u] = INF;
    dis[s] = 0;
    vis[s] = true;
    par[s] = -1;
    while(!pq.empty()){
        info top1 = pq.top();
        pq.pop();
        int u = top1.x;
        ll c = top1.y;
        vis[u] = true;
        if(c>dis[u]) continue;
        for(int i=0; i<G[u].size(); i++){
            int v = G[u][i];
            ll w = W[u][i];
            if(!vis[v] && max(c, w) < dis[v]){
                dis[v] = max(c, w);
                par[v] = u;
                pq.push({v, dis[v]});
            }
        }
    }
    if(vis[t])
    {
        cout<<"Shortest path of "<<s<<" to "<<t<<" = "<<dis[t]<<endl;
        vector<int> path;
        while(t != -1)
        {
            path.push_back(t);
            t = par[t];
            cout<<"t = "<<t<<endl;
        }
        reverse(path.begin(), path.end());

        /*for(auto it = path.begin(); it!=path.end(); it++){
            cout<<*it<<endl;
        }*/

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
        cout<<"there is no connection between "<<s<<" and "<<t<<endl;
    }
}

int main(){
    int T;
    cin>>T;
    while(T--){

        int n, m;
        cin>>n>>m;
        G.clear(); G.resize(n+1);
        W.clear(); W.resize(n+1);
        for(int i=0; i<m; i++){
            int u, v, w;
            cin>>u>>v>>w;
           // G[u].push_back(v); W[u].push_back(w);
            G[v].push_back(u); W[v].push_back(w);
        }
        memset(dis, 0, sizeof dis);
        int d;
        cin>>d;
        dij(d, n);
    }
}
