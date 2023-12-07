
#include<bits/stdc++.h>
#define LIM 2003
using namespace std;
//k = c[LIM]== how many times the product have
int s, n, w[LIM], v[LIM], c[LIM];
int dp[LIM][LIM];
int f(int in, int rem){
    if(in == n) return 0;
    if(dp[in][rem] != -1) return dp[in][rem];
    int ans = 0;
    for(int t=0; t<=c[in]; t++){
        if(rem >= t*w[in]) ans = (ans, t*v[in]+f(in+1, rem-t*w[in]));
        else break;
    }
    return dp[in][rem] = ans;
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin>>s>>n;
    for(int i=0; i<n; i++){
        cin>>w[i]>>v[i]>>c[i];
    }
    cout<<f(0, s)<<endl;
}

