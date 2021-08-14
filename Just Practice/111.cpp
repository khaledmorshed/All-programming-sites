
#include<bits/stdc++.h>
using namespace std;

long long int a, b, c, d, e, f;

long long int fn(long long int n) {
    if (n == 0) return 1;
    else if (n == 1) return 2;
    else if (n == 2) return 3;
    else if (n == 3) return 4;
    else if (n == 4) return 5;
    else if (n == 5) return 6;
    return fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6);
}

int main() {
    long long int n, cases,returnvalue;
    scanf("%d", &cases);
    int caseno = 1;
   /* for (int caseno = 1; caseno <= cases; caseno++) {
        //scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        cin>>a>>b>>c>>d>>e>>f>>n;
        printf("Case %d: %d\n", caseno++, fn(n) % 10000007);
    }*/

    while(cases){

        cin>>/*a>>b>>c>>d>>e>>f>>*/n;
        returnvalue = fn(n);
        cout<<"returnvalue "<<returnvalue<<endl;
        //printf("Case %d: %d\n", caseno++, returnvalue /*% 10000007*/);
        cases--;
    }

    return 0;
}
