#include<bits/stdc++.h>
#define LIM 10004

using namespace std;

map<string,vector<string>> mv;

int main()
{




        string st[201];
        for(int i=0; i<6; i++)
        {
            cin>>st[i];
        }

        for(int i=0, j=1; i<6 && j < 6; i++, j++)
        {

                string u = st[i];
                string v = st[j];
                cout<<"u = "<<u<<" v = "<<v<<"  "<<i<<"->"<<j<<endl;

                    mv[u].push_back(v);

                    mv[v].push_back(u);

                    //cout<<mv[u][i]<<" "<<mv[v][i]<<endl;


                }




        for(auto it=mv.begin(); it!=mv.end(); it++)
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
        }



}

