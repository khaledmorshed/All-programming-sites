#include<bits/stdc++.h>
using namespace std;
int cnt[52], cnt2[52], cnt3=0;

int main(){

    string str1, str2;
    cin>>str1>>str2;
    //memset(cnt, -1, sizeof(cnt));
    if(str1.length() == str2.length()){
        for(int i=0;  i<str1.length(); i++){

            if(str1[i]>= 97 && str1[i]<=122){
                cnt[str1[i] - 'a']++;
            }
            else{
                cnt[str1[i]-65 + 26]++;
            }


            if(str2[i]>=97 && str2[i]<=122)
            cnt2[str2[i] -'a']++;
            else
            cnt2[str2[i]-65 + 26]++;
        }

    }
    else cnt3 = 1;

    for(int i=0, j=0; i<52; i++, j++){
        if(cnt[i] == 0 && cnt2[j]==0) continue;
        else if(cnt[i] == cnt2[j]){
        }
        else{
            cnt3 = 1;
            break;
        }
    }

    if(cnt3 == 1) cout<<"Not anagram"<<endl;
    else cout<<"anagram"<<endl;
    cout<<endl<<endl;

}
/*
abcDE
DEabc
*/

