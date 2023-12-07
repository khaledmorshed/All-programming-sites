#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    //2 the power n will be got if n times left shift be done by 1.
    for(int v=0; v<(1<<n); v++){
        int mask = v;
        vector<int> bits;
        for(int t=0; t<n; t++){
            //cout<<mask%2<<" ";
            //mask % 2 == mask & 1
            bits.push_back(mask%2);
            //(mask/=2) == (mask>>=1)//right shift
            mask /= 2;
        }
        reverse(bits.begin(), bits.end());
        for(int i=0; i<bits.size(); i++){
            cout<<bits[i]<<" ";
        }
        cout<<endl;
    }
}

