#include<bits/stdc++.h>

using namespace std;

//()()))(()()
int main(){
    string s;
    cin>>s;
    string result = "";
    int cnt = 0, ans = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i] == '(') cnt++;
        else if(s[i] == ')') cnt--;
        if(cnt < 0){
            result = result + '(';
            ans++;
            cnt = 0;
        }
        result = result + s[i];
    }
    cout<<ans+cnt<<endl;
    for(int i=0; i<cnt; i++){
        result = result + ')';
    }
    cout<<"balanced bracket = "<<result<<endl;
}

