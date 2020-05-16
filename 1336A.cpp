#include<bits/stdc++.h>
using namespace std;
const int N=200010;
vector<int> adj[N];
int dep[N],size[N];
bool vis[N];
void dfs(int u,int par){
    vis[u]=1;
    for(int v: adj[u]){
        if(vis[v])continue;
        dep[v]=dep[u]+1;
        dfs(v,u);
        size[u]+=size[v]+1;
    }
}
int main(){
    int n,k; cin>>n>>k;
    for (int i = 0; i < n-1; i++)
    {   int u,v;
        cin>>u>>v; adj[u].push_back(v); adj[v].push_back(u);
    }
    dfs(1,0);
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        ans.push_back(size[i]-dep[i]);
    }
    int res=0;
    sort(ans.begin(),ans.end());
    for(int i=n-1;i>=k;i--){
        res+=ans[i];

    }
    cout<<res<<endl;
    

    
    
}