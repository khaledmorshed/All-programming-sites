#include<bits/stdc++.h>
#define ll long long int
#define pdd pair<ll,ll>
using namespace std;

ll B = 29, M = 1000000009+5;
ll B2 = 31, M2 = 1000000009+7;
//for forward hasing
ll prefix1 [100005], prefix2[100005];
ll pow1[100005], pow2[100005];
//for reverse hasing
ll suffix1[100005], suffix2[100005];
ll pow3[100005], pow4[100005];

int st, ed, ans = 1, cnt=0;
string s;
void hasingGenerate(){
	int sz = s.size();
	//forward hasing calculation
	//hasing 1
	prefix1[0] = s[0];
	for(int i=1; i<sz; i++) prefix1[i] = (prefix1[i-1] * B + s[i]) % M;
	pow1[0] = 1;
	for(int i=1; i<sz; i++) pow1[i] = (pow1[i-1] * B) % M;

	//hasing 2
	prefix2[0] = s[0];
	for(int i=1; i<sz; i++) prefix2[i] = (prefix2[i-1] * B2 + s[i]) % M2;
	pow2[0] = 1;
	for(int i=1; i<sz; i++) pow2[i] = (pow2[i-1] * B2) % M2;

	//reverse hasing
	//hasing 1
	suffix1[sz-1] = s[sz-1];
	for(int i=sz-2; i>=0; i--) suffix1[i] = (suffix1[i+1] * B + s[i]) % M;
	pow3[0] = 1;
	for(int i=1; i<sz; i++) pow3[i] = (pow3[i-1] * B) % M;

	//hasing 2
	suffix2[sz-1] = s[sz-1];
	for(int i=sz-2; i>=0; i--) suffix2[i] = (suffix2[i+1] * B2 + s[i]) % M2;
	pow4[0] = 1;
	for(int i=1; i<sz; i++) pow4[i] = (pow4[i-1] * B2) % M2;
}

pdd reverseHashValue(int i, int j){

	ll value1 = suffix1[i];
	int sz = j-i+1;
	if(j+1 < s.size()) value1 = (value1 - suffix1[j+1] * pow3[sz]) % M;
	if(value1 < 0) value1+=M;

	ll value2 = suffix2[i];
	if(j+1 < s.size()) value2 = (value2 - suffix2[j+1] * pow4[sz]) % M2;
	if(value2<0)  value2+=M2;
	//cout<<"ri = "<<i<<" rj = "<<j<<" rval1 = "<<value1<<" rval2 = "<<value2<<endl;
	return {value1, value2};
}

pdd forwardHashValue(int i, int j){

	ll value1 = prefix1[j];
	int sz = j-i+1;
	if(i) value1 = (value1 - prefix1[i-1] * pow1[sz]) % M;
	if(value1 < 0) value1+=M;

	ll value2 = prefix2[j];
	if(i) value2 = (value2 - prefix2[i-1] * pow2[sz]) % M2;
	if(value2<0)  value2+=M2;
	//cout<<"i  = "<<i<<" j  = "<<j<<" val1  = "<<value1<<" val2  = "<<value2<<endl;
	return {value1, value2};
}

//marufporoshalamsexymommadam

int  mostPalindrom(){

	for(int m=0; m<s.size(); m++){
		int lo = 0, hi = m;
		while(lo<hi){
			int i = (lo + hi) / 2;
			int x = m-i;
			int j = m+x;
			if(j>=s.size()) lo = i + 1;
			else if((forwardHashValue(i, j).first == reverseHashValue(i, j).first) && (forwardHashValue(i, j).second == reverseHashValue(i, j).second)){
				hi = i;
				int prevAns = ans;
				ans = max(ans, j-i+1);
				if(ans > prevAns){
					st = i;
					ed = j;
				}
			}
			else lo = i + 1;
		}
       //cout<<"m1 = "<<m<<endl;
		//abbc
		if(m+1 >= s.size() || s[m] != s[m+1]) continue;
		//cout<<"m2 = "<<m<<endl;
		//abbc
		int prevAns = ans;
		ans = max(ans, 2);
		if(ans > prevAns){
			st = m;
			ed = m+1;
		}
		lo = 0, hi = m;
		while(lo<hi){
			int i = (lo + hi) / 2;
			int x = m-i;
			int j = m+x+1;
			//cout<<"i = "<<i<<" x = "<<x<<" j = "<<j<<endl;
			if(j>=s.size()) lo = i + 1;
			else if((forwardHashValue(i, j).first == reverseHashValue(i, j).first) && (forwardHashValue(i, j).second == reverseHashValue(i, j).second)){
				hi = i;
				cout<<"i = "<<i<<" j = "<<j<<" m = "<<m<<endl;
				int prevAns = ans;
				ans = max(ans, j-i+1);
				if(ans > prevAns){
					st = i;
					ed = j;
				}
			}
			else lo = i + 1;
		}
	}
	return ans;
}


int main(){
	cin>>s;
	hasingGenerate();

	int ans = mostPalindrom();

	cout<<"most palindrome string = ";
	for(int i=st; i<= ed; i++){
		cout<<s[i];
	}
	cout<<" and length = "<<ans<<endl;
}
