#include<bits/stdc++.h>
#define N 2*10004
#define INF 10000000010LL
#define ll long long int
using namespace std;

vector<vector<int>> g;
vector<vector<int>> W;
ll dis[N];
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

ll dijsktra(int s, int t){
    priority_queue<info> pq;
    pq.push({s, 0});;
    for(int i=0; i<N; i++){
        dis[i] = INF;
    }
    dis[s] = 0;

    while(!pq.empty()){
        info top = pq.top();
        pq.pop();
        int u = top.x;
        ll c = top.y;
        if(c > dis[u]) continue;

        for(int i=0; i<g[u].size(); i++){
            int v = g[u][i];
            ll w = W[u][i];
            if(c+w < dis[v]){
                dis[v] = c+w;
                pq.push({v, dis[v]});
            }
        }
    }
    return dis[t];
}

int main(){
    int T;
    cin>>T;

    for(int t=1; t<=T; t++){
        g.clear();
        g.resize(N);
        W.clear();
        W.resize(N);
        int n, m, s, d;
        cin>>n>>m>>s>>d;
        for(int i=0; i<m; i++){
            int u, v, w;
            cin>>u>>v>>w;
            g[u].push_back(v); W[u].push_back(w);
            g[v].push_back(u); W[v].push_back(w);
        }

        ll res = dijsktra(s,d);
        res < INF ? cout<<"Case #"<<t<<": "<<res<<endl : cout<<"Case #"<<t<<": "<<"unreachable"<<endl;
    }
}
