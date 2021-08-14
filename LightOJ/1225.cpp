#include<bits/stdc++.h>


using namespace std;

int main(){

    string s;
    int T;
    string rev;
    cin>>T;
    int i = 1;

    //rev = reverse(s);

    while(T>0){

        cin>>s;

        rev = s;

        reverse(rev.begin(), rev.end());

        if(s.compare(rev) == 0){

           cout<<"Case "<<i++<<": Yes"<<endl;
        }

        else if(s.compare(rev) != 0){

            cout<<"Case "<<i++<<": No"<<endl;
        }

        T--;
    }

}
