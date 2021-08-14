#include<bits/stdc++.h>
#define LIM 100005
#define INF 1000000000012LL
#define pii pair<int, int>
#define ll long long int

using namespace std;

struct info
{
    int x;
    ll y;
    info() {}
    info(int xx, ll yy)
    {
        x = xx;
        y = yy;
    }
};
//operator overloading
bool operator < (const info &a, const info &b)
{
    return a.y > b.y;
}

//vector<vector<pii>> g;
vector<vector<int>>G,W;
ll dis[LIM], dis2[LIM];

int m, n, t= 1;

void dij(int s)
{
    priority_queue<info> pq;
    pq.push({s, 0});
    //memset(dis, 127, sizeof dis);
    for(int u=1; u<=n; u++)
    {
        dis[u] = INF;
        dis2[u] = INF;
    }
    dis[s] = 0;
    dis2[s] = INF;
    while(!pq.empty())
    {
        info U = pq.top();
        pq.pop();
        int u = U.x;
        ll c = U.y;
        for(int i=0; i<G[u].size(); i++)
        {
            int v = G[u][i];
            int w = W[u][i];
            if(c+w < dis[v])
            {
                dis2[v] = dis[v];
                dis[v] = c+w;
                pq.push({v, dis[v]});
            }
            else if(c+w == dis[v]){

            }
            else if(c+w < dis2[v])
            {
                dis2[v] = c+w;
                pq.push({v, dis2[v]});
            }
        }
    }
    cout<<"Case "<<t++<<": "<<dis2[n]<<endl;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        scanf("%d %d", &n, &m);
        G.clear();
        G.resize(n+1);
        W.clear();
        W.resize(n+1);
        for(int i=1; i<=m; i++)
        {
            int u, v, w;
            cin>>u>>v>>w;
            //g[u].push_back({v,w});
            //g[v].push_back({u.w});
            G[u].push_back(v);
            W[u].push_back(w);
            G[v].push_back(u);
            W[v].push_back(w);
        }
        memset(dis, 0, sizeof dis);
        memset(dis2, 0, sizeof dis2);
        dij(1);
    }
}
/*
6 5
0 1 100
0 2 5
0 3 50
1 5 8
2 5 10


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


*/


