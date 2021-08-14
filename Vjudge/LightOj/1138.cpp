#include<bits/stdc++.h>

using namespace std;
int cas = 1;

void findNum(int x){

     int low = 0, hi = 1e15;
    int mid, check = 0, value;

    while(low < hi){

        int sum = 0;
        mid = (low + hi) / 2;

        for(int i = 1; i < 30; i++){

            int num = pow(5, i);
            sum = sum + mid / num;

        }
        if(sum == x){
            check = -1;
            value = mid;
        }
        if(sum < x) low = mid+1;
        else if(x <= sum) hi = mid;
    }

    if(check == -1){

         printf("Case %d: %d\n",cas++, value);
    }
    else{
        printf("Case %d: impossible\n",cas++);
    }

}

int main(){

    int T;
    cin>>T;

    while(T--){
        int sum = 0;
        int x;
        cin>>x;

       findNum(x);
    }

}
