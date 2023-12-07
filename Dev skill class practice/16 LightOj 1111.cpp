#include<bits/stdc++.h>
#define LIM 10004
using namespace std;

int p[LIM], visit[LIM], cnt[LIM], result = 0;
vector<vector<int>> g;

void dfs(int u){
	visit[u] = 1;
	cnt[u]++;
	for(int i=0; i<g[u].size(); i++){
		int v = g[u][i];
		if(!visit[v]){
			//cnt[v]++;
			dfs(v);
		}
	}
}

int main(){
	int T, t = 1;
	cin>>T;
	while(T--){
		int k,n,m;
		cin>>k>>n>>m;
		memset(p, 0, sizeof p);
        memset(visit, 0, sizeof visit);
        memset(cnt, 0, sizeof cnt);
		for(int i=0; i<k; i++) cin>>p[i];

		g.clear();
		g.resize(n+1);

		for(int i=0; i<m; i++){
			int u, v;
			cin>>u>>v;
			g[u].push_back(v);
		}

		for(int u=0; u<k; u++){
			dfs(p[u]);
			memset(visit, 0, sizeof visit);
		}

		for(int i=1; i<=n; i++){
			if(cnt[i] == k) result++;
		}
		cout<<"Case "<<t++<<": "<<result<<endl;
		result = 0;
	}
}
