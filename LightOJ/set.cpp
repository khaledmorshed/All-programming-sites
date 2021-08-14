#include<bits/stdc++.h>

using namespace std;

int main(){

    //set<int> s;

    int arr[] = { 14, 12, 15, 11, 10 };

    set<int> s(arr, arr + 5);

    /*for(int i = 1; i <= 10; i++){

        s.insert(i);
    }*/

    for(auto it = s.begin(); it != s.end(); it++){

        cout<<*it<<endl;
    }
}
