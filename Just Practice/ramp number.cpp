#include<bits/stdc++.h>

using namespace std;

int main(){

    string s;
    cin>>s;
    string index ="";

    for(int i = 0; s[i] != '\0'; i++){

         index = s[i];
        int num=stod(index);
        printf("%d\n", num);
    }
}
