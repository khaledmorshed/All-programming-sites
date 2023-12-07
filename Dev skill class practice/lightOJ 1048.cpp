#include<bits/stdc++.h>

using namespace std;

int n, k, a[1003];

int numberOfJourney(int x){
	int cnt = 1, cur = 0;
	for(int i=0; i<n; i++){
		if(x < a[i]) return k+10000;
		if(cur+a[i] <= x){
			cur = cur+a[i];
		}
		else{
			cnt++;
			cur = a[i];
		}
	}
	return cnt;
}

int main(){
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++){
		scanf("%d %d", &n, &k);
		n++;k++;
		int sum = 0;
		for(int i=0; i<n; i++){
			scanf("%d", &a[i]);
			sum = sum + a[i];
		}

		int lo = 0, hi = sum;
		while(lo<hi){
			int x = (lo+hi) / 2;
			if(numberOfJourney(x) <= k) hi = x;
			else lo = x+1;
		}
		printf("Case %d: %d\n", t, hi);

	}
}
