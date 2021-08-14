#include<bits/stdc++.h>
#define LIM 10004

using namespace std;
vector<vector<int>> g;
int vis[LIM], dis[LIM], par[LIM], countAtLevel[LIM];

map<int, int> m;

void bfs(int s)
{
     if(m[s] == -1){
        cout<<0<<endl;
        return;
     }
    cout<<"dfdf "<<endl;
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    dis[s] = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i];
            if(!vis[v])
            {
                vis[v] = 1;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
}
}

int main()
{
    int e, temp, temp2;
    cin>>e;
    int ee = e;
    g.clear();
    g.resize(e+1);
    while(ee--){
        int n;
        cin>>n;
        int num = n;
        while(n--){
            int u;
            cin>>u;
            if(num == 1){
                m[u] = -1;
            }
            else if(n+1 == num){
                temp = u;
                //cout<<"temp1 = "<<temp<<endl;
            }
            else{
                //cout<<"temp = "<<temp<<" u = "<<u<<endl;
                g[temp].push_back(u);
                g[u].push_back(temp);
                temp = u;
            }
        }
    }
    int T;
    cin>>T;
    while(T--){
        g.clear();
        memset(vis, 0 , sizeof vis);
        memset(dis, 0, sizeof dis);
        memset(countAtLevel, 0, sizeof countAtLevel);
        int employee;
        cin>>employee;
        bfs(employee);

        int tt = 0, mm, min_da;

        for(int u=0; u<e; u++){
            countAtLevel[dis[u]]++;
            cout<<" dfd "<<countAtLevel[u]<<endl;
        }
       // cout<<" dfd "<<countAtLevel[0]<<endl;
        cout<<" dfd "<<countAtLevel[1]<<endl;
    }
}

