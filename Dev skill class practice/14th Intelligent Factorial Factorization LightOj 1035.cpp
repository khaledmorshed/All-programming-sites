#include<bits/stdc++.h>
#define ll long long int
#define LIM 65536+1//sqrt(2^32) + 1
using namespace std;

vector<int> primes;
vector<bool> isPrime(LIM, true);
vector<int> ans[101];

void sieve()
{
    primes.push_back(2);
    for(ll i=3; i<=LIM; i+=2)
    {
        if(isPrime[i] == true)
        {
            primes.push_back(i);
            for(ll j=i*i; j<=LIM; j+=i)
            {
                isPrime[j] = false;
            }
        }
    }
}

void factorize()
{
    for(int n=2; n<=100; n++)
    {
        int temp = n;
        for(int j = 0; j<=100; j++)
        {
            int m = ans[n-1][j];
            ans[n][j] = m;
        }
        for(int j=0; j<primes.size(); j++)
        {
            int p = primes[j];
            if(p > n) break;
            int cnt = 0;
            while(temp>1 && temp%p==0)
            {
                cnt++;
                temp = temp / p;
            }
            ans[n][p] += cnt;
        }

    }
}

int main()
{

    for(int i=0; i<=100; i++)
    {

        for(int j = 0; j<=100; j++)
        {
            ans[i].push_back(0);
        }
    }


    sieve();
    factorize();

    int T;
    cin>>T;
    for(int t=1; t<=T; t++)
    {
        int n;
        cin>>n;
        cout<<"Case "<<t<<": "<<n<<" = ";
        bool check = false;
        for(int i = 0; i<=100; i++)
        {
             if(ans[n][i] > 0){
                if(check) cout<<" * ";
                cout<<i<<" ("<<ans[n][i]<<")";
                check = true;
            }
        }
        cout<<endl;
    }
}
