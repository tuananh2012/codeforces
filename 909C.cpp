#include<bits/stdc++.h>
using namespace std;
const int mod =1e9+7;
int dp[5005][5005],n;
string s;
int add(int a,int b){
    return (a+b)%mod;
}

int main(){
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        char c; cin>>c;
        s.push_back(c);
    }
    if(s[0]=='s') dp[0][0]=1;
    else dp[0][1]=1;
    for (int i = 1; i < n; i++)
    {
        if(s[i]=='s'){
            for (int  j = n; j >= 0; j--)
            {
                dp[i][j]= add(dp[i][j+1],dp[i-1][j]);
            } 
        }
        else{
            dp[i][0]=0;
            for (int j = 1; j < n; j++)
            {
                dp[i][j]=dp[i-1][j-1];
            }  
        }
    }
    cout<<dp[n-1][0]<<endl;
    
    


}