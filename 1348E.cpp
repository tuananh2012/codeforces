#include<bits/stdc++.h>
using namespace std;
bool dp[505][505];
int a[505],b[505];
int main(){
    long long sum=0;
    int n,k; cin>>n>>k;
    for (int i = 0; i < n;i++ )
    {
        cin>>a[i]>>b[i];
        sum+=(a[i]+b[i]);
    }
    dp[0][0]=true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            if(dp[i][j]){
                for(int v=0;v<=min(k-1,a[i]);v++){
                    if((a[i]-v+k)%k==0) dp[i+1][(j+v)%k]=1;
                    if(((a[i]-v)%k)+b[i]>=k) dp[i+1][(j+v)%k]=1;
                }
            }
        }
    }
    long long ans=0;
    for (int i = 0; i < k; i++)
    {
        if(dp[n][i]){
            ans=max(ans, (sum-i)/k);
        }
    }
    cout<<ans<<endl;
    
    
    
    
}