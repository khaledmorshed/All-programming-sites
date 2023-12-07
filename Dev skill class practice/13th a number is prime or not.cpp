#include<bits/stdc++.h>
#define ll long long
#define LIM 1000006

using namespace std;
int prime[LIM];
vector<int> primes;

void primeGen(){
    for(int i=4; i<LIM; i+=2){
        prime[i] = 1;
    }
    for(ll i=3; i*i<LIM; i+=2){
        for(ll j = i*i; j<LIM; j+=i){
            prime[j] = 1;
        }
    }
    primes.push_back(2);
    for(int i=3; i<LIM; i+=2){
        if(!prime[i])primes.push_back(i);
    }
}

bool isPrime(ll n){
    for(int i=0; i<primes.size(); i++){//
        int p = primes[i];
        if(p*p > n) break;
        if(n % p == 0){
            printf("divisor.........%d", p);
            return false;
        }
    }

    return true;
}

int main(){
    primeGen();

    ll n;
    cin>>n;

    bool flag = isPrime(n);

    if(flag)cout<<"N is "<<"prime"<<endl;
    else cout<<"N is "<<"not prime"<<endl;
}
