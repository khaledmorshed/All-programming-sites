#include<bits/stdc++.h>
#define LIM 20004
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;
int n;
pii A[LIM];
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>A[i].ff>>A[i].ss;
    }
    sort(A, A+n);

    multiset<int> ase;
    int ans = 0;
    for(int i=0; i<n; i++){
        while(!ase.empty() && *ase.begin() <= A[i].ff){
            ase.erase(ase.begin());
        }
        ase.insert(A[i].ss);
        ans = max(ans, (int)ase.size());
    }
    cout<<"minimum room need = "<<ans<<endl;
}
