#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[3010][3010];
const ll mod =998244353;
string s,t;
int main(){
    cin>>s>>t; int n=s.size(),m=t.size();
    for (int i = 1; i <=m; i++)
    {
        if(s[0]==t[m-i]) dp[1][i]=1;
    }
    for (int i = 1; i < n; i++)
    {   if(i==1)dp[i][0]=1;
        else dp[i][0]= (dp[i-1][0]<<1)%mod;
        for (int j = 1; j <= m; j++)
        {   if(i+1<=j){
            //tinh dp[i+1][j];
            if(s[i] == t[m-j]) dp[i+1][j]+=dp[i][j-1];
            if(s[i] == t[m-j+i]) dp[i+1][j]+=dp[i][j];
        }   
            if(i>=j){
                dp[i+1][j]=dp[i][j];
                if(s[i]==t[m-j]) dp[i+1][j]+=dp[i][j-1];
            }   
            dp[i+1][j]%=mod;   
        }
        
    }
    ll ans=0; 
    for (int i = m; i <=n; i++)
    {
        ans+=dp[i][m];
    }
    ans<<=1;
    ans%=mod;
    cout<<ans<<endl;
    
    
    
    
}