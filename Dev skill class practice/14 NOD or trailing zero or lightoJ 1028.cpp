#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define LIM 1000006

bool isPrime[LIM+100];
vector<int> primes;

void sieveOfEratosthenes(){
    for(ll i=2; i<=LIM; i++){
        if(!isPrime[i]){
            primes.push_back(i);
            for(ll j=i; j<=LIM; j+=i){
               isPrime[j] = true;
            }
        }
    }
}

int main(){
	sieveOfEratosthenes();
    int testCase;
    cin>>testCase;
    for(int t=1; t<=testCase; t++){
        ll n;
        cin>>n;
        if(n == 1){
			cout<<"Case "<<t<<": "<<0<<endl;
			continue;
        }
        ll ans = 1;
        for(ll i=0; primes[i] <= sqrt(n); i++)
        {
			ll cnt = 0;
            while(n > 1 && n % primes[i] == 0){
                n = n / primes[i];
                cnt++;
            }
            //a+1 so here 1 is for zero
            ans *= cnt+1;
        }
        if(n>1){
			ans *= 2;
		}
        cout<<"Case "<<t<<": "<<ans-1<<endl;
    }

}

