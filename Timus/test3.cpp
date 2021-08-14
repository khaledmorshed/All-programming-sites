#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a[100005],i,j,k,sum,sum2=0,m=100000000;
    cin>>n;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
        sum2+=a[i];
    }
    vector<int>v;
    for(i=0; i<n; i++)
    {
        sum=a[i];
        v.push_back(sum);
        for(j=i+1; j<n; j++)
        {
            sum+=a[j];
            v.push_back(sum);
            for(k=j+1; k<n; k++)
            {
                sum+=a[k];
                v.push_back(sum);
                //sum=ar[i]+ar[j];
            }
            sum=a[i];
        }
    }
    //sort(v.begin(),v.end());
   /* for(i=0;i<v.size();i++)
    cout<<v[i]<<" ";
    cout<<endl;*/
    for(i=0; i<v.size(); i++)
    {
        m=min(abs((sum2-v[i])-v[i]),m);
    }
    cout<<m<<endl;
}

