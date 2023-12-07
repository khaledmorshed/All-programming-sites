#include<bits/stdc++.h>
#define LIM 2003
using namespace std;
int s, n, w[LIM], v[LIM];
//it will not be accepted in spoj Online judge.
int f(int in, int rem){
    if(in == n) return 0;
    int a = 0, b = 0;
    if(rem >= w[in]) a = v[in]+f(in+1, rem-w[in]);
    b = f(in+1, rem);
    return max(a, b);
}

int main(){
    cin>>s>>n;
    for(int i=0; i<n; i++){
        cin>>w[i]>>v[i];
    }
    cout<<f(0, s)<<endl;
}
