
#include<bits/stdc++.h>
#define LIM 1000006
#define ll long long int
using namespace std;

void allFactorization(int n){

    bool check = false;
    for(int i=2; i<sqrt(n); i++){
        //if(check)cout<<" ";
        if(n%i == 0)cout<<i<<" x "<<n/i<<endl;
        check = true;
    }
}

int main(){
    int n;
    cin>>n;
    allFactorization(n);
}
