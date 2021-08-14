#include<iostream>
#include<stack>
#include<string.h>

using namespace std;

bool ArePair(char opening, char closing){

    if(opening == '(' && closing ==')') return true;
    else if(opening == '{' && closing == '}') return true;
    else if(opening == '[' && closing == ']') return true;

    else{
        return false;
    }

}

bool AreParenthecisBalance(string ex){

    stack<char> s;

    for(int i = 0; i < ex.length(); i++){


        if(ex[i] == '(' || ex[i] == '{' || ex[i] =='['){

            s.push(ex[i]);

           }
           else if(ex[i] == ')' || ex[i] == '}' || ex[i] == ']'){

                if(s.empty() || !ArePair(s.top(), ex[i])){

                    return false;
                }
                else{

                    s.pop();
                }
           }
    }

    return s.empty() ? true:false;
}

int main(){

    string expression;

    cin>>expression;

    if(AreParenthecisBalance(expression)){

        cout<<"Balanced expression"<<endl;
    }
    else{
        cout<<"Not balanced expression"<<endl;
    }
}
