#include<bits/stdc++.h>
//Bookman Old Style/Calibri/Corbel/Goudy Old Style
using namespace std;

long long int somethingSquare(long long int a, int long long b){

    long long int temp, temp2;
    //cout<<"I am calculating F("<<a<<","<<b<<")"<<endl;
    if(b==0){

        cout<<"I am calculating 0 F("<<a<<","<<b<<")"<<endl;
        return 1;
    }
    else if(b % 2){

         cout<<"I am calculating Odd , F("<<a<<","<<b<<")"<<endl;
         temp2 = a * somethingSquare(a, b-1);
         cout<<"Odd  ! F("<<a<<","<<b<<") = "<<temp2<<endl;
         return temp2;
    }

    else{
        //cout<<"something"<<endl;
        cout<<"I am calculating Even, F("<<a<<","<<b<<")"<<endl;

        temp = somethingSquare(a,b/2);
        cout<<"Even ! F("<<a<<","<<b<<") = "<<temp*temp<<endl;
       // cout<<"something"<<endl;
        return temp * temp;
        //cout<<"nothing"<<endl;
        //cout<<"Done ! F("<<a<<","<<b<<")"<<temp<<endl;
    }

}

int main(){

    long long int a, b;
    cin>>a>>b;

    long long int store = somethingSquare(a,b);
    cout<<store<<endl;

}
