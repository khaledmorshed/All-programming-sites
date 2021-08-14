#include<bits/stdc++.h>

using namespace std;
map<string,string> par;
map<string,bool> visited;
map<string,vector<string> > adj;

bool bfs(string s1,string s2)
{
    queue<string> q;
    //while(!q.empty()) q.pop();
    q.push(s1);
    while(!q.empty())
    {
        string u=q.front();
        q.pop();
        visited[u]=true;
        if(u==s2)
            return true;
        for(int i=0;i<adj[u].size();i++){
            string v=adj[u][i];
            if(!visited[v]){
                visited[v]=true;
                par[v]=u;
                if(v==s2)
                    return true;
                q.push(v);
            }

        }
    }
    return false;
}
void print_path(string s1,string s2)
{
    //cout<<"s2 = "<<s1<<" s1 = "<<s2<<endl;
    if(s1==s2) return;
    //cout<<"just tes"<<endl;
    print_path(par[s1],s2);
    cout<<par[s1]<<" "<<s1<<endl;
}
int main()
{
    int n,i;
    string s1,s2;
    bool p=false;
    while(scanf("%d",&n)!=EOF)
    {

        for(i=0;i<n;i++){
            cin>>s1>>s2;
            adj[s1].push_back(s2);
            adj[s2].push_back(s1);
            //cout<<adj[s1][i]<<endl<<adj[s2][i]<<endl<<endl;
        }

        /* for(auto it=adj.begin(); it!=adj.end(); it++)
        {
                cout<<it->first<<" just chek"<<endl;

            //cout<<(*it).first<<" dg "<<(*it).second<<endl;
            //cout<<it->first<<endl;
            //cout<<it->first<<" dg "<<*it<<endl;
            for(auto it2 = it->second.begin(); it2 != it->second.end(); it2++){

                cout<<it->first<<" ";
                cout<<*it2<<endl;
                //break;

            }
        }*/


        cin>>s1>>s2;
        if(p) printf ("\n"); p = true;
        if(bfs(s1,s2)){
            print_path(s2,s1);
        }
        else cout<<"No route"<<endl;
        visited.clear();
        adj.clear();
        par.clear();

    }
   return 0;
}
