#include<bits/stdc++.h>
#define ll long long int
using namespace std;


ll B = 31, M = 100000009+7;//big prime number
ll power[100005];

ll B2 = 31, M2 = 100000009+7;
ll power2[100005];

string text, pat;
ll prefixsSum[100005];

ll prefixsSum2[100005];

//value calculation fo big string with every position
void generateValue(){
    prefixsSum[0] = text[0];
    for(int i=1; i<text.size(); i++){
       prefixsSum[i] = (prefixsSum[i-1] * B + text[i]) % M;
    }

    power[0] = 1;
    for(int i=1; i<text.size(); i++){
      power[i] = (power[i-1] * B) % M;
    }

}
//value calculation fo big string with every position again
void generateValue2(){
    prefixsSum2[0] = text[0];
    for(int i=1; i<text.size(); i++){
       prefixsSum2[i] = (prefixsSum2[i-1] * B2 + text[i]) % M2;
    }

    power2[0] = 1;
    for(int i=1; i<text.size(); i++){
      power2[i] = (power2[i-1] * B2) % M2;
    }

}

//value calculation fo pattern string(small string)
ll calculatePatHash(){
    ll h = 0;
    for(int i=0; i<pat.size(); i++){
        h = (h*B + pat[i]) % M;
    }
    cout<<"pat = "<<h<<endl;
    return h;
}

//get has value first time
ll getHashValue(int i, int j){
    ll ans = prefixsSum[j];
    int sz = j-i+1;
    if(i){
       ans = (ans - prefixsSum[i-1]*power[sz]) % M;
    }
    if(ans < 0){
      ans += M;
    }
    cout<<"getvalue1 = "<<ans<<endl;
    return ans;
}

//get has value 2nd time
ll getHashValue2(int i, int j){
    ll ans = prefixsSum2[j];
    int sz = j-i+1;
    if(i){
       ans = (ans - prefixsSum2[i-1]*power2[sz]) % M2;
    }
    if(ans < 0){
      ans += M2;
    }
    cout<<"getvalue2 = "<<ans<<endl;
    return ans;
}

int cnt;

void finder(){
    cnt = 0;
    ll patHashValue = calculatePatHash();
    int sz = pat.size();
    for(int i=0; i<text.size() - sz + 1; i++){
        if(patHashValue == getHashValue(i, i+sz-1) && patHashValue == getHashValue2(i, i+sz-1)){
            cnt++;
            //return true;
        }
    }
    //return false;
}

int main(){
    cin>>text>>pat;
    generateValue();
    generateValue2();

    finder();
    if(cnt == 0)
    cout<<"sting not matching inside"<<endl;
    else{
        cout<<"string got and "<<cnt<<" times"<<endl;
    }
}
