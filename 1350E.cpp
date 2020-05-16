#include<bits/stdc++.h>
using namespace std;
int n,m,t;
vector<string> s;
int add[5]={-1,0,1,0,-1};
int dis[1001][1001];
bool vis[1010][1010];
queue<pair<int,int>>q;
bool valid(int u,int v){
    if(0<=u&&u<n&&0<=v&&v<m) return true;
    return false;
}
int main(){
    cin>>n>>m>>t;
    for (int i = 0; i < n; i++)
    {
        string x; cin>>x;
        s.push_back(x);
        for (int j = 0; j < m; j++)
        {
            dis[i][j]=1e9;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if(valid(i+add[k],j+add[k+1])){
                    if(s[i][j]==s[i+add[k]][j+add[k+1]]){
                        if(!vis[i][j]) q.push({i,j});
                        vis[i][j]=1;
                        dis[i][j]=0;
                    }
                }
            }
        }
    }
    while (q.size())    
    {
        int u=q.front().first, v=q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            if(valid(u+add[i],v+add[i+1])){
                dis[u+add[i]][v+add[i+1]]= min(dis[u][v]+1,dis[u+add[i]][v+add[i+1]]);
                if(!vis[u+add[i]][v+add[i+1]]){
                    q.push({u+add[i],v+add[i+1]});
                    vis[u+add[i]][v+add[i+1]]=1;
                }
            }
        }
        
    }
    while (t--)
    {  
        int i,j; long long p;
        cin>>i>>j>>p; i--;j--;
        if(dis[i][j]>=p|| dis[0][0]==1e9){
            cout<<s[i][j]<<endl;
        }
        else{
            p-=dis[i][j];
            if(p&1) cout<<('1'-s[i][j])<<endl;
            else cout<<s[i][j]<<endl;

        }
    }
    
    
    
    

}