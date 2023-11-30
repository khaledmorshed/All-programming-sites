
#include<bits/stdc++.h>
using namespace std;

int n = 3;

bool f(int t, int f, vector<vector<int>> v){

    int cnt = 0, notUse = 0;
    //juust tes

    for(int i=0; i<26; i++){
        int value;
        if(v[i][t])
        if(t == 0){
            value = v[f][i] - 0;
        }else{
            value = v[f][i] - v[t-1][i];
        }
        if(value % 2 == 1){
        if(cnt > 1)
           cnt++;
        }
    }
    return cnt > 1 ? false : true;
}

int main(){
    string str = "ddmbbccd";
    int len = str.size();
    n = len;
    cout<<n<<endl;
    vector<vector<int>> v(n, vector<int>(26, 0));
    v[0][str[0]-'a'] = 1;

    for(int i=1; i<n; i++){
        v[i] = v[i-1];
        v[i][str[i]-'a'] = v[i-1][str[i]-'a']+1;
    }


    int num = 1;
    while(num){
        cin>>num;
        int i, j;
        cin>>i>>j;
        cout<<f(i, j, v)<<endl;
    }
}
