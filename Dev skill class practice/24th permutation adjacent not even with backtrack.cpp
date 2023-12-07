#include<bits/stdc++.h>
using namespace std;
int n, perm[20], taken[20];

void f(int in, int last){
    if(in == n){
        for(int i=0; i<n; i++){
            cout<<perm[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int p=0; p<n; p++){
        if(!taken[p]){
                //cout<<"p = "<<p<<endl;
            if(last == -1){
                //cout<<"p2 = "<<p<<endl;
                taken[p] = p;
                perm[in] = p;
                f(in+1, p);
                taken[p] = 0;
            }
            else if(last%2 && p%2==0){
                taken[p] = p;
                perm[in] = p;
                f(in+1, p);
                taken[p] = 0;
            }
            else if(last%2==0 && p%2){
                taken[p] = p;
                perm[in] = p;
                f(in+1, p);
                taken[p] = 0;
            }
            //else if(last)
        }
    }
}

int main(){
    cin>>n;
    f(0, -1);
}

