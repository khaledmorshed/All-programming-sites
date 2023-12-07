#include<bits/stdc++.h>
using namespace std;
int cnt[26];
int main(){
    string str;
    cin>>str;
    int cnt2 = 0;

    for(int i=0; i<str.length(); i++){
        cnt[str[i] - 'a']++;
    }

    for(int i=0; i<26; i++){

        if(cnt[i] % 2 == 1){
            if(cnt2 == 1){
              cnt2 = 2;
              break;
            }
            else cnt2 = 1;
        }
    }

    if(cnt2 == 2) cout<<"Not palindromic anagram"<<endl;
    else cout<<"Palindromic anagram"<<endl;

}
