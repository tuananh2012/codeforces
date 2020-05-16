#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll INF= 1e15;
ll a[100010], dp[100010][4];
string s; int n;
int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>s; 
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    dp[0][0]=0; dp[0][1]= INF; dp[0][2]=INF; dp[0][3]=INF;
    for (int i = 0; i < n; i++)
    {   
        for (int j = 0; j < 4; j++)
        {
            dp[i+1][j]=dp[i][j];
        }
        if(s[i]=='h'){  dp[i+1][0]+=a[i]; dp[i+1][1]=min(dp[i][1],dp[i][0]);}
        else if(s[i]=='a'){
            dp[i+1][1] +=a[i];
            dp[i+1][2]=min(dp[i][2],dp[i][1]);
        }
        else if(s[i]=='r') {dp[i+1][2]= dp[i][2]+a[i]; dp[i+1][3]=min(dp[i][3],dp[i][2]);}
        else if(s[i]=='d') {dp[i+1][3]=dp[i][3]+a[i];  }
    }
    ll  ans=INF;
    for (int i = 0; i < 4; i++)
    {
        ans=min(ans, dp[n][i]);
    }
    cout<<ans<<endl;
    
    
    

}