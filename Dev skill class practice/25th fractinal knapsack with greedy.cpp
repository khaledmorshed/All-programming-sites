#include<bits/stdc++.h>
#define LIM 2003
using namespace std;

struct info{
    int v, w;
};

bool operator < (const info &a, const info &b){
    return 1LL*a.v*b.w < 1LL*b.v*a.w;
}

int n, k;
info A[LIM];

int main(){
    cin>>n>>k;
    for(int i=0; i<n; i++){
        cin>>A[i].v>>A[i].w;
    }
    sort(A, A+n);
    double ans = 0;
    for(int i=n-1; i>=0 && k; i--){
        if(A[i].w <= k){
            ans+=A[i].v;
            k = k-A[i].w;
        }
        else{
            ans = ans + (1.0*A[i].v*k/A[i].w);
            k = 0;
        }
    }
    printf("%.4f\n", ans);
}

/*
6
7
5 1 3 2 10 1 100 10 8 1 20 5
*/
