#include<bits/stdc++.h>
using namespace std;

int main(){
    
    string str1, str2;
    cin>>str1>>str2;
    int cnt = 0;
    
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    
    //cout<<str1<<endl<<str2<<endl;
    
    if(str1.length() == str2.length()){
        for(int i=0, j=0; i<str1.length(); i++,j++){
            if(str1[i] == str2[j]){
            
            }
            else {
                 cnt = 1;
                 break;
            }
             
        }
    }

        if(cnt == 0) cout<<"Anagram"<<endl;
        else cout<<"Not anagram"<<endl;

}