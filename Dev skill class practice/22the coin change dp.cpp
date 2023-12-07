#include<bits/stdc++.h>
#define LIM 2003
using namespace std;
int coin[LIM], k, n;
int dp[LIM][LIM];
/*
7 10
2 10 3 5 15 20 1
*/
int f(int in, int rem){

    //if(in>=rem)  rem == 0;
    if(in >= n){
        if(rem == 0) return 1;
        return 0;
    }
    if(dp[in][rem] != -1) return dp[in][rem];
    int ans = 0;
    if(rem >= coin[in]) ans = ans | f(in+1, rem-coin[in]);

    ans = ans | f(in+1, rem);
    return dp[in][rem] = ans;
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>coin[i];
    }
    //f(0, k);
    cout<<f(0, k)<<endl;
}



