#include<bits/stdc++.h>
#define LIM 20004
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;
int n;
pii A[LIM];
int cnt[LIM];
int main(){
    cin>>n;
    int mxDay = 0;
    for(int i=0; i<n; i++){
        cin>>A[i].ff>>A[i].ss;
        mxDay = max(mxDay, A[i].ss);
    }

    for(int i=0; i<n; i++){
        for(int j=A[i].ff; j<A[i].ss; j++){
            cnt[j]++;
        }
    }
    int ans = 0;
    for(int i=0; i<=mxDay; i++){
        ans = max(ans, cnt[i]);
    }

    cout<<"minimum room need = "<<ans<<endl;
}

