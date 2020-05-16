#include<bits/stdc++.h>
using namespace std;
int n;
vector<pair<int,int> > adj[110];
int solve(int u,int v){
    vector<bool> vis(110,0);
    int dis[110];
    stack<int> s;
    s.push(u);
    vis[u]=1; dis[u]=0;
    while (!vis[v])
    { 
        int k = s.top();
        s.pop();
        if(!vis[k]) continue;
        for(auto x : adj[k]){
            int f = x.first;int sec = x.second;
            if(vis[f] == 0){
                vis[f]=1;
                dis[f]= dis[k] + sec;
                s.push(f);
            }
        }
    }
    return dis[v]; 
}
int main(){
    cin>>n;
	for(int i=0; i < n-1;i++){
        int u,v,w;
		cin>>u>>v>>w;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
    int ans = 0;
    for(int i =1 ;i <n;i++){
        for(int j = i+1;j<=n;j++){
            ans=max(ans, solve(i,j));
        }
    }
    cout<<ans<<endl;
}