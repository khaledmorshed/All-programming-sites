#include<iostream>
#include<ios> //used to get stream size
#include<limits> //used to get numeric limits
using namespace std;

void change(string &s){

    for(int i = 0; s[i]!='\0'; i++){

        if(s[i] =='h'){
            s[i] = 'y';
        }
    }

}

main() {

   string str;

   getline(cin,str); //take a string

   change(str);

   cout << "You have entered:\n";

   cout << str << endl;
}
