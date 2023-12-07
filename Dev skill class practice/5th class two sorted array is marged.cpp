#include<bits/stdc++.h>

using namespace std;

int main(){

//    int A[] = {6, 8, 9, 12, 12, 15, 18, 20};
//    int B[] = {1, 3, 5, 5, 12, 12, 17, 20};
     int A[] = {1};
    int B[] = {};
    int C[102];

//    int n = 8, m = 8;
    int n = 1, m = 0;
    int i = 0, j = 0, k = 0;

    while(i<n && j<m){
        if(A[i] <= B[j]) C[k++] = A[i++];
        else C[k++] = B[j++];
    }

    while(i<n) C[k++] = A[i++];
    while(j<m) C[k++] = B[j++];

    for(int i=0; i<n+m; i++){
        cout<<C[i]<<" ";
    }
}
