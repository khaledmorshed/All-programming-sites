#include<bits/stdc++.h>
#define LIM 2003
#define INF 1000000009

using namespace std;

struct info{
    int s, e;
};

bool operator < (const info &a, const info &b){
    return a.e < b.e;
}

int n, start[LIM], finish[LIM];
info A[LIM];

int f(){
    int x = INF, ans = 0;
    for(int i=n-1; i>=0; i--){
        if(A[i].e <= x){
            ans++;
            x = A[i].s;
        }
        //A[i-1].s == x
        else if(A[i].s > A[i-1].s){
            x = A[i].s;
        }
    }
    return ans;
}

int main(){
   cin>>n;
   for(int i=0; i<n; i++){
    cin>>start[i]>>finish[i];
    A[i].s = start[i];
    A[i].e = finish[i];
   }

   sort(A, A+n);
   cout<<"maximum number of works = "<<f()<<endl;
}

/*
6
1 2
3 4
0 6
5 7
8 9
5 9

5
1 2
3 4
0 6
8 9
5 9

*/

