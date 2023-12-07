#include<bits/stdc++.h>
#define LIM 1e5
using namespace std;
//int cnt[LIM][26];
int cnt[10][26];
//ababcbbabaca
int main(){
    string str;
    cin>>str;

    cnt[0][str[0]-'a'] = 1;
    for(int i=1; i<str.size(); i++){
        int res = str[i] - 'a';
        for(int j=0; j<26; j++){
            cnt[i][j] = cnt[i-1][j];
        }
        cnt[i][res] = cnt[i-1][res] + 1;
    }

//	for(int i=0; i<str.size(); i++){
//		for(int j = 0; j<26; j++){
//			cout<<cnt[i][j]<<" ";
//		}
//		cout<<endl;
//	}

    int num1, num2;
    cin>>num1>>num2;
    num1 = min(num1, num2);
    num2 = max(num1,num2);

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
