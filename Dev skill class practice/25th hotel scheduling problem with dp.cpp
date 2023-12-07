#include<bits/stdc++.h>
#define LIM 2003
using namespace std;

struct info{
    int s, e;
};

info A[LIM];
int n;
int dp[LIM];
int f(int in, int fre){
    if(in == n) return 0;
    int a=0, b=0;
    if(A[in].s >= fre){
        a = 1+f(in+1, A[in].e);
    }
    b = f(in+1, fre);
    return dp[in] = max(a, b);
}

int main(){
   cin>>n;
   for(int i=0; i<n; i++){
    cin>>A[i].s>>A[i].e;
   }
   cout<<f(0, 0)<<endl;
}

/*
5
1 5
2 4
4 6
7 9
8 12

4
1 5
2 4
4 6
7 9

3
1 5
2 4
4 6

*/
