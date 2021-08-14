#include<bits/stdc++.h>

using namespace std;

int main(){

    long long n;
    scanf("%lld", &n);

    double low = 0, hi = n, mid;

    for(int i = 0; i < 110; i++){

        mid = (low + hi) / 2;

        if(abs(mid*mid - n) < 1e-6){

            printf("%.10f\n", abs(mid*mid)-n);
            break;//10^-6
        }
        else if(mid*mid < n) low = mid;
        else hi = mid;
    }

    printf("%0.10f %0.10f\n", mid, mid*mid);
}
