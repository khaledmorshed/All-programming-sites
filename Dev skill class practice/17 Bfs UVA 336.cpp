#include<bits/stdc++.h>
#define LIM 10000007
#define ll long long int

using namespace std;
int n = 1002, m, t= 1;
//int m , t = 1;
vector<vector<int>> g;
int vis[LIM], reserve[LIM], Time[LIM];

int bfs(int start, int tim)
{
    int cnt = 0;
    queue<int> q;
    q.push(start);
    vis[start] = 1;
    Time[start] = tim;
    cout<<"tim "<<tim<<endl;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        //if(tim == 0)
        //{
        tim = Time[u];
        // cout<<"after zero = "<<tim<<" and node is "<<u<<endl;
        //  getchar();
        // }

        //cout<<"g["<<u<<"].size() = "<<g[u].size()<<endl;
        for(int i=0; i<g[u].size(); i++)
        {
            int v = g[u][i];
            if(!vis[v])
            {
                Time[v] = --tim;
                //cout<<" node "<<v<<" = "<<tim<<endl;
                vis[v] = 1;
                if(tim<0)
                {
                    cnt++;
                    // cout<<" cnt = "<<cnt<<endl;
                    //getchar();
                }
                //else reserve[v];
                q.push(v);
                ++tim;
            }
            /*cout<<"after if condition = "<<tim<<endl;
            getchar();*/

        }
        --tim;
        /*cout<<"after for loop = "<<tim<<endl;
        getchar();*/
    }


    return cnt;
}

int main()
{
    int bf;
    while(1)
    {
        map<ll, int> maap;

        int rep1 = 1, rep2 = 1, rep3 = 1;

        int k = 0;
        int sum = 0;
        scanf("%d", &m);
        if(m == 0) break;
        g.clear();
        maap.clear();
        //N.clear();
        //memset(N, 0, sizeof N);
        g.resize(n+1);
        for(int i=0; i<m; i++)
        {
            ll u, v;
            scanf("%lld %lld", &u, &v);

            auto it = maap.find(u);
            auto it2 = maap.find(v);
           // cout<<&it<<endl;
           // cout<<&it2<<endl;


            if(u != v)
            {
                cout<<"just entered\n";
                if(maap.empty())
                {
                    cout<<"I am empty"<<endl;
                    maap.insert({u, ++rep1});
                    maap.insert({v, rep1+1});


                    cout<<"u rep  = "<<u<<" "<<rep1<<endl;
                    cout<<"v rep2 = "<<v<<" "<<rep1+1<<endl;

                    g[rep1].push_back(rep1+1);
                    g[rep1+1].push_back(rep1);

                    rep1+=1;
                }

                else if(it->first == u)
                {
                    cout<<"I am it\n"<<it->first<<" "<<u<<endl;
                    maap.insert({u, maap.at(u)});
                    maap.insert({v, rep1+1});


                    cout<<"u rep  = "<<u<<" "<<maap.at(u)<<endl;
                    cout<<"v rep2 = "<<v<<" "<<rep1+1<<endl;

                    g[maap.at(u)].push_back(rep1+1);
                    g[rep1+1].push_back(maap.at(u));

                    rep1+=1;
                }

                else if(it2->first == v)
                {
                    cout<<"I am it2\n";
                    maap.insert({v, maap.at(v)});
                    maap.insert({u, rep1+1});


                    cout<<"u rep2  = "<<u<<" "<<rep1+1<<endl;
                    cout<<"v rep22 = "<<v<<" "<<maap.at(v)<<endl;

                    g[maap.at(v)].push_back(rep1+1);
                    //cout<<"map2 = u "<<g[maap.at(v)]
                    g[rep1+1].push_back(maap.at(v));

                    rep1+=1;
                }

                else
                {
                    cout<<"hi i am else\n";
                    //rep1 = rep1+5;
                    maap.insert({u, ++rep1});
                    maap.insert({v, rep1+1});

                    cout<<"u rep3  = "<<u<<" "<<rep1<<endl;
                    cout<<"v rep4  = "<<v<<" "<<rep1+1<<endl;

                    g[rep1].push_back(rep1+1);
                    g[rep1+1].push_back(rep1);

                    rep1+=1;
                }


            }

            else
            {

                if(maap.empty())
                {

                    maap.insert({u, ++rep1});
                    //maap.insert({v, rep1});


                    cout<<"u rep 0 = "<<u<<" "<<rep1<<endl;
                    cout<<"v rep2 0= "<<v<<" "<<rep1<<endl;

                    g[rep1].push_back(rep1);
                    //g[rep1].push_back(rep1);

                    //rep1+=1;
                }

                else if(it->first == u)
                {

                    maap.insert({u, maap.at(u)});
                    //maap.insert({v, maap.at(u)});


                    cout<<"u rep  0= "<<u<<" "<<maap.at(u)<<endl;
                    cout<<"v rep2 0= "<<v<<" "<<rep1<<endl;

                    g[maap.at(u)].push_back(rep1);
                    //g[rep1].push_back(maap.at(u));

                    //rep1+=1;
                }

                else if(it2->first == v)
                {

                    maap.insert({v, maap.at(v)});
                   // maap.insert({u, maap.at(v)});


                    cout<<"u rep2  0= "<<u<<" "<<rep1<<endl;
                    cout<<"v rep22 0= "<<v<<" "<<maap.at(v)<<endl;

                    g[maap.at(v)].push_back(rep1);
                    //cout<<"map2 = u "<<g[maap.at(v)]
                    //g[rep1].push_back(maap.at(v));

                    //rep1+=1;
                }

                else
                {

                    //rep1 = rep1+5;
                    maap.insert({u, ++rep1});
                    //maap.insert({v, rep1});

                    cout<<"u rep3  0= "<<u<<" "<<rep1<<endl;
                    cout<<"v rep4 0 = "<<v<<" "<<rep1<<endl;

                    g[rep1].push_back(rep1);
                    //g[rep1].push_back(rep1);

                    //rep1+=1;
                }

            }

            //auto it = maap.at(u);
            //cout<<"it firt = "<<maap.at(u)/*<<" it second = "<<it->second*/<<endl;
            //g[u].push_back(it->second);

            /*auto it2 = maap.find(v);
            if(it2->first == v || maap.empty())
            {

                maap.insert({v, ++rep2});
            }
            else maap.insert({v, rep2+=3});*/
            //auto it2 = maap.at(v);
            //cout<<"it-firt = "<<maap.at(v)/*<<" it2-second = "<<it->second*/<<endl;
            //g[v].push_back(it2->second);
            // g[rep1].push_back(rep2);
            // g[rep2].push_back(rep1);

            //N[k++] = rep1;
            //N[k++] = rep2;

            //N.push_back(u);
            //N.push_back(v);
        }



        /*cout<<endl;
        for(int i=1; i<30; i++)
        {
            //cout<<"size "<<g[i].size()<<endl;
            for(int j=0; j<g[i].size(); j++)
            {
                cout<<g[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;*/

        while(1)
        {
            ll node;
            int ti;
            scanf("%lld %d", &node, &ti);

            memset(vis, 0, sizeof vis);
            memset(Time, 0, sizeof Time);
            //vis.clear();
            //Time.clear();
            //N.clear();

            if(node == 0 && ti == 0)
            {
                break;
            }


            auto it = maap.find(node);
            if(it == maap.end())
            {
                bf = bfs(-2, ti);
            }
            else bf = bfs(it->second, ti);
            //int uu = it->second;
            //getchar();
            //cout<<"bfs "<<endl;
            //bf = bfs(it->second, ti);
            cout<<"bf = "<<bf<<endl;
            // getchar();

            for(int i=0; i< n; i++)
            {
                if(i == n-2) break;


                int u = i;


                for(int j=0; j<g[u].size(); j++)
                {
                    int v = g[u][j];
                    if(!vis[u])
                    {
                        vis[u] = 1;
                        ++sum;
                    }
                    if(!vis[v])
                    {
                        //comp++;
                        //int cc = bfs(u, ti);
                        vis[v] = 1;
                        ++sum;
                        //cout<<"sum v = "<<sum<<" "<<v<<endl;
                        //getchar();
                    }
                }
                //cout<<"sum2 v = "<<sum<<" "<<endl;
                //getchar();
            }
            // getchar();
            int sum2 = sum + bf;
            //cout<<"sum2 = "<<endl;

            //cout<<"Case "<<t++<<": "<<bfs(node, ti)<<" nodes not reachable from node "<<node<<" with TTL = "<<ti<<endl;
            printf("Case %d: %d nodes not reachable from node %lld with TTL = %d.\n", t++, sum2, node, ti);
            sum = 0;
        }
    }

}
