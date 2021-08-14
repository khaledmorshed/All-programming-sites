#include <bits/stdc++.h>
#define LIM 100005
#define INF 1000000000012LL
#define ll long long int


using namespace std;

struct info {
    int x;
    ll y;
    info() {}
    info(int xx, ll yy) {
        x = xx; y = yy;
    }
};

///operator overloading
bool operator < (const info &a, const info &b) {
    return a.y > b.y;
}

int n,m;
vector<vector<int>> G, W;
ll dis[LIM];

ll dij(int s, int t) {
    priority_queue<info> pq;
    pq.push({s, 0});
//    memset(dis, 127, sizeof dis);
    for(int u=0; u<n; u++) dis[u] = INF;
    dis[s] = 0;

    while(!pq.empty()) {
        info U = pq.top();
        pq.pop();
        int u = U.x;
        ll c = U.y;

        if(c > dis[u]) continue;

        for(int i=0; i<G[u].size(); i++) {
            int v = G[u][i];
            int w = W[u][i];
            if(c+w < dis[v]) {
                dis[v] = c+w;
                pq.push({v, dis[v]});
            }
        }
    }

    return dis[t];
}

int main() {
    scanf("%d %d", &n, &m);
    G.clear();
    G.resize(n);
    W.clear();
    W.resize(n);
    for(int i=0; i<m; i++) {
        int u,v,w;
        cin >> u >> v >> w;
//        G[u].push_back({v,w});
//        G[v].push_back({u,w});
        G[u].push_back(v); W[u].push_back(w);
        G[v].push_back(u); W[v].push_back(w);
    }

    int s,t;
    cin >> s >> t;
    cout << dij(s, t) << endl;
}
