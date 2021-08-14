#include<bits/stdc++.h>

using namespace std;

void changeString(string &s){

    for(int i = 0; i < s.length(); i++){

        s[i] = s[i+1];
    }

}

int main(){

    string s;
    string temp;
    long long int rem;
    int div;
    long long int di;

    int T, j = 1;
    cin>>T;

    while(T>0){

         cin>>s>>div;

         if(s[0] =='-'){

            changeString(s);
         }

        temp = s[0];


        div =abs(div);

    //cout<<div<<endl;
    //temp = temp + s[1];

    rem = stod(temp);


    for(int i = 1; i <= s.length(); i++){


        while(rem >= div){

            rem = rem % div;
        }

        if(div > rem){

            temp = to_string(rem);
            temp = temp + s[i];

            rem = stod(temp);
        }

    }

    if(rem == 0){

        cout<<"Case "<<j++<<": "<<"Divisible"<<endl;

    }
    else{
        cout<<"Case "<<j++<<": "<<"Divisible"<<endl;
    }

    T--;

    }

   // cout<<rem<<endl;

}
