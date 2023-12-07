#include<bits/stdc++.h>
#define LIM 2003
using namespace std;
int s, n, w[LIM], v[LIM];
int dp[LIM][LIM];
int f(int in, int rem){
    if(in >= n) return 0;
    if(dp[in][rem] != -1) return dp[in][rem];
    int a = 0, b = 0 , c = 0;
    //pasa pasi adjacent ke na niye...nile
    if(rem >= w[in]) a = v[in]+f(in+2, rem-w[in]);
    //na line
    b = f(in+1, rem);
     cout<<"a = "<<a<<" b = "<<b<<endl;
    return dp[in][rem] = max(a, b);
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin>>s>>n;
    for(int i=0; i<n; i++){
        cin>>w[i]>>v[i];
    }
    cout<<f(0, s)<<endl;
}



