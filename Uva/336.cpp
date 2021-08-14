#include<bits/stdc++.h>
#define LIM 1000006

using namespace std;

map<int, int> m;
vector<vector<int>> g;
int vis[LIM], par[LIM], Time[LIM];
int mn, t = 1, temp;
int bfs(int start, int tim)
{
    //cout<<"stat "<<start<<" time "<< tim<<endl;
    int cnt = 0;
    if(tim == 0) return -1;
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    Time[start] = tim;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        tim = Time[u];
        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i];
            //cout<<" dfs u  = "<<v<<endl;
            if(!vis[v])
            {
                Time[v] = --tim;
                vis[v] = 1;
                if(tim<0)
                {
                    cnt++;
                }
                //else reserve[v];
                q.push(v);
                ++tim;
            }
        }
        --tim;
    }
    return cnt;
}

int main(){
    int bf;
    while(cin>>mn && mn>0){
        g.resize(mn+mn+2);
        m.clear();
        g.clear();
        int num = 0, sum = 0;
        for(int i=0; i<mn; i++){
            int u, v;
            cin>>u>>v;
            if(m.find(u) == m.end()){
                m[u] = ++num;
            }
            u = m[u];
            //cout<<"u = "<<u<<endl;
            if(m.find(v) == m.end()){
                m[v] = ++num;
            }
            v = m[v];
            //cout<<"v = "<<v<<endl;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int start, time;
        while(cin>>start>>time && start>0){
            memset(vis, 0, sizeof vis);
            memset(Time, 0, sizeof Time);
            //memset(par, 0, sizeof par);
            int node = m[start];
            if(m.find(node) == m.end()){
                //cout<<"node = "<<m.size()<<endl;
            }
            else bf = bfs(node, time);
            //cout<<"bf = "<<bf<<endl;
            //cout<<" size = "<<m.size()<<endl;
            for(int i=1; i <= num; i++)
            {
                //if(i == 100-2) break;
                //int u = m[i];
                //if(m.find(u) == )
                //if(g[u].find() == )
                for(int j=0; j<g[i].size(); j++)
                {
                    int v = g[i][j];
                    if(!vis[v])
                    {
                        vis[v] = 1;
                        ++sum;
                    }
                    if(!vis[v])
                    {
                        vis[v] = 1;
                        ++sum;
                    }
                }
            }
            int sum2 = sum + bf;
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", t++, sum2, start, time);
            sum = 0;
        }
        if(mn>0) cout<<endl;
    }
}
