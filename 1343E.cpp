#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a,b,c;
ll p[200010];int dis[3][200010];
vector<int> adj[200010];
void  bfs(){
    int ver;
    for(int u=0;u<3;u++){
        for(int i=1;i<=n;i++) dis[u][i]=0;
        if(u==0) ver=a; 
        else if(u==1) ver=b;
        else ver=c;
        vector<bool> vis(n+1,0);
        queue<int> q; q.push(ver); dis[u][ver]=0;
        while(q.size()){
            ver=q.front();
            q.pop();
            if(vis[ver]) continue;
            vis[ver]=1;
            for(auto v: adj[ver] ){
                if(!vis[v]) {
                    if(dis[u][v]==0)
                    dis[u][v]=dis[u][ver]+1;
                    else dis[u][v]=min(dis[u][v],dis[u][ver]+1);
                    q.push(v);
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);
    int t; cin>>t;
    while (t--)
    {
        cin>>n>>m>>a>>b>>c;
        for (int i = 0; i < m; i++)
        {
           
           cin>>p[i];
           adj[i+1].clear();
        }
        adj[n].clear();
        
        for (int i = 0; i < m; i++)
        {
            int u,v; cin>>u>>v;
            adj[u].push_back(v); adj[v].push_back(u);
        }
        if(a==b&&b==c) {
            cout<<0<<endl;
            continue;
        }
        bfs();

        ll ans=2e18;
        sort(p,p+m);
        for(int i=1;i<m;i++){
            p[i]+=p[i-1];
        }
        // cout<<dis[0][]<<endl;
        for(int i=1;i<=n;i++){
            int x1=dis[1][i];
            int x2=dis[0][i];
            int x3=dis[2][i];
            if(x1+x2+x3<=m){
                if(x1) ans=min(ans,(p[x1+x2+x3-1]+p[x1-1]));
                else ans=min(ans,p[x1+x2+x3-1]);
            }
        }
        cout<<ans<<endl;
    }
    
}