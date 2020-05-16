#include<bits/stdc++.h>
using namespace std;
const int N=300010;
#define ll long long
int n,m,k, a[N];
ll dp[N][11];
int dec(int x){
    if(x==0) return m-1;
    else return x-1;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m>>k;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];      
    }
    for (int i = 0; i < n+1; i++)
    {   
        dp[i][0]=0;
        for (int j = 1; j < m; j++)
        {
            dp[i][j]=-1e18;
        }   
    }
    ll ans=0;
    
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {   if(j!=1&& m>1)
            dp[i][j]= max(dp[i][j],dp[i-1][dec(j)]+a[i-1]);
            else{
                dp[i][j]=max(dp[i][j],dp[i-1][dec(j)]+a[i-1]-k);
            }
            
            ans=max(ans,dp[i][j]);
        }
        
    }
    cout<<ans<<endl;  
}