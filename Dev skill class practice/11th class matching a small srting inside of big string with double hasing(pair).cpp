#include<bits/stdc++.h>
#define ll long long int
#define pdd pair<ll,ll>
using namespace std;


ll B = 31, M = 1000000009+7;//big prime number
ll power[100005];

ll B2 = 29, M2 = 1000000009+3;
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

    ///sencod
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
pdd calculatePatHash(){
    ll h = 0, h1 = 0;
    for(int i=0; i<pat.size(); i++){
        h = (h*B + pat[i]) % M;
    }

	//second
     for(int i=0; i<pat.size(); i++){
        h1 = (h1*B2 + pat[i]) % M2;
    }
    //cout<<"pat = "<<h<<endl;
    return {h, h1};
}

//get has value first time
pdd getHashValue(int i, int j){
    ll ans = prefixsSum[j];
    int sz = j-i+1;
    if(i){
       ans = (ans - prefixsSum[i-1]*power[sz]) % M;
    }
    if(ans < 0){
      ans += M;
    }

    //second
    ll ans2 = prefixsSum2[j];
    int sz2 = j-i+1;
    if(i){
       ans2 = (ans2 - prefixsSum2[i-1]*power2[sz2]) % M2;
    }
    if(ans2 < 0){
      ans2 += M2;
    }
    //cout<<"getvalue1 = "<<ans<<endl;
    return {ans,ans2};
}



int cnt;

void finder(){
    cnt = 0;
    pdd patHashValue = calculatePatHash();

    int sz = pat.size();
    for(int i=0; i<text.size() - sz + 1; i++){
        if(patHashValue.first == getHashValue(i, i+sz-1).first && patHashValue.second == getHashValue(i, i+sz-1).second){
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
    cout<<"sting not matching inside"<<endl;
    else{
        cout<<"string got and "<<cnt<<" times"<<endl;
    }
}
