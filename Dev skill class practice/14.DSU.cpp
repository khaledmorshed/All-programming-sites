#include <bits/stdc++.h>
#define LIM 100005

using namespace std;
int par[LIM], sz[LIM];

int getpar(int u)
{
    if(par[u] == u) return u;
    return par[u] = getpar(par[u]);
}

void unite(int u, int v)
{
    u = getpar(u);
    v = getpar(v);

    if(u == v) return;

    /*if(sz[u] < sz[v]) swap(u,v);
    sz[u] += sz[v];
    par[v] = u;*/

    if(sz[u] >= sz[v])
    {
        sz[u] += sz[v];
        par[v] = u;
    }
    else{
        sz[v] += sz[u];
        par[u] = v;
    }
}

bool isconnection(int u, int v)
{
    bool chek;
    chek = getpar(u) == getpar(v);
    return chek;
}

int main()
{
    for(int i=1; i<LIM; i++) par[i] = i, sz[i] = 1;

    int n, m, q, cycle=0;
    scanf("%d %d %d", &n, &m, &q);
    for(int i=0; i<m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        if(par[u] == par[v]){
            cycle++;
        }
        unite(u,v);
    }


    for(int i=0; i<q; i++)
    {
        int u,v;
        scanf("%d %d", &u, &v);
        if(isconnection(u,v)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    int comp=0;
    for(int i=1; i<=n; i++){
        if(par[i] == i){
            comp++;
        }
    }
    cout<<"component = "<<comp<<endl;
    cout<<"Cycle = "<<cycle<<endl;

    //cout<<"par[2] = "<<par[2]<<endl;
}
