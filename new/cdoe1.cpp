
#include<bits/stdc++.h>

using namespace std;

long long int somethingSquare(long long int a, int long long b){

    long long int temp;
    if(b==0) return 1;
    else if(b % 2) return  a * somethingSquare(a, b-1);

    else{
        temp = somethingSquare(a,b/2);
        return temp * temp;
    }

}

int main(){

    long long int a, b;
    cin>>a>>b;

    long long int store = somethingSquare(a,b);
    cout<<store<<endl;
}
