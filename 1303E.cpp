#include<bits/stdc++.h>
using namespace std;
#define ll long long
int dp[404][404][404];
int main(){
    int t;
    cin>>t; 
    while (t--)
    {
        string s,t; cin>>s>>t;
        int n=s.length(),m=t.length();
        for (int i = 0; i < n+1; i++)
        {
            for (int j = 0; j < m+1; j++)
            {
                for (int l = 0; l < m+1; l++)
                {   if(i==0&& j==0) dp[i][j][l]=0;
                    else dp[i][j][l]=-1;
                }
            }
        }
        for (int i = 1; i <=n; i++) {
            for (int j = 0; j <=m ; j++)
            {
                for (int k = 0; k <= m; k++)
                {   
                    dp[i][j][k]=dp[i-1][j][k];
                    if(j&&s[i-1]== t[j-1]){
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j-1][k]);
                    }
                    if(k&&s[i-1]== t[k-1]){
                        if(dp[i-1][j][k-1]!=-1)
                        dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k-1]+1);
                    } 
                }
                
            } 
        }

        
        bool check =0;
        for (int i = 0; i < m+1; i++)
        {
                if(dp[n][i][m]==m-i){check =1; break;}   
        }
        if(check) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
        
        
    }
    
}    