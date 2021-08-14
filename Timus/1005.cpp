#include<bits/stdc++.h>
using namespace std;

int main(){

    int n;
    long long int value, smalDiff, largdiff;

    cin>>n;
    set<int> v;

    for(int i = 0; i < n; i++){

        cin>>value;
        v.insert(value);
    }


    auto it2 = v.begin();
    it2++;
    auto it = v.begin();

     smalDiff = *it2 - *it;


    cout<<smalDiff<<endl;

}
