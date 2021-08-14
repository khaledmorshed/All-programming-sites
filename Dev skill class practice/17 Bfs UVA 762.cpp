#include<bits/stdc++.h>
#define LIM 100005

using namespace std;

int n, m;
vector<vector<int>> g;
//int dis[LIM], par[LIM];
map<int, bool> vis;
map<int, int> dis;
map<int, int> par;

char s1[20], s2[20];
char s3[20], s4[20];
string temp;

map<string, int> id;
map<int, string> str;

int num = 0;

void bfs(int s, int d)
{
    queue<int> q;
    q.push(s);
    vis[s] = true;
    dis[s] = 0;
    par[s] = -1;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();

        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i];
            if(!vis[v])
            {
                vis[v] = true;
                dis[v] = dis[u] + 1;
                par[v] = u;
                q.push(v);
            }
        }
    }

    if(vis[d])
    {
        vector<string> path;
        path.clear();
        while(d != -1)
        {
            temp = str[d];
            path.push_back(temp);
            d = par[d];
        }

        reverse(path.begin(), path.end());

        for(auto it=path.begin(); it!=path.end()-1; it)
        {
            cout<<*it<<" "<<*++it<<endl;
        }
    }
    else
    {
        cout<<"No route"<<endl;
    }
}

int main()
{
    bool newline = false;
    while(cin>>m)
    {
        g.resize(m+m+2);
        g.clear();
        id.clear();
        str.clear();
        vis.clear();
        dis.clear();
        par.clear();

        num = 0;

        for(int i=0; i<m; i++)
        {
            int u, v;
            scanf("%s %s", &s1, &s2);
            temp = s1;

            if(id.find(temp) == id.end())
            {
                id[temp] = ++num;
                str[num] = temp;
            }
            u = id[temp];
            //cout<<"u = "<<u<<endl;
            temp = s2;

            if(id.find(temp) == id.end())
            {
                id[temp] = ++num;
                str[num] = temp;
            }
            v = id[temp];
            //cout<<"v = "<<v<<endl;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        scanf("%s %s", &s3, &s4);
        if(newline)
        {
            cout<<endl;
        }
        newline = true;

        temp = s3;
        string temp3 = s4;

        if(id.find(temp) == id.end() || id.find(temp3) == id.end())
        {
            cout<<"No route"<<endl;
        }
        else
        {
            int it = id.at(s3);
            int it2 = id.at(s4);

            bfs(it, it2);
        }

    }

}
