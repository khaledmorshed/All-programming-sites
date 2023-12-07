#include <bits/stdc++.h>
#define value 1000000010
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
	    int n, mn = value, mx = -value;
	    cin>>n;
	    vector<int> v;
	    v.clear();
	    for(int i=0; i<n; i++){
			int num;
			cin>>num;
			v.push_back(num);
	    }

	    for(int i = 0;i<n;i++){
			if(i > 0 && v[i] == -1 && v[i - 1] != -1)
				mn = min(mn , v[i - 1]) , mx = max(mx , v[i - 1]);
			if(i < n - 1 && v[i] == - 1 && v[i + 1] != -1)
				mn = min(mn , v[i + 1]) , mx = max(mx , v[i + 1]);
		}

	    int result = (mn + mx) / 2;
	    int dif = 0;
	    for(int i=0; i<n; i++){
			if(v[i] == -1) v[i] = result;
			if(i){
				dif = max(dif, abs(v[i] - v[i-1]));
			}
 	    }
 	    cout<<dif<<" "<<result<<endl;
	}
	return 0;
}
