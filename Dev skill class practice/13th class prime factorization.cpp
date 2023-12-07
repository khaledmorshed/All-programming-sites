#include<bits/stdc++.h>
#define LIM 1000006
#define ll long long int
using namespace std;
int prime[LIM];
vector<int> primes;

void primeGen(){
    for(int j=4; j<LIM; j+=2){
        prime[j] = 1;
    }
    for(ll i=3; i*i<LIM; i+=2){
        for(ll j=i*i; j<LIM; j+=i){
            prime[j] = 1;
        }
    }
    primes.push_back(2);
    for(int i=3; i<LIM; i+=2){
        if(!prime[i]) primes.push_back(i);
    }
}

void primeFactorization(int n){
    int num  = n;
    bool check = false;
    for(int i=0; i<primes.size(); i++){
       int p  = primes[i];
       if(p * p > n) break;
       int cnt = 0;
      // cout<<"p = "<<p<<endl;
       while(num%p == 0){
            cnt++;
            num/=p;
       }
       if(cnt){
        if(check)cout<<" ";
        cout<<p<<"^"<<cnt<<endl;
        check = true;
       }
    }
    cout<<"num = "<<num<<endl;
    if(num != 1) cout<<n<<"^1"<<endl;
}

int main(){
    primeGen();
    int n;
    cin>>n;
    primeFactorization(n);
}
