#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<string> v;
set<int> col, row;
bool vis[1001][1001];
bool test(){
    for (int i = 0; i < n; i++)
    {   int cnt=0;
        for(int j=0;j<m;j++){
            if(v[i][j]=='#') {
                row.erase(i);
                col.erase(j);
                cnt++;
            }
            if(v[i][j]=='#'&& v[i][max(j-1,0)]=='.' && cnt>1) {
                return 0; 
            }
        }
    }
    for (int i = 0; i < m; i++)
    {   int cnt=0;
        for (int j = 0; j < n; j++)
        { 
            if(v[j][i]=='#') cnt++;
            if(v[j][i]=='#'&& v[max(j-1,0)][i]=='.'&& cnt>1) {
                return 0; 
            }
            
        }
        
    } 
    return 1;
}
void dfs(int u,int x){
    if(vis[u][x]|| v[u][x]=='.') return;
    vis[u][x]=1;
    dfs(min(u+1,n-1),x);
    dfs(max(0,u-1),x);
    dfs(u,min(x+1,m-1));
    dfs(u,max(0,x-1));
}

int main(){
    cin>>n>>m;
    string t;
    for (int i = 0; i < m; i++)
    {
        t.push_back('.');
        col.insert(i);
    }
    bool check=0;
    
    for (int i = 0; i < n; i++)
    {   row.insert(i);
        string s; cin>>s;
        v.push_back(s);
        if(s!=t){
             check=1;
        }
    }
    if(check==0) {
        cout<<0; return 0;
    }
    if(test()==0) {
        cout<<-1; return 0;
    }
    int x=row.size()+col.size();
    int y=row.size()*col.size();
    if(y==0&&x>0) {
        cout<<-1; return 0;
    }
    int ans=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m;j++)
        {   if(vis[i][j]==0&& v[i][j]=='#'){
            dfs(i,j); ans++;
        }
        }  
    }
    cout<<ans;
    


    

}