#include<bits/stdc++.h>
#define LIM 10004

using namespace std;
map<string,vector<string>> mv;
map<string,bool> vis;
map<string,int> dis;

bool bfs(string s1, string s2)
{
    queue<string> q;
    q.push(s1);
    while(!q.empty())
    {
        string u = q.front();
        q.pop();
        vis[u] = true;
        if(u == s2) return true;
        for(int i=0; i<mv[u].size(); i++)
        {
            string v = mv[u][i];
            if(!vis[v])
            {
                vis[v] = true;
                dis[v] = dis[u] + 1;
                //par[v] = u;
                if(v == s2) return true;
                q.push(v);
            }
        }
    }

}

void print(string s1, string s2)
{
    cout<<s1<<" "<<s2<<" "<<dis[s2]<<endl;
}

int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        mv.clear();
        string st[202];
        for(int i=0; i<201; i++)
        {
            cin>>st[i];
            if(st[i] == "*") break;
        }

        cin.ignore();

        for(int i=0; i<201; i++)
        {
            if(st[i] == "*") break;
            int len = st[i].size();
            for(int j=0; j<201; j++)
            {
                int len2 = st[j].size();
                if(i == j || len != len2) continue;
                int cnt = 0;
                for(int k=0; k<len; k++)
                {
                    if(st[i][k] == st[j][k]) continue;
                    else
                    {
                        ++cnt;
                    }
                }
                string u = st[i];
                string v = st[j];

                if(cnt == 1)
                {
                    mv[u].push_back(v);
                    mv[v].push_back(u);
                }
            }
        }

        // for print map<string, vector<string>> this type of map
        /*for(auto it=mv.begin(); it!=mv.end(); it++)
        {
            for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++)
            {
                cout<<it->first<<" ";
                cout<<*it2<<endl;
            }
        }*/
        string line;
        while (getline(cin, line) && line != "")
        {
            stringstream ss(line);
            string s1, s2;
            ss>>s1>>s2;
            vis.clear();
            dis.clear();
            if(bfs(s1, s2))
            {
                print(s1, s2);
            }

        }
        if(n)
            cout<<endl;
    }
}

