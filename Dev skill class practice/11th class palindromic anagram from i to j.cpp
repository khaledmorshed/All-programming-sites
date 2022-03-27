#include<bits/stdc++.h>
using namespace std;
int cnt[12][26];

int main(){
    string str;
    //cout<<cnt[][]<<endl;
    cin>>str;
    int res;
    //cnt[-1][0] = 0;
    for(int i=0; i<12; i++){
        int cnt2 = 0;
        res = -1;
        for(int j=0; j<26; j++){
            if(cnt2 == 0){
                //here res is a integer value
                res = str[i]-'a';
                //if i = 0 then cnt[i-1][0] will get a wrong value
                if(i-1<0){
                    cnt[i][res] =1;
                }
                else
                cnt[i][res] = cnt[i-1][res] + 1;//present cnt[i][res] is assigned by previous value + 1
                cnt2 = 1;
                //continue;
            }
            //here if res == j become then it is setted previous in if condition and i == 0 becomes
            //then continue.
            if(res == j || i == 0) continue;
            cnt[i][j] = cnt[i-1][j];
        }
    }

    int num1, num2;
    cin>>num1>>num2;
    if(num1 > num2){
        num1 = num2;
        num2 = num1;
    }
    int cnt3 = 0;

    for(int j=0; j<26; j++){
        int result = cnt[num2][j] - cnt[num1-1][j];
            if(result == 0) continue;
            else if(result % 2 == 1){
                if(cnt3 == 1){
                    cnt3 = 2;
                    break;
            }
            else cnt3 = 1;
        }

    }
    if(cnt3 == 2) cout<<"not palindromic anagram"<<endl;
    else cout<<"palindromic anagram"<<endl;


}

//ababcbbabaca
