#include<bits/stdc++.h>
using namespace std;

int main(){
    int T, result;
    cin>>T;
    while(T--){
        long long int n, k;
        long c, value;
        cin>>n>>k;
        if(n>k){
            c = (n + k - 1)/k;
            value = c * k;
            result = (value + n -1) / n;
        }
        else if(n == 1){
            result = k;
        }
        else if(n == k){
            result = 1;
        }
        else{
            result = ( k + n - 1) / n;
        }
        cout<<result<<endl;
    }
}


/*

this is also valid code

#include<bits/stdc++.h>
using namespace std;

int main(){
    int T, result;
    cin>>T;
    while(T--){
        long long int n, k;
        long c, value;
        cin>>n>>k;
        c = (n + k - 1)/k;
        value = c * k;
        result = (value + n -1) / n;
        cout<<result<<endl;
    }
}


*/
