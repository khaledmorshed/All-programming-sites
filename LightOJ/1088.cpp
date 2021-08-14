#include<bits/stdc++.h>

using namespace std;


 int cas = 1;


 void print(vector<int> v2){

    cout<<"Case "<<cas++<<":"<<endl;

    for(int i = 0; i < v2.size(); i++){

        cout<<v2[i]<<endl;
    }


}



void TakeInput(int n, int p){

    vector<long long int> v;
    vector<int> v2;
    long long a, b, num;

    long long x, y, digits  = 0;


    for(int i = 0; i < n; i++){

        scanf("%lld", &num);
        v.push_back(num);
    }

    //cout<<"Case "<<cas++<<":"<<endl;

    for(int i = 0; i < p; i++){

        scanf("%lld %lld", &a, &b);

        auto low1 = lower_bound(v.begin(), v.end(), a);
        auto low2 = upper_bound(v.begin(), v.end(), b);
        x = low2 - v.begin();
        y = low1 - v.begin();

        digits = x - y;

        v2.push_back(digits);
    }

     print(v2);

}



int main(){

    int T, n, p;
    long long int a, b;

    scanf("%d", &T);

    while(T){

        scanf("%d %d", &n, &p);
        TakeInput(n, p);
        T--;
    }

}


