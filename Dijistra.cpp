#include <bits/stdc++.h>
using namespace std;
typedef pair<long long,long long> pll;
long long n,m,u,v,w;
vector<pll > adj[100010];

int main(){
	cin>>n>>m;
	for (int i = 0; i < m; ++i)
	{
		/* code */
		cin>>u>>v>>w;
		adj[u].push_back(make_pair(v,w));
	}
	priority_queue<pll,vector<pll>, greater<pll> > p;
    cin>>u>>v;
    p.push({0ll,u});
    vector<bool> check(100010,0);
    long long ans;
    while(p.size()&&check[v]==0){
    	auto x = p.top();
    	p.pop();
    	long long f=x.first;
    	long long s=x.second;
    	if(s==v) {
    		cout<<f;
    		return 0;
    	}
    	if(check[s]==0){
    		check[s]=1;
    		for(auto k : adj[s]){
    			if(check[k.first]==0){
    				p.push({f+k.second,k.first});
    			}
    		}
    	}
    }
    if(check[v]==0) cout<<-1;
}