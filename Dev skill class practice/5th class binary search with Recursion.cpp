#include<bits/stdc++.h>
#define LIM 10004
using namespace std;

int n;
int ar[LIM];

bool bs(int low, int hi, int x){
    if(low == hi) return (x == ar[hi]);
    int mid = (low + hi) / 2;
    if(x == ar[mid]) return true;
    else if(x < ar[mid]) return bs(low, mid, x);
    else return bs(mid + 1, hi, x);

    return true;
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>ar[i];
    }
    int x;
    cin>>x;
    int low = 0, hi = n-1;
    bool result = bs(low, hi, x);
    if(result) cout<<"found"<<endl;
    else cout<<"not found"<<endl;
}
