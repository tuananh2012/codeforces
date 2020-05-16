#include <bits/stdc++.h>
using namespace std;
int n, u,v,w;
vector<pair<int,int> > adj[110];
int solve(int u,int v){
	priority_queue<pair<int,int> > p;
	p.push({0,u});
	vector<bool> check(110,1);
	while(p.size()&& check[v]){
		auto x = p.top();
		p.pop();
		int f = x.first, s = x.second;
		if(s == v) return f;
		if(check[s] == 0) continue;
		check[s]=0;
		for(auto k : adj[s] ){
			if(check[k.first]==1){
				p.push({f+k.second,k.first});
			    }
	        }
		}
	return 0;
}
int main(){
	cin>>n;
	for(int i=0; i < n-1;i++){
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	int ans=0;
	for(int i=1; i < n;i++){
		for(int j=i+1;j <= n;j++){
			ans=max(ans,solve(i,j));

		}
	}
	cout<<ans<<endl;
}