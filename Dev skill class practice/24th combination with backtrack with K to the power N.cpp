#include<bits/stdc++.h>
using namespace std;
//n = house, k = color
//or 4 jon friend er moddhe 2 jon ke niye koto vabe invite kora jai, n = 4, k = 2
int n, k, comb[20];

void f(int in){
    if(in == n){
        for(int i=0; i<n; i++){
                if(i) cout<<" ";
            cout<<comb[i];
        }
        cout<<endl;
        return;
    }
    for(int c=0; c<k; c++){
        comb[in] = c;
        f(in+1);
    }
}

int main(){
    cin>>n>>k;
    //cout<<(1<<n)<<endl;
    f(0);
}
