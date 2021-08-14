#include<bits/stdc++.h>
#define LIM 10004
#define INF 1000000000012LL
#define pii pair<int, int>
#define ll long long int

using namespace std;

struct info{// notun akta taype ei notun type er jonno "<" operator ta kemne kaj korbe ami seta bole dicci
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

//vector<vector<pii>> g;
vector<vector<int>>G,W;
ll dis[LIM];

int m, n;

ll dij(int s, int t){
    priority_queue<info> pq;//priority_queue<pii, vector<pii>, greater<pii>> pq; it is alternative code for above code like info, bool operator but it is not alternative because it only for x not y
    pq.push({s, 0});
    //memset(dis, 127, sizeof dis);
    for(int u=0; u<n; u++) dis[u] = INF;
    dis[s] = 0;
    while(!pq.empty()){
        info U = pq.top();
        pq.pop();
        int u = U.x;
        ll c = U.y;
        cout<<"u = "<<u<<" c = "<<c<<" dis[u] = "<<dis[u]<<endl;
        if(c > dis[u]) continue;
        for(int i=0; i<G[u].size(); i++){
            int v = G[u][i];
            int w = W[u][i];
            cout<<"v = "<<v<<" w = "<<w<<endl;
            if(c+w < dis[v]){
                dis[v] = c+w;
                cout<<"push v = "<<v<<" dis[v] = "<<dis[v]<<endl;
                pq.push({v, dis[v]});
            }
        }
        cout<<endl;
    }
    return dis[t];
}

int main(){
    scanf("%d %d", &n, &m);
    G.clear();
    G.resize(n+1);
    W.clear();
    W.resize(n+1);
    for(int i=0; i<m; i++){
        int u, v, w;
        cin>>u>>v>>w;
        //g[u].push_back({v,w});
        //g[v].push_back({u.w});
        G[u].push_back(v); W[u].push_back(w);
        G[v].push_back(u); W[v].push_back(w);
    }
    int s, t;
    cin>>s>>t;
    cout<<dij(s, t)<<endl;
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
