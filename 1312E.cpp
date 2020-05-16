#include<bits/stdc++.h>
using namespace std;
int n, a[505];
int dp[505][505];
int ans[505];
int main(){
    cin>>n; 
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        dp[i][i]=a[i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j+i <n ; j++)
        {
            for(int v=j;v<j+i;v++){
                if(dp[j][v]==dp[v+1][j+i]&&dp[j][v]!=0){
                    dp[j][i+j]=dp[j][v]+1;
                }
            }
        }
    }
    ans[0]=1;
    for (int i = 1; i < n; i++)
    {   if(dp[0][i]) ans[i]=1;
        else ans[i]= i+1;
        for (int j = 0; j<=i; j++)
        { 
            if(dp[j][i]){
                ans[i]= min(ans[i],ans[j-1]+1);
            }
        }
    }
    cout<<ans[n-1]<<endl;

}