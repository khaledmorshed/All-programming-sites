#include<bits/stdc++.h>
//not solved
using namespace std;

//()()))(()(()
int main(){
    string s;
    cin>>s;
    string result = "";
    int cnt = 0, cnt2 = 0;
    for(int i=0, j=s.size()-1; i<s.size();i++, j--){
        if(s[i] == '(') cnt++;
        else if(s[i] == ')') cnt--;
        if(s[j] == ')') cnt2++;
        else if(s[j] == '(') cnt2--;
        if(cnt2<0){
            s[j] = '*';
            cnt2 = 0;
        }
        if(cnt < 0){
            result = result + '(';
            cnt = 0;
        }
        if(s[i] != '*') result = result + s[i];
    }
    cout<<result<<endl;
}


