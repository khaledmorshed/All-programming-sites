#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, sum, A[10004];
    scanf("%d %d", &n, &sum);
    for(int i=0; i<n; i++) A[i] = rand()%10 + 1;

    unordered_set<int> ase;
    //set<int> ase;
    int ans = false;

    for(int i=0; i<n; i++) {
        int v = sum-A[i];

        if(ase.find(v) != ase.end()) {
            ans = true;
        }

        ase.insert(A[i]);

//        for(int j=0; j<i; j++) {
//            if(A[j] == v) {
//                ///ans yes
//            }
//        }
    }

    if(ans == true) {

    }
    else {

    }
}
