#include<bits/stdc++.h>
#define ll long long int
using namespace std;


ll B = 31, M = 100000009;
ll power[100005];
string text, pat;
ll previousValueOfText[100005];

//value calculation fo big string with every position
void generateValue(){
    previousValueOfText[0] = text[0];
    for(int i=1; i<text.size(); i++){
       previousValueOfText[i] = (previousValueOfText[i-1] * B + text[i]) % M;
    }

    power[0] = 1;
    for(int i=1; i<text.size(); i++){
      power[i] = (power[i-1] * B) % M;
    }

}

//value calculation fo pattern string(small string)
ll calculatePatHash(){
    ll h = 0;
    for(int i=0; i<pat.size(); i++){
        h = (h*B + pat[i]) % M;
        cout<<"h = "<<h<<endl;
    }
    return h;
}

ll getHashValue(int i, int j){
    ll ans = previousValueOfText[j];
    int sz = j-i+1;
    if(i){
       ans = (ans - previousValueOfText[i-1]*power[sz]) % M;
    }
    if(ans < 0){
      ans += M;
    }
    return ans;
}
int cnt;

void finder(){
    cnt = 0;
    ll patHashValue = calculatePatHash();
    int sz = pat.size();
    for(int i=0; i<text.size() - sz + 1; i++){
        if(patHashValue == getHashValue(i, i+sz-1)){
            cnt++;
            //return true;
        }
    }
    //return false;
}

int main(){
    cin>>text>>pat;
    generateValue();

    finder();
    if(cnt == 0)
    cout<<"sting not matching"<<endl;
    else{
        cout<<"string got and "<<cnt<<" times"<<endl;
    }
}
