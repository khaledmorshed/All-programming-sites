#include<bits/stdc++.h>
#define ll long long int

using namespace std;

ll power(ll a, ll b, ll M){
    if(b == 0) return 1;
    else if(b % 2){
        return (a * power(a, b-1, M)) % M;
    }
    else{
        ll temp = (power(a, b/2, M));
        return (temp*temp) % M;
    }
}

ll modeInverse(ll n , ll M){
    return power(n, M-2, M);
}

ll nCrModFermats(int n, int r , ll M){
    if(n<r) return 0;
    if(r == 0) return 1;

    ll fact[n+1];
    fact[0] = 1;
    for(int i=1; i<=n; i++){
        fact[i] = (fact[i-1] * i) % M;
    }
    return (fact[n] * modeInverse(fact[r], M) % M * modeInverse(fact[n-r], M) % M) % M;
}

int main(){
    int n, r;
    cin>>n>>r;
    ll M;
    cin>>M;
    cout<<"value of nCr is = "<<nCrModFermats(n, r, M)<<endl;
}
