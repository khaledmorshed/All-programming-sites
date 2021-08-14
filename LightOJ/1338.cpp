#include<bits/stdc++.h>

using namespace std;

int main(){


    int T, cas=1;

    cin>>T;

     cin.ignore();

    while(T){


    string s1;
    string s2;

    getline(cin, s1);
    getline(cin, s2);

   transform(s1.begin(), s1.end(), s1.begin(), ::tolower);
   transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    cout<<s1<<endl;

    int name = 0;

    for(int i = 0; i < s1.length(); i++){

        if(s1[i] == ' '){

            name++;
            continue;
        }

        for(int j = 0; j < s2.length(); j++){

            if(s1[i] == s2[j]){

                name++;
                s2[j] = '1';
                break;
            }
        }
    }

    //cout<<s2<<endl;

    //cout<<"name len : "<<name<<endl;
     //cout<<"s1 len : "<<s1.length()<<endl;

    if(name == s1.length()){

        cout<<"Case "<<cas++<<": yes"<<endl;
    }
    else{

        cout<<"Case "<<cas++<<": no"<<endl;

    }


        T--;
    }




}
