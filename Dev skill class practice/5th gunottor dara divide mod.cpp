#include<bits/stdc++.h>
#define mod 1000000009+7

using namespace std;

int power(int x, int n){
    int temp;
    if(n == 0) return 1;
    else if(n % 2) return x * power(x, n -1);
    else{
        temp = power(x, n / 2);
        return temp * temp;
    }
    return 1;
}

int gunottor(int x, int n){
    if(n == 0) return 1;
    else if(n % 2) return (gunottor(x, n / 2) * (1 + power(x, n / 2 + 1))) /*% mod*/;// if needed then use mod
    else return (gunottor(x, n - 1) + power(x, n)) /*% mod*/;// if needed then use mod

}

int main(){
    int n, x;
    cin>>x>>n;
    cout<<"result = "<<gunottor(x,n)<<endl;
}
