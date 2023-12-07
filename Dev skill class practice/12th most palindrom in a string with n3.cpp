#include<bits/stdc++.h>
using namespace std;

bool isPalindrom(string s, int st, int ed){
    for(int i=st, j = ed; i<ed; i++, j--){
        if(s[i] == s[j]){

        }else{
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    int startIndex = 0, endIndex = 0;
    int maxPadlindrom = 1;

    for(int i=0; i<s.size(); i++){
        for(int j=i, l=s.size()-1; l>j; l--){
            if(isPalindrom(s, i, l)){
                maxPadlindrom = max(maxPadlindrom, l-j+1);
                if(maxPadlindrom == l-j+1){
                    startIndex = j; endIndex = l;
                }
            }
        }
    }

    cout<<"maxPalindrom = "<<s.substr(startIndex, endIndex)<<" and len = "<<maxPadlindrom<<endl;

}
