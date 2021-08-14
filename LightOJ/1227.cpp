#include<bits/stdc++.h>

using namespace std;

int cas = 1;

void print(int eggNumber){

    cout<<"Case "<<cas++<<": "<<eggNumber<<endl;
 }


void CalculationEggNumber(int n,int p,int q, vector <int> &v){

    int sum = 0, i = 0, eggNumber = 0;
    int N;

    for(int k = 0; k < n; k++){

        cin>>N;
        v.push_back(N);
    }

    while(sum < q && eggNumber < p && eggNumber < n){

        sum = sum + v[i++];
        eggNumber++;

        if(sum > q){

            sum = sum - v[i];
            eggNumber--;
            break;
        }
    }

    print(eggNumber);


 }


int main(){

    int T;
    cin>>T;

    while(T){

        int n, p,q;
        cin>>n>>p>>q;
        int N;
        vector<int> v;

        CalculationEggNumber(n,p,q, v);
    	T--;
    }
}
