#include<bits/stdc++.h>

using namespace std;

int main(){

   int n = 10;
   int a[] = {10,20,30,40,50,50,50,60,70,80};

   int x;
   scanf("%d", &x);

   int low = 0, hi = n;

   while(low < hi){

        int mid = (low + hi) / 2;

        if(x <= a[mid]){
            hi = mid;
        }
        else low = mid + 1;

   }

   printf("Lower_bound and position = %d %d\n", hi, a[hi]);

   //upper  bound
    low = 0;
    hi = n;
   while(low < hi){

        int mid = (low + hi) / 2;

        if(x < a[mid]){
            hi = mid;
        }
        else low = mid + 1;

   }

   printf("Upper_bound an position = %d %d\n", hi, a[hi]);

}

