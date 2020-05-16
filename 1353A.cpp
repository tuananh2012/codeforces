#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF=  3e17;
ll a[101][101];
ll dis[101][101][2];

int main(){
    int t;
    cin>>t;
    while (t--)
    {   ll ans=3e17;
        int n,m;
        cin>>n>>m;
        bool vis[101][101];
        for (int i = 0; i < n; i++)
        {
            for (int k = 0; k < m; k++)
            {
                cin>>a[i][k];
            } 
        }
        int old=a[0][0];
        for (int l = 0; l < n; l++)
        {
            for (int g = 0; g < m; g++)
            {
                a[0][0]=a[l][g]-l-g;
                for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {   
                vis[i][j]=0;
                dis[i][j][0]= a[i+1][j]-(a[0][0]+i+j+1);
                if(dis[i][j][0]<0) dis[i][j][0]=INF;
                dis[i][j][1]=a[i][j+1]-(a[0][0]+i+j+1);
                if(dis[i][j][1]<0) dis[i][j][1]=INF;
             
            }
        }
    priority_queue<tuple<ll,int,int>,vector<tuple<ll,int,int>>, greater<tuple<ll,int,int>>> q;
    q.push({dis[0][0][0],1,0}); q.push({dis[0][0][1],0,1});
    int cnt=0;
    while (!vis[n][m]&& cnt<=2*n+2)
    {  cnt++;
       tuple<ll,int,int> x= q.top();
        q.pop();
        ll w=get<0> (x), u=get<1>(x) , v=get<2> (x);
        // cout<<u<<" "<<v<<" "<<w<<endl;
        vis[u][v]=1;
        if(u==n-1&&v==m-1) {
            ans=min(ans,w);
            break;
        }
        ll mn= w+dis[u][v][0];
        ll nm=w+dis[u][v][1];
        if(!vis[u+1][v]&& mn<3e17){
            q.push({mn,u+1,v});
        }
        if(!vis[u][v+1]&&nm<3e17){
            q.push({nm,u,v+1});
        }
    }
            }
            
        }
        cout<<ans<<endl;
        



    }
  
    



    
}