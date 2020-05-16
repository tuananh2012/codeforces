#include<bits/stdc++.h>
using namespace std;
string s;
long long dp[1010][1010];
const long long mod=1e9+7;
int main(){
    cin>>s;
    int a[1010];
    int n=s.length();
    for(int i=0;i<s.length();i++){
        if(s[i]=='(') a[i]=1;
        if(s[i]==')') a[i]=-1;
        if(s[i]=='?') a[i]=0;
    }
    if(a[0]==-1){
        cout<<0;
        return 0;
    }
    if(a[0]==1) dp[1][0]=1;
    if(a[0]==0) {
        dp[0][0]=0; dp[1][0]=1;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<=n;j++){
            if(a[i]==1){
                if(j>0) dp[j][i]=dp[j-1][i-1];
                }
            else if(a[i]==0){
                dp[j][i]+=dp[j+1][i-1];
                if(j>0) dp[j][i]+=dp[j-1][i-1];
            }
            else dp[j][i]=dp[j+1][i-1];
            dp[j][i]%=mod;
        }
    }
    cout<<dp[0][n-1];

}