#include<bits/stdc++.h>
#define LIM 10004

using namespace std;

int k, n, m, t = 1;
vector<vector<int>> g;
int p[LIM], vis[LIM], Kcount = 0, cnt=0, l= 0;

int cc;

int dfs2(int u)
{
    vis[u] = 1;
    //cnt++;
    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];
        if(!vis[v])
        {
            ++cnt;
            cout<<"cnt dfs 2 v = "<<cnt<<" "<<v<<endl;
            //getchar();
            dfs2(v);
        }
    }
    //return cnt;
}


void dfs(int u)
{

    vis[u] = 1;

    if(u == p[l])
    {
        ++Kcount;
        //getchar();
        cout<<"K coutn = "<<Kcount<<endl;
        //getchar();
        l++;
    }

    for(int i=0; i<g[u].size(); i++)
    {
        int v = g[u][i];

        if(k == Kcount)
        {
            ++cnt;
            Kcount++;
            cout<<"cnt dfs 1 v = "<<cnt<<" "<<v<<endl;
            //getchar();
            dfs2(u);
            break;
        }


        else if(!vis[v] && u  == p[l])
        {
            //Kcount = k;
            dfs(u);
        }
        else if(!vis[v] && v == p[l]){
            cnt++;
            dfs2(v);
            break;
        }
        else if(!vis[v])
        {
            cout<<" v = "<<v<<endl;
            dfs(v);
        }
    }
}

int main()
{
    int T;
    cin>>T;

    while(T--)
    {

        memset(p, 0, sizeof p);
        memset(vis, 0, sizeof vis);

        scanf("%d %d %d", &k, &n, &m);
        for(int i=0; i<k; i++)
        {
            scanf("%d", &p[i]);
        }

        g.clear();
        g.resize(n+1);

        for(int i=0; i<m; i++)
        {
            int u, v;
            cin>>u>>v;
            g[u].push_back(v);
        }

        dfs(p[0]);

        printf("Case %d: %d\n", t++, cnt);
        cnt = 0;
        l = 0;
        Kcount = 0;
    }

}
