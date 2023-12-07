#include<bits/stdc++.h>
using namespace std;

int main(){

   int n = 10;
   int a[] = {10,20,30,40,50,50,50,60,70,80};
   //int a[] = {2,3,3,6};

   int x;
   scanf("%d", &x);

   int low = 0, hi = n;
    //int a[] = {10,20,30,30,50,50,50,60,70,80};//Lower_bound(40)
    //Lower_bound(60)
   while(low < hi){
        int mid = (low + hi) / 2;
        if(x <= a[mid]){
            hi = mid;
        }
        else low = mid + 1;
   }
   printf("Lower_bound, position and value= %d %d\n", hi, a[hi]);

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
   printf("Upper_boun, position and value= %d %d\n", hi, a[hi]);

}

