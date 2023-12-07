#include<bits/stdc++.h>
using namespace std;

string str;
int startIndex = 0, endIndex = 0;
int mostPalindromic(){
	int ans = 1;

	for(int m=0; m<str.size(); m++){
		for(int i=m-1, j=m+1; i>=0 && j<str.size(); i--, j++){
			if(str[i] == str[j]){
				ans = max(ans, j-i+1);
				if(ans == j-i+1){
					startIndex = i;
					endIndex = j;
				}
			}
			else break;
		}
		for(int i=m, j=m+1; i>=0 && j<str.size(); i--, j++){
			if(str[i] == str[j]){
				ans = max(ans, j-i+1);
				if(ans == j-i+1){
					startIndex = i;
					endIndex = j;
				}

			}
			else break;
		}
	}
	return ans;
}

int main(){
	cin>>str;
	int resu = mostPalindromic();
	cout<<"most palindrome string = ";
	for(int i=startIndex; i<= endIndex; i++){
		cout<<str[i];
	}
	cout<<" and length = "<<resu<<endl;
}
