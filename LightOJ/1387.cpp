#include<bits/stdc++.h>
using namespace std;

void takeNumberOfOPeration();
int  findTotal(string s, int IthValueAfterDonate);

void print(vector<int> Repv);

int cas = 1;

int main()
{

    int T;
    cin>>T;

    //cin.ignore();

    while(T)
    {

        takeNumberOfOPeration();

        T--;
    }

}

void takeNumberOfOPeration()
{

    int N, total, allTotal = 0;
    cin>>N;
    string s;

    cin.ignore();
    vector<int> Repv;

    while(N)
    {

        getline(cin, s);

        if(s == "report")
        {

            Repv.push_back(allTotal);
        }

        else
        {

            for(int i = 0; i < s.length(); i++)
            {

                if(s[i] == ' ')
                {
                    total = findTotal(s, i+1);
                    allTotal = allTotal + total;
                    break;

                }

            }

        }


        N--;
    }

    print(Repv);
}


int  findTotal(string s, int ithValueAfterDonate)
{

    int total;

    string totalValueString = "";

    for(int i = ithValueAfterDonate; i < s.length(); i++)
    {

        totalValueString = totalValueString + s[i];
    }

    total = stod (totalValueString);

    //cout<<total<<endl;

    return total;

}

void print(vector <int> Repv)
{

    cout<<"Case "<<cas++<<":"<<endl;

    for(auto it = Repv.begin(); it != Repv.end(); it++)
    {

        cout<<*it<<endl;
    }
}
