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

    for(int i=0; i<=mxDay; i++){
        cnt[A[i].ff]++;
        cnt[A[i].ss]--;
    }

    int cur = 0 , ans = 0;
    for(int i=0; i<=mxDay; i++){
        cur = cur + cnt[i];
        ans = max(ans, cur);
    }

    cout<<"minimum room need = "<<ans<<endl;
}


