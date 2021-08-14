#include<bits/stdc++.h>

using namespace std;
#define n 10001
long long int A[n];

bool findLook(long long int value){


    long long int low = 0, hi = n;

    while(low <= hi){
        //printf("loop\n");
        long long int mid = (low + hi) / 2;

        if(A[mid] == value){

            return true;
        }
        if(value < A[mid]) hi = mid-1;
        else low = mid+1;
    }

    return false;
}

int main(){

    int T, check = 0;
    //scanf("%d", &T);
    cin>>T;
    long long int look = 0;
    long long int x;

    for(long long int i = 1, j = 0; i <= n; i++){

        A[j++] = i * i * i;
    }

   /*for(int i = 0; i < n; i++){

        cout<<A[i]<<endl;
    }
*/
    for(int t = 1; t <= T; t++){


        //scanf("%lld", &x);
        cin>>x;

        for(int i = 0; i < n; i++){

            look = x - A[i];

            if(findLook(look)){

                printf("YES\n");
                check = -1;
                break;
            }
            check = 0;


            //if(A[i] == x - look)
        }
        if(check == 0){
            printf("NO\n");
        }
    }


    return 0;
}
