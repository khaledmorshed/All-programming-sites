#include<bits/stdc++.h>

using namespace std;


 int cas = 1;


 void print(vector<int> v2){

    cout<<"Case "<<cas++<<":"<<endl;

    for(int i = 0; i < v2.size(); i++){

        cout<<v2[i]<<endl;
    }


}

int numberOfdigits(long long a, long long b, int n, vector<long long int>v){

    long long x, y, digits  = 0;
    int flag=0;

    for(int i = 0; i < n; i++){

        if(v[n-1] == a){
            flag = n;
            break;
        }
        else if(v[i] == a || v[i] > a){
            break;
        }
        else{
            flag++;
        }
    }
    y = flag;
    flag = 0;

    for(int i = 0; i < n; i++){

        if(v[n-1] < b || v[n-1] == b){

            flag = n;
            break;
        }
        else if(v[i] == b){
            flag++;
            break;
        }
        else if(v[i] > b){

            break;
        }
        else{
            flag++;
        }
    }
    x = flag;
    digits = x - y;

   return digits;

}



void TakeInput(int n, int p){

    vector<long long int> v;
    vector<int> v2;
    long long a, b, num;

    for(int i = 0; i < n; i++){

        scanf("%lld", &num);
        v.push_back(num);
    }

    //cout<<"Case "<<cas++<<":"<<endl;

    for(int i = 0; i < p; i++){

        scanf("%lld %lld", &a, &b);
        int di = numberOfdigits(a, b, n, v);
        //cout<<di<<endl;
        v2.push_back(di);
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

