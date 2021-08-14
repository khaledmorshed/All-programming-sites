#include<iostream>

using namespace std;

int main(){

    double d;
    float floating;

    int temp, n, ar[20], i=0, j, l, k, intiger;

    cin >> d;

    intiger = d;
    floating = d - intiger;
    int rest;

    while(intiger != 0){

        rest = intiger % 2;
        intiger /= 2;

        ar[i++] = rest;

    }

    for(j = i-1; j >= 0; j--){

        cout << ar[j];
    }

    cout<<'.';

    for(j = 1; j < 8; j++){

        floating = floating * 2;
        rest = floating;

        cout<<rest;

        if(floating > 1){


            floating = floating - 1;

        }

    }







}

