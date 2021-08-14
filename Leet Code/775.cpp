#include<bits/stdc++.h>
using namespace std;
int A[5003], t[5003], globalInverse = 0, localInverse = 0;

void _merge(int st, int ed){
    int md = (st + ed) / 2;
    int i = st, j = md, k = 0;
    while(i<md && j<ed){
        if(A[i] <= A[j]) t[k++] = A[i++];
        else{
            t[k++] = A[j++];
            globalInverse = globalInverse + md - i;
        }
    }
    while(i<md) t[k++] = A[i++];
    while(j<ed) t[k++] = A[j++];

    for(int p=st, q=0; p<ed; p++,q++)
    {
        A[p] = t[q];

    }

}

void mergesort(int st, int ed){
    if(st == ed-1) return;
    int md = (st + ed) / 2;
    mergesort(st, md);
    mergesort(md, ed);
    _merge(st, ed);
}

void localInverseCount(int n){
    for(int i=0, j=1; i<n && j<n; i++,j++){
        if(A[i]>A[j]) ++localInverse;
    }
}

int main(){

    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>A[i];
    }
    localInverseCount(n);
    mergesort(0, n);

    //cout<<globalInverse<<endl<<localInverse<<endl;
    if(globalInverse == localInverse) cout<<"true\n";
    else cout<<"fale\n";
    //main();
}
