#include<bits/stdc++.h>
#define LIM 2003
#define INF 1000000009
using namespace std;
int coin[LIM], k, n;
int dp[LIM][LIM];
/*
7 11
2 11 3 5 15 20 1
3 5
2 5 3
*/
int f(int in, int rem){

    //if(in>=rem)  rem == 0;
    cout<<"f("<<in<<", "<<rem<<")"<<endl;
    if(in >= n){
        if(rem == 0) return 0;
        return INF;
    }
    if(dp[in][rem] != -1) return dp[in][rem];
    int ans = INF;
    if(rem >= coin[in]) ans = min(ans, 1 + f(in+1, rem-coin[in]));
    cout<<"in = "<<in<<" rem = "<<rem<<" ans = "<<ans<<endl;

    ans = min(ans , f(in+1, rem));
    dp[in][rem] = ans;
    cout<<"in = "<<in<<" rem = "<<rem<<" ans2 = "<<ans<<endl;
    cout<<"dp["<<in<<"]"<<"["<<rem<<"] = "<<dp[in][rem]<<endl;
    return ans;
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



