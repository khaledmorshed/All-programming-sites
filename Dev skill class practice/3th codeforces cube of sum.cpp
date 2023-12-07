#include<bits/stdc++.h>
#define ll long long int
#define n 10004
using namespace std;

bool findLook(ll look, vector<ll> &v){
	int lo = 0, hi = n;
	while(lo<=hi){
		int mid = (lo+hi)/2;
		if(v[mid] == look){
			return true;
		}
		else if(v[mid] > look){
			hi = mid - 1;
		}
		else{
			lo = mid+1;
		}
	}
	return false;
}

int main(){
	int T;
	cin>>T;
	vector<ll> v;
	for(ll i=1; i<n; i++){
		v.push_back(i*i*i);
	}
	while(T--){
		ll x;
		cin>>x;
		bool check = false;
		for(int i=0; i<v.size(); i++){
			ll look = x - v[i];
			if(findLook(look, v)){
				cout<<"YES"<<endl;
				check = true;
				break;
			}
		}
		if(check == false){
			cout<<"NO"<<endl;
		}
	}
}
