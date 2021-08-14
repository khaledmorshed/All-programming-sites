#include<iostream>
#include<string>
#include<vector>

using namespace std;

vector<string>holdvect;

void print(vector<string>v){

    int i;

    for(auto it = v.begin(); it != v.end(); it++){

        if(*it >= 0  && *it<=100000){

             cout<<*it<<endl;
        }
       //cout<<v[0]<<endl;
    }


}

int main(){

    string s;
    getline(cin,s);

    string word="";

    for(int i = 0; i < s.length(); i++){

        if(s[i] == ' '){

            if(s[i+1] == ' '){

                continue;
            }
            else{
            holdvect.push_back(word);
            word="";
            }


        }
        else{

            word.push_back(s[i]);
        }

    }
     holdvect.push_back(word);

     print(holdvect);
}
