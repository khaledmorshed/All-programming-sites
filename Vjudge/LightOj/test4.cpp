#include <bits/stdc++.h>

using namespace std;

int n, k, A[1003];

int f(int x) {
    int cnt = 1, cur = 0;
    for(int i=0; i<n; i++) {
        if(A[i] > x) return k+100000;
        if(cur+A[i] <= x) {
            cur += A[i];
        }
        else {
            cnt++;
            cur = A[i];
        }
    }
    return cnt;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int t=1; t<=T; t++) {
        int sum = 0;
        scanf("%d %d", &n, &k);
        n++; k++;
        for(int i=0; i<n; i++) {
            scanf("%d", &A[i]);
            sum += A[i];
        }

        int lo = 0, hi = sum;
        while(lo < hi) {
            int x = (lo+hi)/2;

            /** f(x) : kono dinei x mile er beshi
            journey hobe na, ei rule e sesh porjonto
            jete hole koyta journey korte hobe
            */
            if(f(x) <= k) hi = x;
            else lo = x+1;
        }

        printf("Case %d: %d\n", t, hi);

        int cur = 0;
        for(int i=0, j=0; i<n || j<k; i++) {
            if(i == n) {
                printf("%d\n", cur);
                cur = 0;
                j++;
            }
            else if(cur+A[i] <= hi && n -i != k - j -1) cur += A[i];
            else {
                printf("%d\n", cur);
                cur = A[i];
                j++;
            }
        }

    }
}


