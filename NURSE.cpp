#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1010;
const int mod= 1e9+7;
int n,l,r;
ll dp[N];

int main(){
    cin>>n>>l>>r;
    dp[0]=1; dp[1]=1;
    for (int i = 1; i <=n ; i++)
    {
        for(int j=l;j<=r;j++){
            if(i-j>=0) dp[i+1]+=dp[i-j];
        }
        dp[i]%=mod;
    }
    ll ans=dp[n]+dp[n+1];
    ans%=mod;
    cout<<ans<<endl;
}