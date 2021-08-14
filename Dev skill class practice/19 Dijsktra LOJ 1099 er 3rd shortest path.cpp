#include<bits/stdc++.h>
#define LIM 10004
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
ll dis[LIM], dis2[LIM], dis3[LIM];

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
        dis3[u]= INF;
    }
    dis[s] = 0;
    dis2[s] = INF;
    while(!pq.empty())
    {
        info U = pq.top();
        pq.pop();
        int u = U.x;
        ll c = U.y;
        cout<<endl<<"u = "<<u<<"   c = "<<c<<"   dis2[u] = "<<dis2[u]<<"   dis[u] = "<<dis[u]<<endl;
        for(int i=0; i<G[u].size(); i++){
            int v = G[u][i];
            int w = W[u][i];
            cout<<"v = "<<v<<"   w = "<<w<<endl;
            cout<<"disPrev dis["<<v<<"] = "<<dis[v]<<endl;
            cout<<"disPrev2 dis2["<<v<<"] = "<<dis2[v]<<endl;
            cout<<"c+w = "<<c+w<<endl;
            if(c+w < dis[v]){
                dis2[v] = dis[v];
                dis[v] = c+w;
                cout<<"push if dis2["<<v<<"] = "<<dis2[v]<<endl;
                cout<<"push if dis["<<v<<"] = "<<dis[v]<<"  and push v = "<<v<<endl;
                pq.push({v, dis[v]});
            }
            else if(c+w == dis[v]){
                cout<<"(c+w) inside = "<<c+w<<" dis[v] = "<<dis[v]<<endl;
            }
            else if(c+w < dis2[v]){
                 dis3[v] = dis2[v];
                 dis2[v] = c+w;
                cout<<"push else dis2["<<v<<"] = "<<dis2[v]<<"  and push v = "<<v<<endl;
                cout<<"push else dis3["<<v<<"] = "<<dis3[v]<<endl;
                pq.push({v, dis2[v]});
            }
            else if(c+w == dis2[v]){
                 cout<<"(c+w)33 inside = "<<c+w<<" dis2[v] = "<<dis2[v]<<endl;
            }
            else if(c+w < dis3[v]){
                dis3[v] = c+w;
                cout<<"push else dis3["<<v<<"] = "<<dis3[v]<<"  and push v = "<<v<<endl;
                //cout<<"push else dis["<<v<<"] = "<<dis[v]<<endl;
                pq.push({v, dis3[v]});
            }
        }
    }
    cout<<"All node have 3rd shortest path :"<<endl;
    for(int i=1; i<=n; i++){
        cout<<dis3[i]<<endl;
    }
    cout<<"Case "<<t++<<": "<<dis3[n]<<endl;
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
        for(int i=0; i<m; i++)
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
        memset(dis3, 0, sizeof dis3);
        dij(1);
    }
}

/*
1
5 5
1 2 3
2 3 1
3 4 1
4 5 8
5 4 8


2
3 3
1 2 100
2 3 200
1 3 50


*/
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


