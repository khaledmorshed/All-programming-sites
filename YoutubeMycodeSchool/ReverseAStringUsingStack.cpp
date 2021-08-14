//#include<bits/stdc++.h>
#include<iostream>
#include<string.h>
#include<stack>


using namespace std;

void Revers(char *c, int n){

    stack<char> s;

    for(int i = 0; i < n; i++){

        s.push(c[i]);
    }
     for(int i = 0; i < n; i++){

        c[i] = s.top();
        s.pop();
    }
}

int main(){

    char c[50];

    cout<<"Enter a string : ";

    gets(c);
    int l = strlen(c);

    Revers(c,l);
    cout<<"Outputs : "<<c<<endl;

}
